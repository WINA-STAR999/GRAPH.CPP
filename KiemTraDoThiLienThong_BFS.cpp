#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
vector <int> adj[1001];
bool visited[1001];
void inp(){
    cout<<"Nhap so luong dinh: ";cin>>n;
    cout<<"Nhap so luong canh: ";cin>>m;
    cout<<"Nhap danh sach canh: "<<endl;
    for (int i = 1; i <= m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);//Danh sach ke
    }
    memset(visited, false, sizeof(visited));
}

int bfs(int u){
    int cnt = 0;
    queue <int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cnt++;
        for (int x : adj[v]){
            if (visited[x] == false){
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return cnt;
}
int main(){
    inp();
    if (bfs(1) == n){
        cout<<"Do thi lien thong!";
    }
    else cout<<"Do thi khong lien thong!";
    return 0;
}