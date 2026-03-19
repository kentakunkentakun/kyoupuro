#include <bits/stdc++.h>
#include <atcoder/segtree>
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
ll op(ll a, ll b)
{
  return a + b;
}
ll e()
{
  return 0;
}
ll k = 1;
bool g(ll a)
{
  if (a < k)
  {
    return true;
  }
  return false;
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vll a(n);
  vll d(m);
  rep(i, n)
  {
    cin >> a[i];
    a[i]--;
    d[a[i]]++;
  }
  vvll cntnum(n + 1, vll(0));
  rep(i, m)
  {
    cntnum[d[i]].pb(i);
  }
  set<ll> s;
  ll q;
  cin >> q;
  vector<pll> que(q);
  segtree<ll, op, e> seg(m);
  rep(i, q)
  {
    ll x;
    cin >> x;
    que[i] = {x, i};
  }
  sort(all(que));
  vll ans(q);
  ll cnt = n;
  ll it = 0;
  while (it < q && que[it].F - 1 < n)
  {
    ans[que[it].S] = a[que[it].F - 1] + 1;
    it++;
  }
  ll now_len = 0;
  ll cntnum_it = 0;
  while (now_len < m)
  {
    rep(i, cntnum[cntnum_it].size())
    {
      seg.set(cntnum[cntnum_it][i], 1);
    }
    now_len += cntnum[cntnum_it].size();
    while (it < q && que[it].F <= now_len + cnt)
    {
      // 何番目？(u);
      k = que[it].F - cnt;
      ll res = seg.max_right<g>(0);
      ans[que[it].S] = res + 1;
      it++;
    }
    cntnum_it++;
    cnt += now_len;
  }
  while (it < q)
  {
    ans[que[it].S] = (que[it].F - cnt) % m;
    if ((que[it].F - cnt) % m == 0)
      ans[que[it].S] = m;
    it++;
  }
  rep(i, q)
  {
    cout << ans[i] << endl;
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
