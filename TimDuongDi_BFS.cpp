#include <bits/stdc++.h>

using namespace std;

int n, m, s, t;
vector <int> adj[1001];
bool visited[1001];
int parent[1001];

void inp(){
    cout<<"Nhap so luong dinh: "; cin>>n;
    cout<<"Nhap so luong canh: ";cin>>m;
    cout<<"Nhap danh sach canh: "<<endl;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin>> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
}

void bfs(int u){
    visited[u] = true;
    queue <int> q;
    q.push(u);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int x : adj[v]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                parent[x] = v;
            }
        }
    }
}

void Path(){
    cout<<"Nhap dinh bat dau: "; cin>>s;
    cout<<"Nhap dinh ket thuc: "; cin>>t;
    bfs(s);
    if (!visited[t]){
        cout<<"Khong co duong di!\n";
    }
    else{
        vector <int> v;
        while (t != s){
            v.push_back(t);
            t = parent[t];
        }
        v.push_back(t);
        reverse(v.begin(), v.end());
        for (int x : v){
            cout<<x<<" ";
        }
    }
}
int main(){
    inp();
    Path();
    return 0;
}
