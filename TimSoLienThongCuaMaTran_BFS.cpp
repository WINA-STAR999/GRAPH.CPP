/*
Vi du ma tran:
x x x o o o
o o x o o o
o x x x x o
o o o o o x
x x o x o x
x o x x o x
=>co 4 lien thong
*/
#include <bits/stdc++.h>

using namespace std;
char a[1001][1001];
bool visited[1001][1001];
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
void inp(){
    cout<<"Nhap do dai theo x cua ma tran: "; cin>>n;
    cout<<"Nhap do dai theo y cua ma tran: "; cin>>m;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
}
void bfs(int i, int j){
    queue <pair<int, int>> q;
    visited[i][j] = true;
    q.push({i, j});
    while (!q.empty()){
        pair <int, int> top;
        top = q.front(); 
        visited[top.first][top.second] = true;
        q.pop();
        for (int k = 0; k < 4; k++){
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if (i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n && !visited[i1][j1] && a[i1][j1] == 'x'){
                q.push({i1, j1});
            }
        }
    }
}
int main(){
    inp();
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(a[i][j] == 'x' && !visited[i][j]){
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout<<"So lien thong cua ma tran: "<<cnt;
    return 0;
}