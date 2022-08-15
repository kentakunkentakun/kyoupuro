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
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
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
struct edge {int to,cost;};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<edge>> G(n);
    map<pll,ll> path;
    rep(i,m){
        int v;
        edge e;
        cin>>v>>e.to>>e.cost;
        v--;e.to--;
        path[pll(v,e.to)] = i+1;
        path[pll(e.to,v)] = i+1;
        
        G[v].pb(e);
        int y=e.to;
        e.to=v;
        G[y].pb(e);
    }
    vll dist(n,INF);
    vll prev(n);
    dist[0] = 0;
    priority_queue<pll, vector<pll>,greater<pll>> que;
    que.pu(pll(0,0));
    while(!que.empty()){
        pll now = que.top();que.pop();
        int v = now.S;
        if(dist[v]<now.F) continue;
        for(auto e: G[v]){
            if(dist[e.to]>dist[v]+e.cost){
                dist[e.to] = dist[v] + e.cost;
                prev[e.to]=v;
                que.pu(pll(dist[e.to], e.to));
            }
        }
    }
    set<ll> ans;
    for(int i=1;i<n;i++){
        ans.insert(path[pll(prev[i],i)]);
    }
    for(auto a: ans){
        cout<<a<<" ";
    }
    cout<<endl;
}