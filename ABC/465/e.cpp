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
  string s;
  cin >> s;
  ll n = s.size();
  vector<vector<vector<vector<ll>>>> dp(n + 1, vvvll(3, vvll(1024, vll(2))));
  dp[0][0][0][0] = 1;
  rep(i, n)
  {
    rep(j, 2)
    {
      rep(nx, 10)
      {
        ll nj = j;
        if (j == 0 && (s[i] - '0') < nx)
        {
          continue;
        }
        if (j == 0 && (s[i] - '0') > nx)
        {
          nj = 1;
        }
        rep(r, 3)
        {
          rep(k, 1024)
          {
            if (k == 0 && nx == 0)
            {
              dp[i + 1][0][0][1] += dp[i][r][k][j];
            }
            else
            {
              dp[i + 1][(r + nx) % 3][k | (1 << nx)][nj] += dp[i][r][k][j];
              dp[i + 1][(r + nx) % 3][k | (1 << nx)][nj] %= MOD;
            }
          }
        }
      }
    }
  }
  ll ans = 0;
  dp[n][0][0][1]--;
  dp[n][0][0][1] += MOD;
  dp[n][0][0][1] %= MOD;
  rep(i, 1024)
  {
    if (!(i >> 3 & 1) && __builtin_popcountll(i) != 3)
    {
      ans += dp[n][0][i][0] + dp[n][0][i][1];
      ans %= MOD;
    }
    if ((i >> 3 & 1) && __builtin_popcountll(i) != 3)
    {
      ans += dp[n][1][i][0] + dp[n][2][i][0];
      ans %= MOD;
      ans += dp[n][1][i][1] + dp[n][2][i][1];
      ans %= MOD;
    }
    if (!(i >> 3 & 1) && __builtin_popcountll(i) == 3)
    {
      ans += dp[n][1][i][0] + dp[n][2][i][0];
      ans %= MOD;
      ans += dp[n][1][i][1] + dp[n][2][i][1];
      ans %= MOD;
    }
  }
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
