#include <bits/stdc++.h>
using namespace std;

void in(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int partition(int a[], int l, int r){
    int pivot = a[l];
    int i = l + 1;
    int j = r;
    while(true){
        while(a[i] < pivot) ++i;
        while(a[j] > pivot) --j;

        if(i < j){
            swap(a[i], a[j]);
            ++i; --j;
        } else break;
    }
    swap(a[l], a[j]);
    return j;
}
void quick_sort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quick_sort(a, l, p);
    quick_sort(a, p+1, r);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    //quick_sort(a, 0, n-1);
    in(a, n);
    return 0;
}