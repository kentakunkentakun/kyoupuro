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
  vvll a(h, vll(w));
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> a[i][j];
    }
  }
  vvll dp(h + 1, vll(8, INF));
  auto ch = [&](ll x, ll y, ll up, ll now, ll down) -> bool
  {
    int cnt = 0;
    ll now_v = now ? 1 - a[x][y] : a[x][y];
    if (x - 1 >= 0)
    {
      ll up_v = up ? 1 - a[x - 1][y] : a[x - 1][y];
      if (now_v != up_v)
        cnt++;
    }
    else
    {
      cnt++;
    }
    if (y - 1 >= 0)
    {
      if (a[x][y - 1] != a[x][y])
      {
        cnt++;
      }
    }
    else
    {
      cnt++;
    }
    if (y + 1 < w)
    {
      if (a[x][y + 1] != a[x][y])
      {
        cnt++;
      }
    }
    else
    {
      cnt++;
    }
    if (x + 1 < h)
    {
      ll down_v = down ? 1 - a[x + 1][y] : a[x + 1][y];
      if (down_v != now_v)
      {
        cnt++;
      }
    }
    else
    {
      cnt++;
    }
    if (cnt == 4)
    {
      return false;
    }
    return true;
  };
  auto v = [&](ll bit, ll i) -> bool
  {
    bool ok = true;
    rep(j, w)
    {
      ok &= ch(i - 1, j, (bit >> 2) & 1, (bit >> 1) & 1, bit & 1);
    }
    if (ok)
    {
      return true;
    }
    else
    {
      return false;
    }
  };
  rep(i, h)
  {
    if (i == 0)
    {
      dp[i + 1][0] = 0;
      dp[i + 1][1] = 1;
      continue;
    }
    rep(bit, 8)
    {
      rep(z, 2)
      {
        if (dp[i][bit] != INF)
        {
          ll nbit = (bit << 1) % 8 + z;
          if (v(nbit, i))
          {
            chmin(dp[i + 1][nbit], dp[i][bit] + z);
          }
        }
      }
    }
  }
  ll ans = INF;
  rep(bit, 8)
  {
    if (dp[h][bit] != INF)
    {
      bool ok = true;
      rep(j, w)
      {
        ok &= ch(h - 1, j, (bit >> 1) & 1, (bit & 1), 0);
      }
      if (ok)
      {
        chmin(ans, dp[h][bit]);
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
