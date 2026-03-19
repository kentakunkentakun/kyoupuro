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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
int main()
{
  ll h, w, k;
  cin >> h >> w >> k;
  ll sx, sy;
  cin >> sx >> sy;
  sx--;
  sy--;
  vvll a(h, vll(w));
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> a[i][j];
    }
  }
  ll m = h * w + 5;
  vvvll dp(h, vvll(w, vll(m, -INF)));
  dp[sx][sy][0] = 0;
  queue<tuple<ll, ll, ll, ll>> que;
  que.push({sx, sy, 0, 0});
  while (que.size())
  {
    auto [x, y, u, v] = que.front();
    que.pop();
    if (u > h * w)
    {
      break;
    }
    if (dp[x][y][u] > v)
      continue;
    rep(i, 4)
    {
      ll nx = dx[i] + x;
      ll ny = dy[i] + y;
      if (isIn(nx, ny, h, w))
      {
        if (chmax(dp[nx][ny][u + 1], dp[x][y][u] + a[nx][ny]))
        {
          que.push({nx, ny, u + 1, dp[nx][ny][u + 1]});
        }
      }
    }
    if (chmax(dp[x][y][u + 1], dp[x][y][u] + a[x][y]))
    {
      que.push({x, y, u + 1, dp[x][y][u + 1]});
    }
  }
  ll ans = 0;
  rep(i, h)
  {
    rep(j, w)
    {
      rep(z, min(k + 1, h * w + 1))
      {
        chmax(ans, dp[i][j][z] + (k - z) * a[i][j]);
      }
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
