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
int main()
{
  ll n;
  cin >> n;
  vll d(n);
  rep(i, n) cin >> d[i];
  ll l1, c1, k1, l2, c2, k2;
  cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;
  vvll dp(n + 1, vll(k1 + 1, INF));
  dp[0][0] = 0;
  rep(i, n)
  {
    rep(j, k1)
    {
      if (dp[i][j] == INF)
        continue;
      for (ll z = j; z <= k1; z++)
      {
        ll remain = d[i] - (z - j) * l1;
        ll h = (remain + l2 - 1) / l2;
        if (h < 0)
          h = 0;
        if (h + dp[i][j] <= k2)
        {
          chmin(dp[i + 1][z], dp[i][j] + h);
        }
      }
    }
  }
  ll ans = INF;
  rep(i, k1 + 1)
  {
    if (dp[n][i] != INF)
    {
      chmin(ans, c1 * i + c2 * dp[n][i]);
    }
  }
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
