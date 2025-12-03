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
  ll n, m;
  cin >> n >> m;
  vector<vector<pll>> s(n);
  rep(i, m)
  {
    ll x, y, z;
    cin >> x >> y >> z;
    x--;
    s[x].pb({y, z});
  }
  vll dp(1 << n, 0);
  dp[0] = 1;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    if (dp[bit] == 0)
      continue;

    ll cnt = __builtin_popcount(bit);
    vll tmp(n + 1);
    rep(i, n)
    {
      if ((bit >> i) & 1)
      {
        tmp[i + 1] += 1;
      }
      tmp[i + 1] += tmp[i];
    }
    rep(i, n)
    {
      bool ok = true;

      if (!((bit >> i) & 1))
      {
        for (auto [y, z] : s[cnt])
        {
          if ((i + 1 <= y) && (tmp[y] + 1 > z))
          {
            ok = false;
            break;
          }
          if ((i + 1 <= y) && (tmp[y] + 1 > z))
          {
            ok = false;
            break;
          }
          if ((i + 1 > y) && (tmp[y] > z))
          {
            ok = false;
            break;
          }
        }

        if (ok)
        {
          dp[bit | (1 << i)] += dp[bit];
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
