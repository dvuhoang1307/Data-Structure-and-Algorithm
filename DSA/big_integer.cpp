#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    string b;
    cin >> a >> b;

    int m = a.length();
    int n = b.length();
    vector<int> ans;

    int i = m-1;
    int j = n-1;
    int miss = 0;
    while(i >= 0 && j >= 0){
        if(a[i] - '0' + (b[j]-'0') + miss >= 10){
            ans.push_back(a[i] - '0' + (b[j]-'0') + miss - 10);
            miss = 1;
            //cout << a[i] - '0' + (b[j]-'0') + miss - 10 << " " << miss << endl;
        } else {
            ans.push_back(a[i] - '0' + (b[j]-'0') + miss);
            miss = 0;
            //cout << a[i] - '0' + (b[j]-'0') + miss << " " << miss << endl;
        }
        --i; --j;
    }

    if(i+1 != 0){
        for(int x = i; x >= 0; --x){
            if(a[x]-'0' + miss >= 10){
                ans.push_back(a[x]-'0'+miss-10);
                miss = 1;
            } else {
                ans.push_back(a[x]-'0'+miss);
                miss = 0;
            }
        }
    } else if(j+1 != 0){
        for(int x = j; x >= 0; --x){
            if(b[x]-'0' + miss >= 10){
                ans.push_back(b[x]-'0'+miss-10);
                miss = 1;
            } else {
                ans.push_back(b[x]-'0'+miss);
                miss = 0;
            }
        }
    } else if(i == j){
        if(miss == 1) ans.push_back(1);
    }
    for(int k = ans.size()-1; k >= 0; --k){
        cout << ans[k];
    }
//    cout << endl;
//    cout << ans[0];
    return 0;
}