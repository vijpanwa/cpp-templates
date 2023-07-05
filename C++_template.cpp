#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int long long
#define all(a) begin(a), end(a)
#define ppll pair<ll,pair<ll,ll>>
#define pll pair<ll,ll>
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define inf 1e18
#define imin INT_MIN
#define imax INT_MAX
#define pb push_back
#define pf push_front
#define vll vector<ll> 
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vpll vector<pair<long long, long long>>
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
int mod =1e9+7;
bool comp(pair<int,int> a,pair<int,int> b) {if(a.second == b.second) return a.first<b.first;return a.second<b.second;}
void display(vll a){for(auto& val: a) cout<<val<<' ';}
ll power(ll a, ll b){ll ans = 1;while(b){if(b&1)ans=(ans*a)%mod;a=(a*a)%mod;b >>= 1;}return ans;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    //t = 1;
    //cin>>t;
    while(t--)
    {   
        ll n; 
        cin>>n;
        vll a(n);
        rep(i,0,n-1) cin>>a[i];
    }
    return 0;
}


const ll N = 2 * 1e5 + 1;
ll F[N], inv[N];
void precompute(ll n)
{
    F[0] = 1;
    inv[0] = 1;
    rep(i, 1, n)
    {
        F[i] = (F[i - 1] * i) % mod;
        inv[i] = power(F[i], mod - 2);
    }
}

ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return (F[n] % mod * inv[n - r] % mod * inv[r] % mod) % mod;
}

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        rank[a] += rank[b];
        parent[b] = a;
    } 
}