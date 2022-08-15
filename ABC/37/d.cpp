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
ll h,w;
ll solve(ll i,ll j, vvll &t, vvll &a){
    if(t[i][j] !=INF){
        return t[i][j];
    }
    ll ans = 1;
    rep(z,4){
        ll nx = i+dx[z];
        ll ny = j+dy[z];
        if(i+dx[z] >= 0 && i+dx[z]<h && j+dy[z]>=0 && j+dy[z] <w){
            if(a[nx][ny]>a[i][j]){
                ans += solve(nx,ny,t,a);
                ans%=MOD;
            }
        }
    }
    return t[i][j] = ans;

}
int main(){
    cin>>h>>w;
    vvll a(h,vll(w));
    vvll t(h,vll(w,INF));
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
        }
    }
    ll ans = 0;
    rep(i,h)rep(j,w){
        ans+=solve(i,j,t,a);
        if(ans>=MOD) ans%=MOD;
    }

    COUT(ans);
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/