#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll to_ll(string str) {
    ll num = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        num += (str[i] - '0') * pow(10, str.length() - 1 - i);
    }
    return num;
}

int main() {
    set<ll> s;

    string key;
    while (true) {
        getline(cin, key);
        if (key == "*") {
            break;
        }
        s.insert(to_ll(key));
    }

    // Read and process the actions
    string cmd;
    string v[11];
    while (true) {
        getline(cin, cmd);
        if (cmd == "***") {
            break;
        }

        stringstream ss(cmd);
        string tmp;
        int idx = 0;
        while(ss >> tmp){
            v[idx++] = tmp;
        }

        if (v[0] == "find") {
            if (s.count(to_ll(v[1])) > 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (v[0] == "insert") {
            if (s.count(to_ll(v[1])) == 0) {
                s.insert(to_ll(v[1]));
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
