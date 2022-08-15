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
    ll n,c;
    cin>>n>>c;
    vvll d(c,vll(c));
    rep(i,c){
        rep(j,c){
            cin>>d[i][j];
        }
    }
    vvll t(n,vll(n));
    rep(i,n)rep(j,n)cin>>t[i][j];
    ll ans=INF;
    map<ll,ll> s0;
    map<ll,ll> s1;
    map<ll,ll> s2;
    rep(i,n){
        rep(j,n){
            if((i+j+2)%3==0){
                s0[t[i][j]]++;
            }else if((i+j+2)%3==1){
                s1[t[i][j]]++;
            }else{
                s2[t[i][j]]++;
            }
        }
    }
    vector<pll> c0(c);
    vector<pll> c1(c);
    vector<pll> c2(c);
    rep(i,c){
        c0[i]=pll(0,i);
        c1[i]=pll(0,i);
        c2[i]=pll(0,i);
    }
    for(auto p:s0){
        rep(i,c){
            c0[i]=pll(c0[i].F+d[p.F-1][i]*p.S,i);
        }
    }
    for(auto p:s1){
        rep(i,c){
            c1[i]=pll(c1[i].F+d[p.F-1][i]*p.S,i);
        }
    }
    for(auto p:s2){
        rep(i,c){
            c2[i]=pll(c2[i].F+d[p.F-1][i]*p.S,i);
        }
    }
    sort(all(c0));
    sort(all(c1));
    sort(all(c2));
    set<pll> ss;
    rep(i,3){
        ss.insert(c0[i]);
        ss.insert(c1[i]);
        ss.insert(c2[i]);
    }
    rep(i,3){
        rep(j,3){
            if(c0[i].S==c1[j].S)continue;
            rep(z,3){
                if(c0[i].S==c2[z].S || c1[j].S==c2[z].S)continue;
                chmin(ans,c0[i].F+c1[j].F+c2[z].F);
            }
        }
    }
    cout<<ans<<endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/