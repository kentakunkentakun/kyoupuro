#include<bits/stdc++.h>
#include <atcoder/all>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<pll,vector<pll>,greater<pll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
    ll n,m,t;
    cin>>n>>m>>t;
    vll x(n);
    rep(i,n)cin>>x[i];
    vector<vector<pll>> table1(n,vector<pll> (0));
    vector<vector<pll>> table2(n,vector<pll>(0));
    rep(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        table1[a].pb(pll(c,b));
        table2[b].pb(pll(c,a));
    }
    PQR que;
    vll dist1(n,INF);
    dist1[0] = 0;
    que.pu(pll(0,0));
    while(sz(que)){
        pll w = que.top();que.pop();
        ll now = w.S;
        ll dis = w.F;
        if(dist1[now] < dis)continue;
        for(auto p :table1[now]){
            if(dist1[p.S] > dist1[now]+p.F){
                dist1[p.S] = dist1[now] + p.F;
                que.pu(pll(dist1[p.S], p.S));
            }
        }
    }
    vll dist2(n,INF);
    dist2[0] = 0;
    que.pu(pll(0,0));
    while(sz(que)){
        pll w = que.top();que.pop();
        ll now = w.S;
        ll dis = w.F;
        if(dist2[now] < dis) continue;
        for(auto p : table2[now]){
            if(dist2[p.S] > dist2[now] + p.F){
                dist2[p.S] = dist2[now] + p.F;
                que.pu(pll(dist2[p.S], p.S));
            }
        }
    }
    ll ans = 0;
    rep(i,n){
        if(dist1[i]+dist2[i] > t){
            continue;
        }
        chmax(ans, x[i] * (t-(dist1[i]+dist2[i])));
    }
    COUT(ans);

}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/