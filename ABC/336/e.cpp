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
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;
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
  string s;
  cin >> s;
  ll n = s.size();
  ll init = 1;
  rep(i, n - 1) init *= 10;
  ll ans = 0;
  rep(u, 150)
  {
    if (u == 0)
      continue;
    vvvvll dp(n + 1, vvvll(u + 5, vvll(200, vll(2, 0))));
    // iまでみて、jで割っている、z桁和、
    dp[0][0][0][0] = 1;
    ll ten = init;
    rep(i, n)
    {
      rep(j, u)
      {
        rep(k, 150)
        {
          rep(z, 10)
          {
            ll nv = j + ten * z;
            ll nk = k + z;
            nv %= u;
            dp[i + 1][nv][nk][1] += dp[i][j][k][1];
            if (z < (s[i] - '0'))
            {
              dp[i + 1][nv][nk][1] += dp[i][j][k][0];
            }
            if (z == (s[i] - '0'))
            {
              dp[i + 1][nv][nk][0] += dp[i][j][k][0];
            }
          }
        }
      }
      ten /= 10;
    }
    // cout << dp[n][0][u][1] << " " << dp[n][0][u][0] << " " << u << endl;
    ans += dp[n][0][u][1] + dp[n][0][u][0];
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
