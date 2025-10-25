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
  vll x(n), c(n);
  set<ll> s;
  rep(i, n)
  {
    cin >> x[i] >> c[i];
    s.insert(c[i]);
  }
  map<ll, ll> m;
  ll iter = 0;
  for (auto p : s)
  {
    if (!m.count(p))
    {
      m[p] = iter;
      iter++;
    }
  }
  vector<pll> p(m.size(), {INF, -INF});
  rep(i, n)
  {
    ll it = m[c[i]];
    chmin(p[it].F, x[i]);
    chmax(p[it].S, x[i]);
  }
  n = p.size();
  vvll dp(n + 1, vll(2, INF));
  dp[0][0] = 0;
  dp[0][1] = 0;
  rep(i, n)
  {
    ll now = 0;
    rep(j, 2)
    {
      if (i > 0)
      {
        if (j)
        {
          now = p[i - 1].S;
        }
        else
        {
          now = p[i - 1].F;
        }
      }
      if (i == 0)
        now = 0;
      // f->s
      {
        ll cost = abs(p[i].F - now) + abs(p[i].S - p[i].F);
        chmin(dp[i + 1][1], dp[i][j] + cost);
      }
      {
        ll cost = abs(p[i].S - now) + abs(p[i].F - p[i].S);
        chmin(dp[i + 1][0], dp[i][j] + cost);
      }
    }
  }
  cout << min(dp[n][0] + abs(p[n - 1].F), dp[n][1] + abs(p[n - 1].S)) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
