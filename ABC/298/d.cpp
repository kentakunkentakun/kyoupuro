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
const ll MOD = 998244353LL;
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
    int q;
    cin>>q;
    ll cu = 1;
    queue<ll> que;
    que.pu(1);
    vll t(6*100000+5,1);
    for(ll i = 2; i < (ll)t.size(); i++) {
      t[i] = t[i-1]*10%MOD;
    }
    for (int i = 0; i < q; i++) {
      int a;
      cin>>a;
      
      if (a == 1) {
        int x;
        cin>>x;
        que.pu(x);
        cu*=10;
        cu%=MOD;
        cu+=x;
        cu%=MOD;
      } else if (a == 2) {
        int si = que.size();
        int fs = que.front();
        que.pop();
        int m = t[si] * fs %MOD;
        cu -= m;
        cu%=MOD;
        if (cu < 0){
          cu += MOD;
        }
      } else if (a == 3) {
        cout<<cu<<endl;
      }
    }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/