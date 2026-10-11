#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
#define ll long long
#define ld long double
#define ul unsigned long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (ll)(b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0LL; i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout << (x) << "\n"
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T>
using PQ = priority_queue<T>;

template <class T>
using PQR = priority_queue<T, vector<T>, greater<T>>;

// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 62;
const double INF_D = numeric_limits<double>::infinity();

template <class T>
constexpr void printArray(const vector<T> &vec, char split = ' ')
{
  rep(i, vec.size())
  {
    cout << vec[i];
    cout << (i == (int)vec.size() - 1 ? '\n' : split);
  }
}
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct S_min {
  ll v,it;
};
S_min op_min(S_min a,S_min b){
  if(a.v<b.v){
    return a;
  }
  return b;
}
S_min e_min(){
  return {
    INF,-1
  };
}
struct S_max{
  ll v,it;
};
S_max op_max(S_max a,S_max b){
  if(a.v>b.v){
    return a;
  }
  return b;
}
S_max e_max(){
  return {
    -INF,-1
  };
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m;
  cin>>n>>m;
  vll p(n);
  rep(i,n)cin>>p[i];
  vector<S_min> ini_min(n);
  vector<S_max> ini_max(n);
  rep(i,n){
    ini_min[i] = {
      p[i],i
    };
    ini_max[i] = {
      p[i],i
    };
  }
  segtree<S_min,op_min,e_min> seg_min(ini_min);
  segtree<S_max,op_max,e_max> seg_max(ini_max);
  rep(i,m){
    ll l,r;
    cin>>l>>r;
    l--;
    auto mi = seg_min.prod(l,r);
    auto ma = seg_max.prod(l,r);
    seg_max.set(ma.it,{mi.v,ma.it});
    seg_max.set(mi.it,{ma.v,mi.it});
    seg_min.set(ma.it,{mi.v,ma.it});
    seg_min.set(mi.it,{ma.v,mi.it});
  }
  rep(i,n){
    cout<<seg_min.get(i).v<<" ";
  }
  cout<<endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
