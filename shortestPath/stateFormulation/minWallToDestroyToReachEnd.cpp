/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> ii;
vector<vector<char>> arr;
vector<vector<int>> dis;
int n, m;
int delRow[] = {-1,0,1,0};
int delCol[] = {0, -1, 0, 1};

/* Input :-
5 6
. # # # # .
# # # # # .
# . . # . .
. . # # # #
. . # # . .
*/

void bfs(ii sc){
    dis[sc.F][sc.S] = 0;
    deque<ii> dq;
    dq.push_back(sc);
    while(!dq.empty()){
        ii front = dq.front();
        dq.pop_front();
        int i = front.F, j = front.S;
        for(int k = 0; k < 4; k++){
            int nr = i + delRow[k];
            int nc = j + delCol[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                int weigh = 0;
                if(arr[nr][nc] == '#'){
                    weigh = 1;
                }
                if(dis[nr][nc] > dis[i][j] + weigh){
                    dis[nr][nc] = dis[i][j] + weigh;
                    if(!weigh){
                        dq.push_front({nr, nc});
                    }else {
                        dq.push_back({nr, nc});
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    dis.assign(n, vector<int>(m, 1e9));
    arr.assign(n, vector<char>(m,'.'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char u;
            cin >> u;
            arr[i][j] = u; 
        }
    }
    
    bfs({0,0});
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dis[i][j] << '\t';
        }
        cout << '\n';
    }
    
    cout << dis[n - 1][m - 1] << '\n';
    return 0;
}
