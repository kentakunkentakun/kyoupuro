#include <bits/stdc++.h>

using namespace std;
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
using vvvvll = vector<vvvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T>
using PQ = priority_queue<T>;

template <class T>
using PQR = priority_queue<T, vector<T>, greater<T>>;

// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 62;
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
  ll n;
  cin >> n;
  vector<string> s(n);
  vll sx(0), sy(0);
  rep(i, n)
  {
    cin >> s[i];
    rep(j, n)
    {
      if (s[i][j] == 'P')
      {
        sx.pb(i);
        sy.pb(j);
      }
    }
  }
  vvvvll dist(n, vvvll(n, vvll(n, vll(n, INF))));
  dist[sx[0]][sy[0]][sx[1]][sy[1]] = 0;
  queue<tuple<ll, ll, ll, ll>> que;
  que.push({sx[0], sy[0], sx[1], sy[1]});
  while (que.size())
  {
    auto [x, y, xx, yy] = que.front();
    que.pop();
    ll v = dist[x][y][xx][yy];
    rep(i, 4)
    {
      ll nx = x;
      ll ny = y;
      ll nxx = xx;
      ll nyy = yy;
      if (isIn(dx[i] + x, dy[i] + y, n, n) && s[dx[i] + x][dy[i] + y] != '#')
      {
        nx += dx[i];
        ny += dy[i];
      }
      if (isIn(dx[i] + xx, dy[i] + yy, n, n) && s[dx[i] + xx][dy[i] + yy] != '#')
      {
        nxx += dx[i];
        nyy += dy[i];
      }
      if (chmin(dist[nx][ny][nxx][nyy], v + 1))
      {
        que.push({nx, ny, nxx, nyy});
      }
    }
  }
  ll ans = INF;
  rep(i, n)
  {
    rep(j, n)
    {
      chmin(ans, dist[i][j][i][j]);
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
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
