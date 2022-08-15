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
    ll h,w;
    cin>>h>>w;
    vstr s(h);
    rep(i,h){
        cin>>s[i];
    }
    ll kuro = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#')kuro++;
        }
    }
    vvll ch(h,vll(w,-1));
    ch[0][0]=1;
    queue<pll> que;
    que.pu(pll(0,0));
    while(sz(que)){
        pll now = que.front();que.pop();
        rep(i,4){
            ll nx=now.F+dx[i];
            ll ny=now.S+dy[i];
            if(nx>=0&&nx<h&&ny>=0&&ny<w&&s[nx][ny]=='.'&&ch[nx][ny]==-1){
                ch[nx][ny]=ch[now.F][now.S]+1;
                que.pu(pll(nx,ny));
            }
        }
    }
    if(ch[h-1][w-1]==-1){
        cout<<-1<<endl;
    }else{
        cout<<h*w-kuro-ch[h-1][w-1]<<endl;
    }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/