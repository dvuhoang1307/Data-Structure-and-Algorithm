//using Dijktra
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100000
const int vocuc = 1e9;
int V, E;
int s, t;

vector<pair<int,int>> adj[MAX];

void inp(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> s >> t;
}

void dijkstra(int s){
    vector<ll> dist(V + 1, vocuc);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> PQ;
    PQ.push({s, 0});
    while(!PQ.empty()){
        pair<int, int> top = PQ.top(); PQ.pop();
        int u = top.first;

        for(auto x : adj[u]){
            int v = x.first;
            int w = x.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                PQ.push({v, dist[v]});
            }
        }
    }
    cout << dist[t] << endl;
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    inp();
    dijkstra(s);
}
