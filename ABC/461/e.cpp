#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
int main()
{
  ll n, q;
  cin >> n >> q;
  vll r(q, -1);
  vll c(q, -1);
  rep(i, q)
  {
    ll op, t;
    cin >> op >> t;
    if (op == 1)
    {
      r[i] = t;
    }
    else
    {
      c[i] = t;
    }
  }
  // rのコマンド集
  vll rc(n + 1, 0);
  vll cc(n + 1, 0);
  vector<vector<pll>> rq(q);
  vector<vector<pll>> cq(q);
  vll ef(q);

  rep(i, q)
  {
    if (r[i] != -1)
    {
      rq[i].pb({rc[r[i]], i});
      rc[r[i]] = i + 1;
    }
    else
    {
      cq[i].pb({cc[c[i]], i});
      cc[c[i]] = i + 1;
    }
  }

  fenwick_tree<ll> bit(q + 1);
  vll tmp(n + 1, 0);
  bit.add(0, n);
  rep(i, q)
  {
    for (auto [l, it] : rq[i])
    {
      ef[i] = bit.sum(l, it + 1);
    }
    if (c[i] != -1)
    {
      bit.add(tmp[c[i]], -1);
      bit.add(i + 1, 1);
      tmp[c[i]] = i + 1;
    }
  }
  fenwick_tree<ll> bit2(q + 1);

  vll tmp2(n + 1, -1);
  rep(i, q)
  {
    for (auto [l, it] : cq[i])
    {
      ef[i] = bit2.sum(l, it + 1);
    }
    if (r[i] != -1)
    {
      if (tmp2[r[i]] != -1)
      {
        bit2.add(tmp2[r[i]], -1);
      }
      bit2.add(i + 1, 1);
      tmp2[r[i]] = i + 1;
    }
  }
  ll now = 0;
  rep(i, q)
  {
    if (r[i] != -1)
    {
      now += ef[i];
    }
    else
    {
      now -= ef[i];
    }
    cout << now << endl;
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
