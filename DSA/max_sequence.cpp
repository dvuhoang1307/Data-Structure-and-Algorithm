#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        res = max(res, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    cout << res << endl;
    return 0;
}