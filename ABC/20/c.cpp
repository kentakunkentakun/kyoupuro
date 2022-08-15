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
#define PQR priority_queue<pll,vector<pll>,greater<pll>>
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
    ll h,w,t;
    cin>>h>>w>>t;
    vstr s(h);
    rep(i,h){
        cin>>s[i];
    }
    ll left =  0;
    ll right = t+1;
    ll gx=0;
    ll gy = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 'G'){
                gx = i;
                gy = j;
            }
        }
    }
    while(left+1<right){
        ll mid = (left+right)/2;
        vvll cost(h,vll(w));
        vvll dist(h,vll(w,INF));
        
        ll ss;
        rep(i,h){
            rep(j,w){
                
                if(s[i][j] != '#'){
                    if(s[i][j] == 'S'){
                        cost[i][j] =0;
                        ss = i*w+j;
                        dist[i][j] = 0;
                    }else{
                        cost[i][j] = 1;
                    }
                }
                else cost[i][j] = mid;
            }
        }
        
        PQR que;
        que.pu(pll(0,ss));
        while(sz(que)){
            pll now = que.top();
            que.pop();
            ll x,y;
            x = now.S/w;
            y = now.S%w;
            rep(i,4){
                ll nx = x+dx[i];
                ll ny = y+dy[i];
                if(0<=nx && nx<h && 0<=ny && ny<w){
                    if(dist[nx][ny] == INF){
                        dist[nx][ny] = dist[x][y] + cost[nx][ny];
                        que.pu(pll(dist[nx][ny], nx*w+ny));
                    }
                }
            }
        }
        if(dist[gx][gy]<=t){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout<<left<<endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/