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
int main()
{
  ll h, w;
  cin >> h >> w;
  vvll a(h, vll(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vvll b(h, vll(w));
  rep(i, h) rep(j, w) cin >> b[i][j];
  vector<vector<bitset<26000>>> dp(h, vector<bitset<26000>>(w));
  dp[0][0][13000 + (a[0][0] - b[0][0])] = 1;
  dp[0][0][13000 + (b[0][0] - a[0][0])] = 1;
  rep(i, h)
  {
    rep(j, w)
    {
      if (i)
      {
        dp[i][j] |= dp[i - 1][j] << abs(a[i][j] - b[i][j]);
        dp[i][j] |= dp[i - 1][j] >> abs(a[i][j] - b[i][j]);
      }
      if (j)
      {
        dp[i][j] |= dp[i][j - 1] << abs(a[i][j] - b[i][j]);
        dp[i][j] |= dp[i][j - 1] >> abs(a[i][j] - b[i][j]);
      }
    }
  }
  ll ans = INF;
  rep(i, 26000)
  {
    if (dp[h - 1][w - 1][i])
    {
      if (ans > abs(13000 - i))
      {
        ans = abs(13000 - i);
      }
    }
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
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
