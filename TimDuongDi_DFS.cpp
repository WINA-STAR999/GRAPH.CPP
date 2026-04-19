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

void dfs(int u){
    visited[u] = true;
    for (int x : adj[u]){
        if (!visited[x]){
            parent[x] = u;
            dfs(x);
        }
    }
}

void Path(){
    cout<<"Nhap dinh bat dau: "; cin>>s;
    cout<<"Nhap dinh ket thuc: "; cin>>t;
    dfs(s);
    if (!visited[t]){
        cout<<"Khong co duong di!\n";
    }
    else{
        cout<<"Co duong di!\n";
        vector <int> path;
        while (t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path){
            cout<<x<<" ";
        }
    }
}
int main(){
    inp();
    Path();
    return 0;
}
