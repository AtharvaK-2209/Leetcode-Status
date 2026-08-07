#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitExp[10][4]; // exponents of {2,3,5,7} contributed by digit 1..9
    int dim[4];
    vector<int> minLen;

    int encode(array<int,4> s){
        int code = 0;
        for (int i = 0; i < 4; i++) code = code * dim[i] + s[i];
        return code;
    }

    array<int,4> reduceState(array<int,4> s, int d){
        array<int,4> r = s;
        for (int i = 0; i < 4; i++) r[i] = max(0, s[i] - digitExp[d][i]);
        return r;
    }

    void buildDigitExp(){
        int table[10][4] = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
            {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
        };
        memcpy(digitExp, table, sizeof(table));
    }

    array<int,4> factor(long long t, bool &possible){
        array<int,4> req{0,0,0,0};
        int primes[4] = {2,3,5,7};
        for (int i = 0; i < 4; i++)
            while (t % primes[i] == 0) { req[i]++; t /= primes[i]; }
        possible = (t == 1);
        return req;
    }

    void precomputeMinLen(array<int,4> cap){
        for (int i = 0; i < 4; i++) dim[i] = cap[i] + 1;
        int total = dim[0]*dim[1]*dim[2]*dim[3];
        minLen.assign(total, INT_MAX);

        vector<array<int,4>> states;
        for (int a = 0; a < dim[0]; a++)
         for (int b = 0; b < dim[1]; b++)
          for (int c = 0; c < dim[2]; c++)
           for (int d = 0; d < dim[3]; d++)
            states.push_back({a,b,c,d});

        sort(states.begin(), states.end(), [](const array<int,4>&x, const array<int,4>&y){
            return (x[0]+x[1]+x[2]+x[3]) < (y[0]+y[1]+y[2]+y[3]);
        });

        array<int,4> zero{0,0,0,0};
        minLen[encode(zero)] = 0;

        for (auto &s : states){
            if (s == zero) continue;
            int best = INT_MAX;
            for (int d = 1; d <= 9; d++){
                array<int,4> r = reduceState(s, d);
                if (r == s) continue;              // no progress
                int rc = encode(r);
                if (minLen[rc] != INT_MAX) best = min(best, 1 + minLen[rc]);
            }
            minLen[encode(s)] = best;
        }
    }

    string greedyFill(array<int,4> state, int L){
        string res; res.reserve(L);
        for (int pos = 0; pos < L; pos++){
            int remaining = L - pos - 1;
            for (int d = 1; d <= 9; d++){
                array<int,4> r = reduceState(state, d);
                if (minLen[encode(r)] <= remaining){
                    res.push_back('0' + d);
                    state = r;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        buildDigitExp();
        bool possible;
        array<int,4> req = factor(t, possible);
        if (!possible) return "-1";          // t has a prime factor > 7
        precomputeMinLen(req);

        int n = num.size();
        int maxTight = n;
        for (int i = 0; i < n; i++) if (num[i] == '0') { maxTight = i; break; }

        vector<array<int,4>> prefixState(maxTight + 1);
        prefixState[0] = req;
        for (int i = 0; i < maxTight; i++)
            prefixState[i+1] = reduceState(prefixState[i], num[i]-'0');

        // exact match check (only meaningful if num itself is zero-free)
        if (maxTight == n) {
            array<int,4> zero{0,0,0,0};
            if (prefixState[n] == zero) return num;
        }

        int top = (maxTight < n) ? maxTight : (n - 1);
        for (int i = top; i >= 0; i--){
            int orig = num[i] - '0';
            for (int d = orig + 1; d <= 9; d++){
                array<int,4> s2 = reduceState(prefixState[i], d);
                int remaining = n - 1 - i;
                if (minLen[encode(s2)] <= remaining){
                    string res = num.substr(0, i);
                    res.push_back('0' + d);
                    res += greedyFill(s2, remaining);
                    return res;
                }
            }
        }
        int L = max(n + 1, minLen[encode(req)]);
        return greedyFill(req, L);
    }
};