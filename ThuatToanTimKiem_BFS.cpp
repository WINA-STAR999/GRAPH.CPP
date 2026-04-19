#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

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

void bfs(int u){
    queue <int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for (int x : adj[v]){
            if (visited[x] == false){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main(){
    inp();
    bfs(1);
    return 0;
}
