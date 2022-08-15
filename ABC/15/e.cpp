#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
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
ll dp[55][10005][55];
int main(){
  ll n,w,k;
  cin>>w>>n>>k;
  vll a(n),b(n);
  rep(i,n)cin>>a[i]>>b[i];
  memset(dp,0,sizeof(dp));
  rep(i,n){
    rep(j,w+1){
      rep(z,n){
        dp[i+1][j][z]=max(dp[i+1][j][z],dp[i][j][z]);
        if(j+a[i]<=w){
          dp[i+1][j+a[i]][z+1]=max(dp[i+1][j+a[i]][z+1],dp[i][j][z]+b[i]);
        }
      }
    }
  }
  ll ans=0;
  rep(i,w+1){
    rep(z,n+1){
        cout<<dp[n][i][z]<<" ";
    }
    cout<<endl;
  }
  rep(i,k+1){
    ans=max(ans,dp[n][w][i]);
  }
  COUT(ans);
}
