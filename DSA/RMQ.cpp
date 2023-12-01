#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int lookup[MAX][MAX];
int n, m;
int arr[1000000];

int sum = 0;
void preprocess()
{
    for (int i = 0; i < n; i++)
        lookup[i][i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (arr[lookup[i][j - 1]] < arr[j])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = j;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;
    preprocess();
    for(int i = 1; i <= m; i++){
        int k, j;
        cin >> k >> j;
        sum += arr[lookup[k][j]];
    }
    cout << sum;
    return 0;
}