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
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x,vector<x>,greater<x>>
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
struct edge{
public:
    ll cost;
    ll to;
    ll num;
};
struct seni{
    public:
    ll now;
    ll distance;
    ll i;
    bool operator >(const seni &e1) const
    {
        return distance > e1.distance;
    };
};
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<edge>> t(n,vector<edge>(0));
    rep(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        edge e;
        e.to = b;
        e.cost = c;
        e.num = i;
        t[a].pb(e);
        e.to = a;
        t[b].pb(e);
    }
    set<ll> ans;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            vll dist(n,INF);
            dist[i] = 0;
            PQR(seni) que;
            vvll prev(0);
            seni e;
            e.distance = 0;
            e.now = i;
            e.i = INF;
            que.pu(e);
            while(sz(que)){
                ll now = que.top().now;
                ll dis = que.top().distance;
                ll miti = que.top().i;
                que.pop();
                if(dist[now]<dis) continue;
                if(miti != INF)  ans.insert(miti);
                
                for(auto p: t[now]){
                    if(p.cost+dist[now]<dist[p.to]){
                        dist[p.to] = p.cost+dist[now];
                        seni s;
                        s.i=p.num;
                        s.now = p.to;
                        s.distance = dist[p.to];
                        que.pu(s);
                    }
                }
            }

        }
    }
    ll res = 0;
    rep(i,m){
        if(!ans.count(i)){
            res++;
        }
    }
    cout<<res<<endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/