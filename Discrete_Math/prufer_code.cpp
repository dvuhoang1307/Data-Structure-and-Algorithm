#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int E;

vector<vector<int>> dsk(MAX);
int bac[MAX];           //lưu bậc của các đỉnh
bool da_tham[MAX];      //đánh dấu các đỉnh đã thăm
int truoc[MAX];         //lưu đỉnh cha của đỉnh sắp xóa khỏi đồ thị

void dfs(int i){
    da_tham[i] = true;
    for(auto x : dsk[i]){
        if(!da_tham[x]){
            da_tham[x] = true;
            truoc[x] = i;
            dfs(x);
        }
    }
}

int V = -MAX;           //lưu số đỉnh của đồ thị
void make_graph(){
    cin >> E;
    memset(da_tham, false, size(da_tham));
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        V = max(x, max(V, y));
        dsk[x].push_back(y);
        dsk[y].push_back(x);
        ++bac[x]; ++bac[y];
    }
    dfs(0);
    ++V;
}

void prufer_code(){
    int ans[V-2];
    //Tìm node bậc 1 nhỏ nhất đầu tiên
    int now = MAX;
    for(int i = 1; i < V; i++){
        if(bac[i] == 1 && i < now){
            now = i;
        }
    }


    int idx = 0;
    while(E > 1){
        //cout << now << " ";
        int v = truoc[now];
        ans[idx++] = v;
        --bac[v];
        --E;
        if(bac[v] == 1 && v < now && v > 0){
            now = v;
        } else {
            ++now;
            while(now < V && bac[now] > 1 && now > 0){
                ++now;
            }
        }
    }

    for(int x : ans) cout << x << " ";
}

int main(){
    make_graph();
    prufer_code();
}
//input:
//9
//0 2
//0 3
//2 4
//2 6
//2 9
//6 1
//6 5
//9 7
//9 8

