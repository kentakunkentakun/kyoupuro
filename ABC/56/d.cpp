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
int main()
{
  ll n, k;
  cin >> n >> k;
  vll a(n);
  rep(i, n) cin >> a[i];
  vb dp(k + 1);
  vector<fenwick_tree<ll>> BIT(n + 1, fenwick_tree<ll>(k + 1));
  BIT[n].add(0, 1);
  for (int i = n - 1; i >= 0; i--)
  {
    rep(j, k + 1)
    {
      ll v = BIT[i + 1].sum(j, j + 1);
      if (v)
      {
        ll now = BIT[i].sum(j, j + 1);
        if (now == 0)
          BIT[i].add(j, 1);
        if (j + a[i] <= k)
        {
          ll now = BIT[i].sum(j + a[i], j + a[i] + 1);
          if (now == 0)
          {
            BIT[i].add(j + a[i], 1);
          }
        }
      }
    }
  }
  dp[0] = 1;
  ll ans = 0;
  rep(i, n)
  {
    if (a[i] >= k)
    {
      ans++;
    }
    else
    {
      rep(j, k + 1)
      {
        if (dp[j])
        {
          ll l = k - a[i];
          ll r = k;
          l -= j;
          r -= j;
          chmax(l, 0LL);
          chmax(r, 0LL);
          ll v = BIT[i + 1].sum(l, r);
          if (v)
          {
            ans++;
            break;
          }
        }
      }
    }
    vb tmp = dp;
    rep(j, k + 1)
    {
      if (tmp[j] && j + a[i] <= k)
      {
        dp[j + a[i]] = true;
      }
    }
  }
  cout << n - ans << endl;
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
