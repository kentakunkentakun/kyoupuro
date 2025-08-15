#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout << (x) << "\n"
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x, vector<x>, greater<x>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
int main()
{
    ll n;
    cin >> n;
    vector<pll> x(n);
    vector<pll> y(n);
    rep(i, n)
    {
        pll p;
        cin >> p.F >> p.S;
        x[i] = p;
    }
    rep(i, n)
    {
        pll p;
        cin >> p.F >> p.S;
        y[i] = p;
    }
    sort(all(y));

    ll ans = 0;
    rep(i, n)
    {
        ll mx = y[i].F;
        ll my = y[i].S;
        ll cnt = 0;
        ll j = -1;
        ll yy = -1;
        while (cnt < x.size())
        {
            if (x[cnt].F < mx && x[cnt].S < my)
            {
                if (chmax(yy, x[cnt].S))
                    j = cnt;
            }
            cnt++;
        }
        if (j != -1)
        {
            ans++;
            x.erase(x.begin() + j);
        }
    }
    cout << ans << endl;
    // ll n;
    // cin>>n;
    // map<pll,ll> ao;
    // map<pll,ll> aka;
    // map<pll,ll> all;
    // rep(i,n){
    //     pll p;
    //     cin>>p.F>>p.S;
    //     aka[p]=i;
    //     all[p]=0;
    // }
    // rep(i,n){
    //     pll p;
    //     cin>>p.F>>p.S;
    //     ao[p]=i;
    //     all[p]=1;
    // }
    // ll ans=0;
    // set<ll> akaa;
    // for(auto p:ao){
    //     pll pa=p.F;
    //     ll ma=-1;
    //     ll inde=-1;
    //     for(auto e:aka){
    //         if(pa.F>e.F.F && pa.S>e.F.S){
    //             if(ma<e.F.S && !akaa.count(e.S)){
    //                 ma=e.F.S;
    //                 inde = e.S;
    //             }
    //         }
    //     }
    //     if(inde!=-1){
    //         akaa.insert(inde);
    //         ans++;
    //     }
    // }
    // cout<<ans<<endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
