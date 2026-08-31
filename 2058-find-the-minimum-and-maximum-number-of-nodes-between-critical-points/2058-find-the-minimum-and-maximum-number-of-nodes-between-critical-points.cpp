/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        ListNode* prev = head;
        ListNode* curr = head-> next;

        int idx = 1;
        // finding local maxima and local minima
        while(curr != nullptr && curr->next != nullptr) {
            if((curr->val > prev->val && curr->val > curr->next->val ) || 
                (curr->val < prev->val && curr->val < curr->next->val)){
                    pos.push_back(idx);
            }
            prev = curr;
            curr = curr-> next;
            idx++;
        }
        if(pos.size() < 2)
            return {-1,-1};

        int minDist = INT_MAX;
        for(int i = 1 ; i < pos.size(); i++){
            minDist = min(minDist, pos[i] - pos[i-1]);
        }
        int maxDist = pos.back() - pos.front();
        return {minDist, maxDist};
    }
};