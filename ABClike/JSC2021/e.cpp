#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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
ll dx[3] = {0, 1, 0};
ll dy[3] = {1, 0, -1};
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct S
{
  ll sum, cnt;
};
S op(S a, S b)
{
  return {a.sum + b.sum, a.cnt + b.cnt};
}
S e()
{
  return {0, 0};
}
int main()
{
  ll n, m, q;
  cin >> n >> m >> q;
  vector<tuple<ll, ll, ll>> que(q);
  set<ll> s;
  map<ll, ll> it;
  rep(i, q)
  {
    ll t, x, y;
    cin >> t >> x >> y;
    que[i] = {t, x, y};
    s.insert(y);
  }
  s.insert(0);
  ll iter = 0;
  for (auto p : s)
  {
    it[p] = iter;
    iter++;
  }
  segtree<S, op, e> sega(iter);
  segtree<S, op, e> segb(iter);
  ll res = 0;
  vll a(n), b(m);
  sega.set(0, {0, n});
  segb.set(0, {0, m});
  rep(i, q)
  {
    auto [t, x, y] = que[i];
    x--;
    if (t == 1)
    {
      ll b_it = it[a[x]];
      res -= segb.prod(b_it, iter).sum;
      res -= segb.prod(0, b_it).cnt * a[x];
      auto now = sega.get(b_it);
      now.sum -= a[x];
      now.cnt--;
      sega.set(b_it, now);
      a[x] = y;
      b_it = it[y];
      res += segb.prod(b_it, iter).sum;
      res += segb.prod(0, b_it).cnt * y;
      now = sega.get(b_it);
      now.sum += y;
      now.cnt++;
      sega.set(b_it, now);
    }
    else
    {
      ll b_it = it[b[x]];
      res -= sega.prod(b_it, iter).sum;
      res -= sega.prod(0, b_it).cnt * b[x];
      auto now = segb.get(b_it);
      now.sum -= b[x];
      now.cnt--;
      segb.set(b_it, now);
      b[x] = y;
      b_it = it[y];
      res += sega.prod(b_it, iter).sum;
      res += sega.prod(0, b_it).cnt * y;
      now = segb.get(b_it);
      now.sum += y;
      now.cnt++;
      segb.set(b_it, now);
    }
    cout << res << endl;
  }
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
