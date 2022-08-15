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
bool solve(ll a,ll s){
    vll aa(0),ss(0);
    ll aaa=a;
    ll sss=s;
    while(aaa>0){
        aa.pb(aaa%2);
        aaa/=2;
    }
    while(sss>0){
        ss.pb(sss%2);
        sss/=2;
    }
    while(sz(aa)<100){
        aa.pb(0);
    }
    while(sz(ss)<100){
        ss.pb(0);
    }
    ll mi=min(sz(aa),sz(ss));
    ll cu=0;
    rep(i,mi){
        ll now=cu;
        if(aa[i]==1){
            now+=2;
        }else{
            now+=abs(ss[i]-now);
        }
        if(now%2!=ss[i]){
            return false;
        }
        cu=now/2;
    }
    if(cu==1)return false;
    return true;
}
int main(){
    ll t;
    cin>>t;
    rep(i,t){
        ll a,s;
        cin>>a>>s;
        Yes(solve(a,s));
    }
}