class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // bfs
        queue<pair<pair<int,int>,int>> q;   // pair<pair<row,col>, time>>
        int vis[n][m];
        int cntFresh = 0 ; 
        // Inital node 
        for(int i = 0 ; i < n ; i++){
            for ( int j = 0 ; j < m ; j++ ){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }

        int tim = 0;  // result time
        int drow [] = {-1, 0 , 1, 0};
        int dcol [] = {0,1,0,-1};
        int cnt =0 ;
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tim = max(tim, t);
            q.pop();
            for(int k=0;k<4;k++) {
                int nr = r + drow[k];
                int nc = c+ dcol[k];

                if(nr>=0 && nc>=0 && nr < n  && nc < m && vis[nr][nc] ==0 && grid[nr][nc]==1  ) {
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) return -1;

        return tim;
    }
};