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
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
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
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  SegmentTree<ll> seg(n + 1, [](ll a, ll b)
                      { return a + b; }, 0LL);
  for (int i = 1; i < (int)s.size(); i++)
  {
    if (s[i] == s[i - 1])
      seg.update(i - 1, 1);
  }
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;
      ll now_l = seg.query(l - 1, l);
      seg.update(l - 1, 1 - now_l);
      ll now_r = seg.query(r, r + 1);
      seg.update(r, 1 - now_r);
    }
    else
    {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;
      ll cnt = seg.query(l, r);
      if (cnt != 0)
      {
        cout << "No" << endl;
      }
      else
      {
        cout << "Yes" << endl;
      }
    }
  }
}

/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
