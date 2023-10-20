#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

struct edge{
    int u, v;
    int w;
};
int V, E;
vector<edge> canh;
int final_weight;
int parent[MAX];
int sz[MAX];

bool cmp(edge a, edge b){
    return a.w < b.w;
}
void input(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge e;
        e.u = a; e.v = b; e.w = c;
        canh.push_back(e);
    }
    sort(canh.begin(), canh.end(), cmp);
    //for(auto k : canh) cout << k.u << " " << k.v << " " << k.w << endl;
}

void dsu_make(){
    for(int i = 1; i <= V; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int dsu_find(int a){
    if(a == parent[a]) return parent[a];
    return parent[a] = dsu_find(parent[a]);
}

bool dsu_union(int a, int b){
    int x = dsu_find(a);
    int y = dsu_find(b);
    if(x == y) return false;
    if(sz[x] > sz[y]) swap(x, y);
    parent[x] = y;
    sz[y] += sz[x];
    return true;
}

int kruskal(){
    final_weight = 0;
    vector<edge> mst;
    for(int i = 0; i < canh.size(); i++){
        if(mst.size() == (V - 1)) break;
        edge e = canh[i];
        if(dsu_union(e.u, e.v)){
            mst.push_back(e);
            final_weight += e.w;
        }
    }
//    for(auto x : mst){
//        cout << x.u << " " << x.v << " " << x.w << endl;
//    }
}
int main(){
    input();
    dsu_make();
    kruskal();
    cout << final_weight << endl;
    return 0;
}