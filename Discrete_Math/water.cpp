#include <bits/stdc++.h>
using namespace std;
#define iii tuple<int,int,int>
#define fi get<0>
#define se get<1>
#define th get<2>

bool visited[20][20][20];
bool ok;

void init(){
    memset(visited, size(visited), false);
    ok = false;
}
ofstream output_file("dfs_forest.dot");

bool dfs(int i, int j, int k){
    if(j == 2 || k == 2) return true;
    visited[i][j][k] = true;
    vector<iii> a;
    if(i != 0){ // Do i sang j va k
        if(i + j > 7) a.push_back(make_tuple(i - (7 - j),7,k));
        else a.push_back(make_tuple(0, i + j, k));

        if(i + k > 4) a.push_back(make_tuple(i - (4 - k),j,4));
        else a.push_back(make_tuple(0, j, i + k));
    }
    if(j != 0){ //Do j san i va k
        if(i + j > 10) a.push_back(make_tuple(10,j-(10-i),k));
        else a.push_back(make_tuple(i + j, 0, k));

        if(k + j > 4) a.push_back(make_tuple(i,j - (4 - k),4));
        else a.push_back(make_tuple(i, 0, j + k));
    }
    if(k != 0){ //Do j san i va k
        if(i + k > 10) a.push_back(make_tuple(10,j,k-(10-i)));
        else a.push_back(make_tuple(i+k, j, 0));

        if(k + j > 7) a.push_back(make_tuple(i , 7, k-(7-j)));
        else a.push_back(make_tuple(i, j+k, 0));
    }

    output_file << i << j << k << " [label=\"" << i <<", " << j << ", " << k << "\"];\n";
        for(auto x : a){
            if(!visited[fi(x)][se(x)][th(x)]){
                if(se(x) == 2 || th(x) == 2) output_file << fi(x) << se(x) << th(x) << " [label=\"" << fi(x) <<", " << se(x) << ", " << th(x) << "\", fillcolor=\"yellow\", style=\"filled\"];\n";
                else output_file << fi(x) << se(x) << th(x) << " [label=\"" << fi(x) <<", " << se(x) << ", " << th(x) << "\"];\n";
                output_file << i << j << k << "->" << fi(x) << se(x) << th(x) << ";" << endl;
                dfs(fi(x), se(x), th(x));
            }
        }
}

int main(){
    if(output_file.is_open()){
        output_file << "digraph DFS_Forest\n{\n";
        dfs(0,7,4);
        output_file << "}";
    }
}