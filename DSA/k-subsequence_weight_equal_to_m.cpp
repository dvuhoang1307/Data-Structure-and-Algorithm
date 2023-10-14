#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int a[100000];

void inp(){
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    int ans = 0;
    int sum = 0;
    for(int i = 1; i<= k; i++){
        sum += a[i];
    }

    if(sum == m) ++ans;
    for(int j = k + 1; j <= n; j++){
        sum = sum + a[j] - a[j-k];
        if(sum == m) ++ans;
    }
    cout << ans << endl;
}

int main(){
    inp();
    solve();
}