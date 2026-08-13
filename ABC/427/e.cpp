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
using vvvvll = vector<vvvll>;
using vvvvvll = vector<vvvvll>;
using vvvvvvll = vector<vvvvvll>;
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
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vvvvll ch(h, vvvll(w, vvll(h, vll(w, -1))));
  ll sx = 0, sy = 0;
  rep(i, h)
  {
    rep(j, w)
    {
      if (s[i][j] == 'T')
      {
        sx = i;
        sy = j;
      }
    }
  }
  rep(i, h)
  {
    rep(j, w)
    {
      for (int ii = i; ii < h; ii++)
      {
        for (int jj = j; jj < w; jj++)
        {
          bool ok = true;
          for (int x = i; x <= ii; x++)
          {
            for (int y = j; y <= jj; y++)
            {
              if (s[x][y] == '#')
              {
                ok = false;
                break;
              }
            }
            if (!ok)
            {
              break;
            }
          }
          if (ok)
          {
            ch[i][j][ii][jj] = 1;
          }
        }
      }
    }
  }
  map<tuple<ll, ll, ll, ll, ll, ll>, ll> dp;
  dp[{0, 0, h - 1, w - 1, sx, sy}] = 0;
  queue<tuple<ll, ll, ll, ll, ll, ll>> que;
  que.push({0, 0, h - 1, w - 1, sx, sy});
  ll ans = INF;
  while (que.size())
  {
    auto [i, j, ii, jj, x, y] = que.front();
    que.pop();
    if (ch[i][j][ii][jj] == 1)
    {
      chmin(ans, dp[{i, j, ii, jj, x, y}]);
    }
    rep(z, 4)
    {
      ll ni = i;
      ll nj = j;
      ll nii = ii;
      ll njj = jj;
      ll nx = x + dx[z];
      ll ny = y + dy[z];
      if (!isIn(nx, ny, h, w) || s[nx][ny] != '#' || ni > nx || nii < nx || nj > ny || njj < ny)
      {
        if (z == 0)
        {
          nj++;
        }
        else if (z == 1)
        {
          ni++;
        }
        else if (z == 2)
        {
          njj--;
        }
        else
        {
          nii--;
        }
        if ((njj < nj || nii < ni) || dp.count({ni, nj, nii, njj, nx, ny}))
        {
          continue;
        }
        dp[{ni, nj, nii, njj, nx, ny}] = dp[{i, j, ii, jj, x, y}] + 1;

        que.push({ni, nj, nii, njj, nx, ny});
      }
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
