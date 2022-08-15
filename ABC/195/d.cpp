
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
ll n,m,q;
vll w,v;
vll x;
vector<pll> p(0);
ll solve(ll l, ll r){
    ll value=0;
    map<ll,ll> xx;
    rep(i,m){
        if(l-1<=i && i<=r-1){
            continue;
        }
        xx[x[i]]++;
    }
    
    rep(i,n){
        for(auto pa : xx){
            if(pa.S>0 && pa.F>=p[i].S){
                value+=p[i].F;
                xx[pa.F]--;
                break;
            }
        }
    }
    return value;
}

int main(){
    cin>>n>>m>>q;
    rep(i,n){
        int ww,vv;
        cin>>ww>>vv;
        w.pb(ww);
        v.pb(vv);
        p.pb(pll(vv,ww));
    }
    rep(i,m){
        ll xx;
        cin>>xx;
        x.pb(xx);
    }

    sort(rall(p));
    rep(i,q){
        ll l,r;
        cin>>l>>r;
        cout<<solve(l,r)<<endl;
    }
}