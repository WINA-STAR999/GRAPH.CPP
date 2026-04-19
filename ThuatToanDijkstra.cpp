#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 100001;
int n, m; //n: so luong dinh; m: so luong canh
vector <pair<int,int>> adj[maxn]; //Danh sach ke co luu trong so

void inp(){
    cout<<"Nhap so luong dinh: ";
    cin>>n; 
    cout<<"Nhap so luong canh: ";
    cin>>m;
    cout<<"Nhap danh sach canh co trong so: \n";
    for (int i = 1; i <= m; i++){
        int x, y, w;
        cin>> x >> y >> w;
        adj[x].push_back({y, w});//Dinh x ke voi dinh y va co trong so la w
    }
}

const int INF = 1e9;
void dijktra(int s){
    //Luu khoang cach duong di
    vector <ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair <ll, int>, vector <pair<ll, int>>, greater<pair<ll, int>>> pq;
    //{Khoang cach, dinh}

    pq.push({0, s});
    while (!pq.empty()){
        //Chon ra dinh co khoang cach ngan nhat tinh tu dinh s
        pair <int, int> top = pq.top(); pq.pop();
        int u = top.second;//Luu dinh
        int len = top.first;//Luu khoang canh
        if (len > d[u]) continue;
        //Relexation: Cap nhat khoang cach tu s cho toi moi dinh ke voi u
        for (auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
        }
    for(int i = 1; i <= n; i++){
        cout<<d[i]<<" ";
}
}
int main(){
    inp();
    dijktra(1);
    return 0;
}
