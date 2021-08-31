/* Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1. */

#include <bits/stdc++.h>
using namespace std;

int getPathLength(vector<vector<int>>& dp, vector<vector<int>> mat, int i, int j){
    int n = dp.size();

    if(i < 0 || i >= n || j < 0 || j >= n)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int l = INT_MIN, t = INT_MIN, r = INT_MIN, b = INT_MIN;
    
    if(j > 0 && mat[i][j-1] == mat[i][j] + 1)
        l = 1 + getPathLength(dp, mat, i, j-1);
    
    if(i > 0 && mat[i-1][j] == mat[i][j] + 1)
        t = 1 + getPathLength(dp, mat, i-1, j);

    if(j < n-1 && mat[i][j+1] == mat[i][j] + 1)
        r = 1 + getPathLength(dp, mat, i, j+1);

    if(i < n-1 && mat[i+1][j] == mat[i][j] + 1)
        b = 1 + getPathLength(dp, mat, i+1, j);

    dp[i][j] = max(l, max(t, max(r, max(b, 1))));

    return dp[i][j];
}

int main(){
    int n, ans = 1;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(n, -1)), mat(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] == -1)
                getPathLength(dp, mat, i, j);

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}
