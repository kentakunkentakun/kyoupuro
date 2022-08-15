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
int main(){
    ll n,a;
    cin>>n>>a;
    a--;
    string k;
    cin>>k;

    vll b(n);
    rep(i,n){
        cin>>b[i];
        b[i]--;
    }

    vll log(0);
    vll ch(n,false);
    ll now = a;
    ll finish;
    set<ll> hi;
    bool amari = true;
    while(1){
        if(ch[b[now]]){
            log.pb(b[now]);
            finish = now;
            if(hi.count(now)){
                amari = false;
            }
            break;
        }
        hi.insert(now);
        ch[b[now]] = true;
        log.pb(b[now]);
        now = b[now];
    }
    if (amari){
        ll amari_sum = 0;
        rep(i,sz(log)){
            amari_sum++;
            if(b[finish] == log[i]){
                break;
            }
        }
        if(sz(k)<=6){
            ll sum = 0;
            rep(i,sz(k)){
                sum = sum*10;
                sum+=k[i] - '0';
            }
            if(sum<=amari_sum){
                cout<<log[sum-1]+1<<endl;
                return 0;
            }
        }

        ll syuki = sz(log) - amari_sum;

        ll cu = 0;
        rep(i,sz(k)){
            cu = cu*10%syuki;
            cu += k[i] - '0';
            cu%= syuki;
        }
        cu = cu - (amari_sum)%syuki;
        if(cu<0)cu+=syuki;
        cout<<log[cu+amari_sum-1]+1<<endl;
        return 0;
    } else {
        
        log.pop_back();
        ll syuki = sz(log);
        ll cu = 0;
        rep(i,sz(k)){
            cu = cu*10%syuki;
            cu += k[i] - '0';
            cu%= syuki;
        }
        cu-=1;
        if(cu<0) cu+= syuki;
        cout<<log[cu]+1<<endl;
    }


}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/