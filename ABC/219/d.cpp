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

ll dp[305][305][305];

int main(){
    memset(dp, MOD, sizeof(dp));
    int n;
    int x,y;
    cin>>n;
    cin>>x>>y;
    dp[0][0][0]=0;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        rep(j,305){
            rep(z,305){
                if(dp[i][j][z] != MOD){
                    ll nj = j + a;
                    ll nz = z + b;
                    nj = min(nj, 300LL);
                    nz = min(nz, 300LL);
                    chmin(dp[i+1][j][z], dp[i][j][z]);
                    chmin(dp[i+1][nj][nz], dp[i][j][z] + 1);
                }
            }
        }
    }
    ll ans = MOD;
    rep(i,305){
        rep(j,305){
            if(i>=x && j>=y){
                chmin(ans, dp[n][i][j]);
            }
        }
    }
    if(ans==MOD){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

}
