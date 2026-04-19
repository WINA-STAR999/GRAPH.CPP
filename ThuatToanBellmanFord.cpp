#include <bits/stdc++.h>

using namespace std;
int n, m;
struct edge{
    int x, y, w;
};
vector <edge> edges;

void inp(){
    cout<<"Nhap so luong dinh: "; cin>>n;
    cout<<"Nhap so luong canh: "; cin>>m;
    for (int i = 1;  i <= m; i++){
        int x, y, w;
        cin>> x >> y >> w;
        edges.push_back({x, y, w});
        edges.push_back({y, x, w});
    }
}

void BellmanFord(int s){
    vector <int> d(n + 1, 1e9);
    d[s] = 0;
    for (int i = 1; i <= n - 1; i++){
        for (auto e : edges){
            int u = e.x, v = e.y, w = e.w;
            if (d[u] != 1e9 && d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout<<d[i]<<" ";
    }
}
int main(){
    inp();
    BellmanFord(1);
    return 0;
}