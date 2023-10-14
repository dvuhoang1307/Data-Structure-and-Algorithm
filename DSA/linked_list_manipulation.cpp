#include <bits/stdc++.h>
using namespace std;
set<int> s;
struct Node{
    int data;
    Node* next;
};

typedef struct Node* node;

node createNode(int value){
    node newnode = new Node();
    newnode->data = value;
    s.insert(value);
    newnode->next = nullptr;
    return newnode;
}
int size(node head){
    int ans = 0;
    while(head != nullptr){
        ++ans;
        head = head->next;
    }
    return ans;
}
void addnode1(node &head, node newnode){
    if(head == nullptr) head = newnode;
    else {
        node temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void in_ll(node head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}
void addlast(node &head,int val){
    if(s.count(val) == 0){
        addnode1(head, createNode(val));
    }
}
void addfirst(node &head, int val){
    if(s.count(val) != 0){
        node tmp = createNode(val);
        tmp->next = head;
        head = tmp;
    }
}
void addafter(node &head, int u, int v){
    if(s.count(u)==0 && s.count(v) != 0){
        node tmp = head;
        while(tmp != nullptr){
            if(tmp->data == v){
                node nodeU = createNode(u);
                nodeU->next = tmp->next;
                tmp->next = nodeU;
                tmp = nodeU->next;
            }
            tmp = tmp->next;
        }
    }
}
void addbefore(node &head, int u, int v){
    if(s.count(u)==0 && s.count(v) != 0){
        node tmp = head;
        if(head->data == v){
            node nodeU = createNode(u);
            nodeU->next = head;
            head = nodeU;
        }
        while(tmp->next != nullptr){
            node nodeU = createNode(u);
            if(tmp->next->data == v){
                nodeU->next = tmp->next;
                tmp->next = nodeU;

                tmp = nodeU;
            }
            tmp = tmp->next;
        }
    }
}
void remove(node &head, int del){
    while(head->data == del){
        head = head->next;
    }
    node tmp = head;
    node tmp2 = head->next;
    while(tmp2 != nullptr){
        if(tmp2->data == del){
            tmp->next = tmp2->next;
            tmp = tmp->next;
            tmp2 = tmp->next;
            continue;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
}
node dataNode(node head, int k){
    for(int i = 1; i < k; i++){
        head = head->next;
    }
    return head;
}
void reverse(node head){
    vector<int> a;
    node temp = head;
    while(temp != nullptr){
        a.push_back(temp->data);
        temp = temp->next;
    }
    for(int i = a.size()-1; i >= 0; i--){
        head->data = a[i];
        head = head->next;
    }
}
int main(){
    node head = nullptr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        addnode1(head, createNode(x));
    }
//    addlast (head,3);
//    addlast (head,10);
//    addfirst (head, 1);
//    addafter (head, 10, 4);
//    addbefore(head, 111, 5);
//    in_ll(head);
//    cout << endl;
//    remove (head, 1);
//    reverse(head);
//    in_ll(head);
    while(true){
        string s;
        cin.ignore();
        getline(cin, s);
        if(s == "#") break;
        stringstream ss(s);
        string a[3];
        int idx = 0;
        string temp;
        while(ss >> temp){
            a[idx++] = temp;
        }
        if(a[0] == "addlast"){
            addlast(head, stoi(a[1]));
        }
        else if(a[0] == "addfirst"){
            addfirst(head, stoi(a[1]));
        }
        else if(a[0] == "addafter"){
            addafter(head, stoi(a[1]), stoi(a[2]));
        }
        else if(a[0] == "addbefore"){
            addbefore(head, stoi(a[1]), stoi(a[2]));
        }
        else if(a[0] == "remove"){
            remove(head,stoi(a[1]));
        }
        else if(a[0] == "reverse"){
            reverse(head);
        }
//        a[0] = a[1] = a[2] = "0";
//        else if(s == "reverse"){reverse(head);}
//        else if(s.substr(0,6) == "remove"){
//            int x = stoi(s.substr(7, s.length()-7));
//            remove(head, x);
//        }
//        else if(s.substr(3,4) == "last"){
//            int x = stoi(s.substr(8, s.length()-8));
//            addlast(head, x);
//        }
//        else if(s.substr(3,5) == "first"){
//            int x = stoi(s.substr(9, s.length()-9));
//            addfirst(head, x);
//        }
//        else if(s.substr(3,5) == "after"){
//            stringstream
//        }
//        else if(s.substr(3,6) == "before"){
//
//        }
    }
    return 0;
}