#include <bits/stdc++.h>
using namespace std;
long long C[10000] = {0};

//void in(long long a[], int n){
//    for(int i = 0; i <= n; i++) cout << a[i] << " ";
//    cout << endl;
//}
int C_k_n(int k, int n){
    const long long m = 1e9+7;
    C[0] = C[1] = 1;
    if(n >= 2){
        for(int i = 2; i <= n; i++){
            C[i] = 1;
            int x = C[0] % m;
            for(int j = 1; j < i; j++){
                int y = C[j] % m;
                C[j]  = C[j] % m + x;
                x = y;
            }
//            in(C, i);
        }
    }
    return C[k]%m;
}
int main(){
    int k, n;
    cin >> k >> n;
    cout << C_k_n(k, n) << endl;
    return 0;
}