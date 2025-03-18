// Using 3d dist wala approach :-
using ii = pair<pair<int,int>,int>;
#define F first
#define S second
int delRow[] = {-1, 0, 1, 0};
int delCol[] = {0, 1, 0, -1};
class Solution {
public:
    int n, m, k;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dis; 
    void bfs(ii state){
        dis[state.F.F][state.F.S][state.S] = 0; 
        queue<ii> q;
        q.push(state);
        while(!q.empty()){
            ii front = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = front.F.F + delRow[i];
                int nc = front.F.S + delCol[i];
                int z = front.S;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(grid[nr][nc] == 1) z += 1;
                    if(z > k) continue;
                    if(dis[nr][nc][z] > dis[front.F.F][front.F.S][front.S] + 1){
                        dis[nr][nc][z] = dis[front.F.F][front.F.S][front.S] + 1;
                        q.push({{nr,nc},z});
                    }
                }
            }
        }
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        this->k = k;
        dis.assign(n, vector<vector<int>>(m, vector<int>(k + 1, 1e9)));
        ii state = {{0,0}, 0};
        bfs(state);
        int mini = 1e9;
        for(int i = 0; i <= k; i++){ 
            mini = min(mini, dis[n - 1][m - 1][i]);
        }

        if(mini == 1e9) return -1;
        return mini;
    }
};
