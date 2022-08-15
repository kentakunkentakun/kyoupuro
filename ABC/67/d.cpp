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
int main(){
    ll n;
    cin>>n;
    vvll t(n,vll(0));
    rep(i,n-1){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        t[a].pb(b);
        t[b].pb(a);
    }
    vll ch(n,false);
    ch[0]=true;
    queue<ll> que;
    que.pu(0);
    vll dist(n,INF);
    dist[0]=0;
    vll prev(n,INF);
    prev[0]=0;
    while(sz(que)){
        ll now = que.front();que.pop();
        for(auto p:t[now]){
            if(ch[p])continue;
            ch[p]=true;
            dist[p]=dist[now]+1;
            prev[p]=now;
            que.pu(p);
        }
    }
    vll keiro(0);
    ll cu;
    cu=n-1;
    keiro.push_back(n-1);
    while(1){
        cu=prev[cu];
        keiro.push_back(cu);
        if(cu==0)break;
    }
    ll f;
    ll s;
    reverse(all(keiro));
    if(sz(keiro)%2){
        f=keiro[sz(keiro)/2];
        s=keiro[sz(keiro)/2+1];
    }else{
        f=keiro[sz(keiro)/2-1];
        s=keiro[sz(keiro)/2];
    }
    vll check(n,false);
    check[f]=true;
    check[s]=true;
    que.pu(s);
    ll ans=1;
    while(sz(que)){
        ll now=que.front();
        que.pop();
        for(auto p:t[now]){
            if(check[p])continue;
            check[p]=true;
            que.pu(p);
            ans++;
        }
    }
    if(ans<n-ans){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/