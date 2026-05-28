#include <bits/stdc++.h>
#include <atcoder/dsu>
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
struct edge
{
  ll to, it;
};
int main()
{
  ll n;
  cin >> n;
  vll p(n); // iに何番があるか
  vll d(n); // iがどこにいるか
  dsu uf(n);
  dsu uf2(n);

  rep(i, n)
  {
    cin >> p[i];
    p[i]--;
    d[p[i]] = i;
    uf.merge(i, p[i]);
  }
  ll m;
  cin >> m;
  vector<vector<edge>> t(n, vector<edge>(0));
  vector<pll> e(m);
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    e[i] = {a, b};
    if (!uf2.same(a, b))
    {
      t[a].pb({b, i});
      t[b].pb({a, i});
    }
    uf2.merge(a, b);
  }

  bool ch = true;
  rep(i, n)
  {
    if (!uf2.same(i, p[i]))
    {
      cout << -1 << endl;
      return 0;
    }
  }
  if (!ch)
  {
    cout << -1 << endl;
    return 0;
  }
  vll ans(0);
  vb used(n, false);
  // itの辺を使って移動
  auto move = [&](ll it) -> void
  {
    auto [a, b] = e[it];
    ll f = p[a];
    ll s = p[b];
    d[f] = b;
    d[s] = a;
    swap(p[a], p[b]);
  };
  // 移動
  auto dfs = [&](auto dfs, ll x, ll par) -> bool
  {
    if (d[x] == x)
    {
      return true;
    }
    ll now = d[x];
    for (auto [nx, it] : t[now])
    {
      if (nx != par && !used[nx])
      {
        ans.pb(it);
        move(it);
        if (dfs(dfs, x, now))
        {
          return true;
        }
        ans.pb(it);
        move(it);
      }
    }
    return false;
  };
  // xを所定の位置までもっていく
  auto f = [&](ll x) -> void
  {
    if (d[x] == x)
    {
      used[x] = true;
      return;
    }
    dfs(dfs, x, -1);
    used[x] = true;
  };
  auto start = [&](auto start, ll x, ll par) -> void
  {
    if (used[x])
    {
      return;
    }
    for (auto [nx, it] : t[x])
    {
      if (nx != par)
        start(start, nx, x);
    }
    f(x);
    return;
  };

  rep(i, n)
  {
    if (!used[i])
    {
      start(start, i, -1);
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size())
  {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
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
