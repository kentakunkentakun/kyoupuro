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
typedef struct Point_Coordinates {
    double x, y;
} point;

// 線分ab, cdが交差する場合True
// 端点が他方の線分上にある場合もTrue
// 端点が他方の線分の延長線上にある場合もTrueを返すので注意
int Judge(point &a, point &b, point &c, point &d) {
    double s, t;
    s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
    t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
    if (s * t > 0)
        return false;

    s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
    t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
    if (s * t > 0)
        return false;
    return true;
}
int main(){
    ll ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    point a;
    a.x = ax;
    a.y=ay;
    point b;
    b.x=bx;
    b.y=by;
    ll n;
    cin>>n;
    ll ans=0;
    vll x(n),y(n);
    rep(i,n){
        cin>>x[i]>>y[i];
    }
    rep(i,n){
        point c,d;
        c.x=x[i];
        c.y=y[i];
        if(i+1==n){
            d.x=x[0];
            d.y=y[0];
        }else{
            d.x=x[i+1];
            d.y=y[i+1];
        }
        if(Judge(a,b,c,d)){
            ans++;
        }
    }

    cout<<ans/2+1<<endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/