#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
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
int main()
{
  ll n, l;
  cin >> n >> l;
  vll c(n);
  vvll p(n, vll(l));
  rep(i, n)
  {
    cin >> c[i];
    rep(j, l)
    {
      cin >> p[i][j];
      p[i][j]--;
    }
  }
  if (l == 1)
  {
    ll ans = 0;
    rep(i, n)
    {
      ans += c[i];
    }
    cout << ans << endl;
    return 0;
  }
  vll dp(n + 1, 0);
  ll k = l * (l - 1) / 2;
  ll ans = 0;
  rep(i, n)
  {
    for (int j = 1; j <= k; j++)
    {
      if (i + 1 - j < 0)
      {
        continue;
      }
      vll from_it(l);
      vll now_it(l);
      if (i + 1 - j != 0)
      {
        rep(z, l)
        {
          from_it[p[i - j][z]] = z;
        }
      }
      else
      {
        rep(z, l)
        {
          from_it[z] = z;
        }
      }

      rep(z, l)
      {
        now_it[z] = from_it[p[i][z]];
      }
      fenwick_tree<ll> BIT(l);
      ll cost = 0;
      rep(z, l)
      {
        cost += BIT.sum(now_it[z] + 1, l);
        BIT.add(now_it[z], 1);
      }
      if (cost <= j)
      {
        chmax(dp[i + 1], c[i] + dp[i - j + 1]);
      }
    }
    chmax(ans, dp[i + 1]);
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
