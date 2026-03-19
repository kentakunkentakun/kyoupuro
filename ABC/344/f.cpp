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
int main()
{
  ll n;
  cin >> n;
  vvll p(n, vll(n));
  set<ll> s;
  rep(i, n)
  {
    rep(j, n)
    {
      cin >> p[i][j];
      s.insert(p[i][j]);
    }
  }
  vll iter(s.size());
  unordered_map<ll, ll> m;
  ll it = 0;
  for (auto q : s)
  {
    m[q] = it;
    iter[it] = q;
    it++;
  }
  vvll r(n, vll(n - 1));
  rep(i, n)
  {
    rep(j, n - 1)
    {
      cin >> r[i][j];
    }
  }
  vvll d(n - 1, vll(n));

  rep(i, n - 1)
  {
    rep(j, n) cin >> d[i][j];
  }
  vector<vector<vector<pll>>> dp(n, vector<vector<pll>>(n, vector<pll>(it, {-1, INF})));
  dp[0][0][m[p[0][0]]] = {0, 0};
  rep(i, n)
  {
    rep(j, n)
    {
      pll now = {-1, INF};
      ll v = m[p[i][j]];
      rep(k, it)
      {
        if (dp[i][j][k].F == -1)
          continue;
        auto [hp, cost] = dp[i][j][k];
        ll nx = max(v, k);
        ll nxv = iter[nx];
        auto [h, c] = dp[i][j][nx];
        if (c > cost)
        {
          c = cost;
          h = hp;
        }
        else if (c == cost && h < hp)
        {
          h = hp;
        }
        dp[i][j][nx] = {h, c};
        if (j < n - 1)
        {
          ll ncost = max(0LL, (r[i][j] - h) + nxv - 1) / nxv;
          ll nhp = h + ncost * nxv - r[i][j];
          auto [hh, cc] = dp[i][j + 1][nx];
          if (cc > ncost + c + 1)
          {
            dp[i][j + 1][nx] = {nhp, ncost + c + 1};
          }
          else if (cc == ncost + c + 1 && hh < nhp)
          {
            dp[i][j + 1][nx] = {nhp, ncost + c + 1};
          }
        }
        if (i < n - 1)
        {
          ll ncost = max(0LL, (d[i][j] - h) + nxv - 1) / nxv;
          ll nhp = h + ncost * nxv - d[i][j];
          auto [hh, cc] = dp[i + 1][j][nx];
          if (cc > ncost + c + 1)
          {
            dp[i + 1][j][nx] = {nhp, ncost + c + 1};
          }
          else if (cc == ncost + c + 1 && hh < nhp)
          {
            dp[i + 1][j][nx] = {nhp, ncost + c + 1};
          }
        }
      }
    }
  }
  ll ans = INF;
  rep(i, it)
  {
    auto [a, b] = dp[n - 1][n - 1][i];
    chmin(ans, b);
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
