#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int V, E;
vector<int> dsk[MAX];
bool usedColor[MAX];
int result[MAX];
int quantity;
bool available[MAX];
vector<pair<int,int>> edges;

void inp() {
    ifstream fileinput;
    fileinput.open("dothi.txt", ios_base::in);
    if (fileinput.is_open()) {
        fileinput >> V >> E;
        for (int i = 1; i <= E; i++) {
            int x, y;
            fileinput >> x >> y;
            edges.push_back({x, y});
            dsk[x].push_back(y);
            dsk[y].push_back(x);
        }
        memset(result, 0, V);
        memset(available, false, V);
    }
}
void output(){
//    for(int i = 1; i <= V; ++i){
//        cout << "Dinh: " << i << " Mau: " << result[i] << endl;
//    }
//
//    cout << "available:\n";
//    for(int i = 1; i <= V; ++i){
//        cout << available[i] << " ";
//    }
//    cout << "Quantity: " << quantity << endl;
    //cout << quantity << endl;
//    random_device rd;
//    mt19937 gen(rd());
//    vector<string> colors_id;
//
//    for (int i = 0; i < quantity; i++) {
//        uniform_int_distribution<int> dis(0, 0xFFFFFF); // Phạm vi mã màu hexa từ 0x000000 đến 0xFFFFFF
//        int ma_mau = dis(gen);
//        stringstream hexa_color;
//        hexa_color << setfill('0') << setw(6) << hex << ma_mau;
//        colors_id.push_back("#" + hexa_color.str());
//    }
//    for(int i = 0; i < quantity; i++) cout << colors_id[i] << " ";

    vector<std::string> colors_id = {
            "red", "green", "yellow", "pink", "azure", "beige", "bisque",
            "orange", "blanchedalmond", "blue", "blueviolet", "brown", "burlywood", "cadetblue",
            "chartreuse", "chocolate", "coral", "cornflowerblue", "cornsilk", "crimson",
            "cyan", "darkblue", "darkcyan", "darkgoldenrod", "darkgray", "darkgreen", "darkkhaki",
            "darkmagenta", "darkolivegreen", "darkorange"
    };
    ofstream output_file("dothitomau.dot");
    if(output_file.is_open()){
        output_file << "graph dothi\n{\n";
        for(int i = 1; i <= V; ++i){
            output_file << " " << i << "[fillcolor=\"" << colors_id[result[i]-1] << "\", style=filled];\n";
        }

        for(auto a : edges){
            output_file << " " << a.first << " -- " << a.second << ";\n";
        }
        output_file << "}";
    }
}
void coloring(){
    for(int u = 1; u <= V; u++){
        memset(usedColor, false, V);
        for(int x : dsk[u]){
            if(result[x] != 0) usedColor[result[x]] = true;
        }

        int color = 0;
        while(result[u] == 0){
            color += 1;
            if(!usedColor[color]){
                if(!available[color]){
                    available[color] = true;
                    ++quantity;
                }
                result[u] = color;
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    inp();
    coloring();
    output();
    return 0;
}
