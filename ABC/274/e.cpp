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
  cout << fixed << setprecision(10);

  ll n, m;
  cin >> n >> m;
  vector<double> X(n), Y(n);
  rep(i, n)
  {
    cin >> X[i] >> Y[i];
  }
  vll p(m), q(m);
  rep(i, m)
  {
    cin >> p[i] >> q[i];
  }
  double ans = INF;
  rep(i, m + 1)
  {
    vector<double> x(0), y(0);
    rep(j, i)
    {
      x.pb(p[j]);
      y.pb(q[j]);
    }
    rep(j, n)
    {
      x.pb(X[j]);
      y.pb(Y[j]);
    }
    x.pb(0);
    y.pb(0);

    ll N = x.size();
    vector<vector<double>> dp((1 << N), vector<double>(N, INF));
    auto dfs = [&](auto dfs, ll S, ll v) -> double
    {
      if (dp[S][v] != INF)
      {
        return dp[S][v];
      }
      if (S == (1 << N) - 1 && v == N - 1)
      {
        return dp[S][v] = 0;
      }
      double res = numeric_limits<double>::max();
      double speed = pow(2, __builtin_popcount(S & ((ll)pow(2, i) - 1)));
      rep(u, N)
      {
        if (!(S >> u & 1))
        {
          double kyori = sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
          res = min(res, dfs(dfs, S | (1 << u), u) + kyori / speed);
        }
      }
      return dp[S][v] = res;
    };
    dfs(dfs, 0, N - 1);
    chmin(ans, dp[0][N - 1]);
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
