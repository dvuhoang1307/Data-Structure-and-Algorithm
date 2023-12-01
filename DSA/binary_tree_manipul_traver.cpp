#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int id;
    NODE* left;
    NODE* right;
};

typedef NODE* node;
set<int> se;

node MakeRoot(int u){   //check oke
    node root = new NODE();
    root->id = u;
    se.insert(u);
    root->left = nullptr;
    root->right = nullptr;
    return root;
}

node find_n(int v, node root){
    if(root == nullptr) return nullptr;
    if(root->id == v) return root;

    node l1 = find_n(v, root->left);
    node r1 = find_n(v, root->right);
    if(l1 == nullptr) return r1;
    else return l1;
}
void add_left(int u, int v, node &head){
    if(se.count(v) != 0 && se.count(u) == 0){
        node nv = find_n(v, head);
        if(nv->left != nullptr) return;

        node n_node = new NODE();
        n_node->id = u;
        n_node->left = nullptr;
        n_node->right = nullptr;

        se.insert(u);

        nv->left = n_node;
    }
}

void add_right(int u, int v, node &head){
    if(se.count(v) != 0 && se.count(u) == 0){
        node nv = find_n(v, head);
        if(nv->right != nullptr) return;

        node n_node = new NODE();
        n_node->id = u;
        n_node->left = nullptr;
        n_node->right = nullptr;

        se.insert(u);

        nv->right = n_node;
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
void inOrder(node head){
    if(head != nullptr){
        inOrder(head->left);
        cout << head->id << " ";
        inOrder(head->right);
    }
    return;
}
void postOrder(node head){
    if(head != nullptr){
        postOrder(head->left);
        postOrder(head->right);
        cout << head->id << " ";
    }
    return;
}

int main(){
//    node root = MakeRoot(1);
//    add_left(2, 1, root);
//    add_right(3, 1, root);
//    add_left(4,3, root);
//    add_right(5,2,root);
//    preOrder(root);

    node root;
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
        if(s == "*") break;
        else if (v[0] == "MakeRoot"){
            root = MakeRoot(stoi(v[1]));
        } else if (v[0] == "AddLeft"){
            add_left(stoi(v[1]), stoi(v[2]), root);
        } else if (v[0] == "AddRight"){
            add_right(stoi(v[1]), stoi(v[2]), root);
        }else if (v[0] == "PreOrder"){
            preOrder(root);cout << endl;
        } else if (v[0] == "InOrder"){
            inOrder(root); cout << endl;
        } else if (v[0] == "PostOrder"){
            postOrder(root); cout << endl;
        }
    }
    return 0;
}