#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
#define ll long long
#define ld long double
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
// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
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
template <typename T = ll>
struct CC
{
  bool initialized;
  vector<T> xs;
  CC() : initialized(false) {}
  void add(T x) { xs.push_back(x); }
  void init()
  {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    initialized = true;
  }

  // lower_bound
  ll lb(T x)
  {
    if (!initialized)
      init();
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
  }

  // x 以下の最大の要素のindex
  ll operator()(T x)
  {
    if (!initialized)
      init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }

  // 圧縮後index i に対応する元の値を取得
  T operator[](ll i)
  {
    if (!initialized)
      init();
    return xs[i];
  }

  // x を登録済みかどうか
  bool contains(T x)
  {
    if (!initialized)
      init();
    int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    return i < (int)xs.size() && xs[i] == x;
  }

  ll size()
  {
    if (!initialized)
      init();
    return xs.size();
  }
};

struct S
{
  ll cnt, num;
  bool empty;
};
S op(S a, S b)
{
  if (a.empty)
  {
    return b;
  }
  else if (b.empty)
  {
    return a;
  }
  if (a.num > b.num)
  {
    return b;
  }
  else if (a.num < b.num)
  {
    return a;
  }
  else
  {
    return {a.cnt + b.cnt, a.num, false};
  }
}
S e()
{
  return {0, INF, true};
}
S mapping(ll f, S a)
{
  a.num += f;
  return a;
}
ll composition(ll g, ll f)
{
  return g + f;
}
ll id()
{
  return 0;
}
int main()
{
  ll H, W, h, w, n;
  cin >> H >> W >> h >> w >> n;
  vll r(n), c(n);
  CC<ll> cc;
  map<ll, vector<tuple<ll, ll, ll>>> query;
  cc.add(0);
  cc.add(H - h + 1);
  rep(i, n)
  {
    cin >> r[i] >> c[i];
    r[i]--;
    c[i]--;
    ll sr = max(0LL, r[i] - h + 1);
    ll er = min(r[i] + 1, H - h + 1);
    cc.add(sr);
    cc.add(er);
    if (c[i] - w + 1 <= W - w)
      query[max(0LL, c[i] - w + 1)].pb({sr, er, 1});
    if (c[i] + 1 <= W - w)
      query[c[i] + 1].pb({sr, er, -1});
  }
  query[0].pb({0, H - h + 1, 0});
  query[W - w].pb({0, H - h + 1, 0});
  cc.init();
  vector<S> ini(0);
  rep(i, cc.size() - 1)
  {
    ini.pb({cc[i + 1] - cc[i], 0, false});
  }
  lazy_segtree<S, op, e, ll, mapping, composition, id> seg(ini);

  ll pre = -1;
  ll cnt = 0;
  ll ans = 0;
  for (auto [now, v] : query)
  {
    if (pre != -1)
    {
      ans += (now - pre - 1) * cnt;
    }
    for (auto [sr, er, op] : v)
    {
      seg.apply(cc(sr), cc(er), op);
    }
    S res = seg.all_prod();
    if (res.num == 0)
    {
      ans += res.cnt;
      cnt = res.cnt;
    }
    else
    {
      cnt = 0;
    }
    pre = now;
  }
  cout << ans << endl;
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
