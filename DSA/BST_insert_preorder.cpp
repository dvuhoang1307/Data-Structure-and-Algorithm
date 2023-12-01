#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int id;
    NODE* left;
    NODE* right;
};

typedef NODE* node;
set<int> se;

void insert(int v, node &head){
    if(se.count(v) == 0){
        node n_node = new NODE();
        n_node->id = v;
        n_node->left = nullptr;
        n_node->right = nullptr;

        se.insert(v);
        node tmp = head;

        while(tmp != nullptr){
            if(v < tmp->id){
                if(tmp->left == nullptr) break;
                tmp = tmp->left;
            } else {
                if(tmp->right == nullptr) break;
                tmp = tmp->right;
            }
        }

        if(tmp == nullptr){
            head = n_node;
        } else if(v < tmp->id){
            tmp->left = n_node;
        } else {
            tmp->right = n_node;
        }
    }
}
void preOrder(node head){
    if(head != nullptr){
        cout << head->id << " ";
        preOrder(head->left);
        preOrder(head->right);
    }
    return;
}

int main(){
//    node root = MakeRoot(10);
//    insert_node(11, 10, root);
//    insert_node(1, 10, root);
//    insert_node(3, 10, root);
//    inOrder(root);

    node root = nullptr;
    string v[3];
    while(true){
        string s;
        getline(cin, s);

        stringstream ss(s);
        string tmp;
        int idx = 0;
        while(ss >> tmp){
            v[idx++] = tmp;
        }
        if (v[0] == "insert"){
            insert(stoi(v[1]), root);
        } else if (v[0] == "#"){
            preOrder(root);
            cout << endl;
            break;
        }
    }
    return 0;
}