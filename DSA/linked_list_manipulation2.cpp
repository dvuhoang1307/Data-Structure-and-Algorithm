#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};

typedef struct Node* node;
int flag[10000] = {0};
node newNode(int x){
    node temp = new Node();
    temp->data = x;
    ++flag[x];
    temp->next = nullptr;
    return temp;
}
void addlast(node &head, int x){
    if(flag[x] != 0) return;
    if(head == nullptr) head = newNode(x);
    else {
        node temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode(x);
    }
}
void addfirst(node &head, int x){
    if(flag[x] == 0){
        node k = newNode(x);
        k->next = head;
        head = k;
    }
}
void addafter(node &head, int u, int v){
    node temp = head;
    if(flag[v] != 0 && flag[u] == 0){
        while(temp != nullptr){
            if(temp->data == v){
                node U = newNode(u);
                U->next = temp->next;
                temp->next = U;
            }
            temp = temp->next;
        }
    }
}
void addbefore(node &head, int u, int v){
    if(flag[u] == 0 && flag[v] != 0){
        node U = newNode(u);
        node temp = head;
        if(head->data == v){
            addfirst(head, u);
        }
        while(temp->next != nullptr){
            if(temp->next->data == v){
                node V = newNode(u);
                V->next = temp->next;
                temp->next = V;
                temp = V;
            }
            temp = temp->next;
        }
    }
}
void remove(node &head, int k){
    while(head->data == k){
        head = head->next;
    }
    node temp = head;
    node temp2 = head->next;
    while(temp2 != nullptr){
        if(temp2->data == k){
            temp->next = temp2->next;
            temp = temp->next;
            temp2 = temp2->next;
            continue;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    flag[k] = 0;
}
void reverse(node head){
    node temp = head;
    vector<int> v;
    while(temp != nullptr){
        v.push_back(temp->data);
        temp = temp->next;
    }
    for(int i = v.size()-1; i >= 0; i--){
        head->data = v[i];
        head = head->next;
    }
}
void in(node head){
    while(head->next != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}
int main(){
    node head = nullptr;
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cin.ignore();
        addlast(head, x);
    }
//    addlast(head,3);
//    addlast(head, 10);
//    addfirst(head, 1);
//    addafter(head, 10, 4);
//    remove(head, 1);
    string a[3];
    while(true){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        int id = 0;
        while(ss >> tmp){
            a[id++] = tmp;
        }
        if(s == "#"){
            break;
        } else if(s == "reverse"){
            reverse(head);
        } else if (s[2] == 'm'){
            remove(head, stoi(s.substr(7, s.length()-7)));
        } else if (s[3] == 'b'){
            addbefore(head, stoi(a[1]) , stoi(a[2]));
        } else if (s[3] == 'a'){
            addafter(head, stoi(a[1]) , stoi(a[2]));
        } else if (s[3] == 'f'){
            addfirst(head, stoi(s.substr(9, s.length()-9)));
        } else if (s[3] == 'l'){
            addlast(head, stoi(s.substr(8, s.length()-8)));
        }
    }
    in(head);
    return 0;
}