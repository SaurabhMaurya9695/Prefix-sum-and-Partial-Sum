#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

// power function
ll power(ll x,ll y)
{
    ll res = 1;
    while(y)
    {
        if(y&1) 
            res = (res*x)%mod;
        y=y/2,x=(x*x)%mod;
    }
    return res%mod;
}
const int N = 1000001;
ll powerK[N];
ll arr[N];
ll prefixSum[N];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q,k;
    cin>>n>>q>>k;
    // precompute power function
    powerK[0] = 1;
    for(int i=1;i<=n;i++)
        powerK[i] = ( k*powerK[i-1] )%mod;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i] = ( arr[i]*powerK[i] )%mod;
        if(arr[i]<0)
            arr[i]+=mod;
    }
    prefixSum[0] = 0;
    for(int i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1]+ arr[i];
        if(prefixSum[i]>=mod)
            prefixSum[i]-=mod;
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ans = prefixSum[r]-prefixSum[l-1];
        if(ans<0)
            ans+=mod;
        ans = ans*power(powerK[l],mod-2)%mod;
        cout<<ans<<"\n";
    }
}