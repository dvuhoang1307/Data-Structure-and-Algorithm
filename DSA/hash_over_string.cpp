#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string a;

void solve(ll m){
    cin >> a;
    int k = a.length();
    string s = "x"+a;
    const ll M = m;

    vector<long long> p_pow(k);
    p_pow[0] = 1;
    for (int i = 1; i < k; i++) {
        p_pow[i] = (p_pow[i - 1] * 256) % M;
    }

    ll sum = 0;
    for(int i = 1; i <= k; i++){
        sum = sum % M + (97 + (s[i]-'a'))*p_pow[k-i] % M;
    }
    cout << sum % M << endl;
}

int main(){
    int n;
    ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        solve(m);
    }
}