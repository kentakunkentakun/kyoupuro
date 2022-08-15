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
    string s;
    cin>>s;
    ll x,y;
    cin>>x>>y;
    vll xx(0),yy(0);
    ll xy=0;
    ll cu=0;
    rep(i,sz(s)){
        if(s[i]=='F'){
            cu++;
        }else{
            if(xy%2){
                yy.pb(cu);
                cu=0;
                xy=0;
            }else{
                xx.pb(cu);
                cu=0;
                xy=1;
            }
        }
    }
    if(s[sz(s)-1]=='F'){
        if(xy%2){
            yy.pb(cu);
        }else{
            xx.pb(cu);
        }
    }
    vvll dp(2,vll(20000,INF));
    dp[0][10000] = 0;
    rep(i,sz(xx)){
        rep(j,20000){
            if(dp[i%2][j]==i){
                if(i==0){
                    dp[(i+1)%2][j+xx[i]]=i+1;
                }else{
                    dp[(i+1)%2][j+xx[i]]=i+1;
                    dp[(i+1)%2][j-xx[i]]=i+1;
                }
            }
        }
    }
    bool ok = true;
    if(dp[sz(xx)%2][x+10000]!=sz(xx)){
        ok = false;
    }
    vvll dp2(2,vll(20000,INF));
    dp2[0][10000] = 0;
    rep(i,sz(yy)){
        rep(j,20000){
            if(dp2[i%2][j]==i){
                dp2[(i+1)%2][j+yy[i]]=i+1;
                dp2[(i+1)%2][j-yy[i]]=i+1;
            }
        }
    }
    if(dp2[sz(yy)%2][y+10000]!=sz(yy)){
        ok = false;
    }
    Yes(ok);
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/