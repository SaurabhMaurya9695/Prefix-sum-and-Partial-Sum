// Given a 2d-array of dimension N*M and Q queries. In each query four integers x1, y1, x2, y2 is given,
//  you have to find the sum of submatrix with (x1,y1) be the leftmost corner and (x2,y2) be the
//  rightmost corner %10^9+7.

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,m,q;
    cin>>n>>m>>q;
    ll arr[n+1][m+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j]; // taking input in array
        }
    }
    for(int i=1 ; i <= n; i++){  // row wise prefix sum
        for(int j=2;j<=m;j++)
            arr[i][j] =  arr[i][j] + arr[i][j-1];
    }
    for(int i=1;i<=m;i++) // column wise prefix sum
        for(int j=2;j<=n;j++)
            arr[j][i]+=arr[j-1][i];
    while(q--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans = arr[x2][y2] - arr[x1-1][y2] /*col wise */- arr[x2][y1-1]  /*row wise */ + arr[x1-1][y1-1];
        ans%=mod;
        if(ans<0)
            ans+=mod;
        cout<<ans<<"\n";
    }
}