#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x, vector<x>, greater<x>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
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
template <typename T>
struct SegmentTree
{
  typedef function<T(T, T)> F;
  int n; // 要素数
  F f;   // 2項演算
  T e;   // 単位元
  vector<T> dat;
  SegmentTree(int n_, F f, T e) : f(f), e(e)
  {
    init(n_);
    build();
  }
  SegmentTree(int n_, F f, T e, vector<T> &v) : f(f), e(e)
  {
    init(n_);
    build(n_, v);
  }
  void init(int n_)
  {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.clear();
    dat.resize(n << 1, e);
  }
  void build(int n_, const vector<T> &v)
  {
    for (int i = 0; i < n_; ++i)
      dat[n + i] = v[i];
    build();
  }
  void build()
  {
    for (int i = n - 1; i >= 1; --i)
    {
      dat[i] = f(dat[i << 1], dat[i << 1 | 1]);
    }
  }
  void update(int k, const T &x)
  {
    dat[k += n] = x;
    while (k >>= 1)
    {
      dat[k] = f(dat[k << 1], dat[k << 1 | 1]);
    }
  }
  T query(int a, int b)
  {
    T l = e, r = e;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
        l = f(l, dat[a++]);
      if (b & 1)
        r = f(dat[--b], r);
    }
    return f(l, r);
  }
};
int main()
{
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll q;
  cin >> q;
  set<ll> e;
  vector<set<ll>> ini(n);
  rep(i, n)
  {
    ini[i].insert(s[i]);
  }
  SegmentTree<set<ll>>
      seg(n, [](set<ll> a, set<ll> b)
          {
    set<ll> tmp;
    for(auto p:a){
      tmp.insert(p);
    } 
    for(auto k:b){
      tmp.insert(k);
    }
  return tmp; }, e, ini);
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      char b;
      ll a;
      cin >> a >> b;
      set<ll> ne;
      ne.insert(b);
      seg.update(a - 1, ne);
    }
    else
    {
      ll a, b;
      cin >> a >> b;
      set<ll> res = seg.query(a - 1, b);
      cout << res.size() << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
