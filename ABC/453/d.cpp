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
int main()
{
  ll h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  ll sx, sy, gx, gy;
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> s[i][j];
      if (s[i][j] == 'S')
      {
        sx = i;
        sy = j;
      }
      else if (s[i][j] == 'G')
      {
        gx = i;
        gy = j;
      }
    }
  }
  vvvll dp(h, vvll(w, vll(4, INF)));
  queue<tuple<ll, ll, ll>> que;
  rep(j, 4)
  {
    dp[sx][sy][j] = 0;
    que.push({sx, sy, j});
  }
  while (que.size())
  {
    auto [x, y, z] = que.front();
    que.pop();
    rep(i, 4)
    {
      bool ok = false;
      if (s[x][y] == 'o' && z == i)
        ok = true;
      if (s[x][y] == 'x' && z != i)
        ok = true;
      if (s[x][y] == '.' || s[x][y] == 'S')
        ok = true;
      if (ok)
      {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (isIn(nx, ny, h, w) && s[nx][ny] != '#')
        {
          if (chmin(dp[nx][ny][i], dp[x][y][z] + 1))
          {
            que.push({nx, ny, i});
          }
        }
      }
    }
  }
  rep(i, 4)
  {
    if (dp[gx][gy][i] != INF)
    {
      vector<char> res(0);
      cout << "Yes" << endl;
      ll now = 0;
      ll x = gx;
      ll y = gy;
      ll z = i;
      while ((x != sx) || (y != sy))
      {
        if (z == 0)
        {
          res.pb('R');
        }
        else if (z == 1)
        {
          res.pb('D');
        }
        else if (z == 2)
        {
          res.pb('L');
        }
        else
        {
          res.pb('U');
        }
        ll nx, ny, nz;
        if (z == 0)
        {
          nx = x;
          ny = y - 1;
        }
        if (z == 1)
        {
          nx = x - 1;
          ny = y;
        }
        if (z == 2)
        {
          nx = x;
          ny = y + 1;
        }
        if (z == 3)
        {
          nx = x + 1;
          ny = y;
        }
        rep(j, 4)
        {
          if (s[nx][ny] == '.' || s[nx][ny] == 'S')
          {
            if (dp[nx][ny][j] + 1 == dp[x][y][z])
            {
              x = nx;
              y = ny;
              z = j;
              break;
            }
          }
          else if (s[nx][ny] == 'o' && j == z)
          {
            if (dp[nx][ny][j] + 1 == dp[x][y][z])
            {
              x = nx;
              y = ny;
              z = j;
              break;
            }
          }
          else if (s[nx][ny] == 'x' && j != z)
          {
            if (dp[nx][ny][j] + 1 == dp[x][y][z])
            {
              x = nx;
              y = ny;
              z = j;
              break;
            }
          }
        }
      }
      reverse(all(res));
      rep(i, res.size())
      {
        cout << res[i];
      }
      return 0;
    }
  }
  cout << "No" << endl;
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
