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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vll dou(n,-1);
    rep(i,2){
        rep(j,2){
            dou[0] = i;
            dou[n-1] = j;
            for(int z = n-2;z>=1;z--){
                ll bd = dou[z+1];
                ll bbd;
                if(z+2 == n){
                    bbd = dou[0];
                }else{
                    bbd = dou[z+2];
                }
                if(bd == 0){
                    if(s[z+1] == 'o'){
                        dou[z] = bbd;
                    }else{
                        dou[z] = 1-bbd;
                    }
                }else{
                    if(s[z+1] == 'o'){
                        dou[z] = 1-bbd;
                    }else{
                        dou[z] = bbd;
                    }
                }
            }
            ll judgeb = dou[1];
            bool ok = false;
            if(dou[0] == 0){
                if(s[0] == 'o'){
                    if(dou[n-1] == judgeb){
                        ok = true;
                    }else{
                        ok = false;
                    }
                }else{
                    if(dou[n-1] == judgeb){
                        ok = false;
                    }else{
                        ok = true;
                    }
                }
            }else{
                if(s[0] == 'o'){
                    if(dou[n-1] == judgeb){
                        
                        ok = false;
                    }else{
                        ok = true;
                    }
                }else{
                    if(dou[n-1] == judgeb){
                        ok = true;
                    }else{
                        ok = false;
                    }
                }
            }
            bool ok2 = false;
            if(dou[1] == 0){
                if(s[1] == 'o'){
                    if(dou[2] == dou[0]){
                        ok2 = true;
                    }else{
                        ok2 = false;
                    }
                }else{
                    if(dou[2] == dou[0]){
                        ok2 = false;
                    }else{
                        ok2 = true;
                    }
                }
            }else{
                if(s[1]=='o'){
                    if(dou[2] == dou[0]){
                        ok2 = false;
                    }else{
                        ok2 = true;
                    }
                }else{
                    if(dou[2] == dou[0]){
                        ok2 = true;
                    }else{
                        ok2 = false;
                    }
                }
            }
            if(ok && ok2){
                rep(z,n){
                    if(dou[z])cout<<'W';
                    else cout<<'S';
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/