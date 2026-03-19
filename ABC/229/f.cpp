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
  vll a(n), b(n);
  ll sum = 0;
  rep(i, n)
  {
    cin >> a[i];
    sum += a[i];
  }
  rep(i, n)
  {
    cin >> b[i];
    sum += b[i];
  }
  vvvll dp(n + 1, vvll(2, vll(2, -INF)));
  dp[0][0][0] = 0;
  dp[0][1][1] = 0;
  rep(i, n - 1)
  {
    rep(j, 2)
    {
      rep(z, 2)
      {
        // つなげる
        ll p = 0;
        if (z == i % 2)
          p = a[i];
        chmax(dp[i + 1][j][z], dp[i][j][z] + p + b[i]);
        // つなげない
        chmax(dp[i + 1][j][0], dp[i][j][z] + p);
        chmax(dp[i + 1][j][1], dp[i][j][z] + p);
      }
    }
  }
  ll ans = -INF;
  if ((n - 1) % 2)
  {
    chmax(ans, dp[n - 1][0][0] + b[n - 1]);
    chmax(ans, dp[n - 1][0][1] + a[n - 1]);
    chmax(ans, dp[n - 1][1][0]);
    chmax(ans, dp[n - 1][1][1] + a[n - 1] + b[n - 1]);
  }
  else
  {
    chmax(ans, dp[n - 1][0][0] + a[n - 1]);
    chmax(ans, dp[n - 1][1][0] + b[n - 1] + a[n - 1]);
    chmax(ans, dp[n - 1][0][1] + b[n - 1]);
    chmax(ans, dp[n - 1][1][1]);
  }
  cout << sum - ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
