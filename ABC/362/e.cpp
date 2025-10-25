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
  vll a(n);
  set<ll> s;
  rep(i, n)
  {
    cin >> a[i];
  }
  rep(i, n)
  {
    for (int j = i + 1; j < n; j++)
    {
      s.insert(a[j] - a[i]);
    }
  }
  rep(i, n)
  {
    s.insert(a[i]);
  }
  map<ll, ll> m;
  ll it = 0;
  for (auto p : s)
  {
    m[p] = it;
    it++;
  }
  vector<vector<vvll>> dp(n + 1, vector<vvll>(s.size(), vvll(n, vll(n))));
  rep(i, n)
  {
    rep(j, s.size())
    {
      rep(z, i)
      {
        ll sa = a[i] - a[z];
        if (sa == m[j])
        {
          dp[i + 1][j][i] = dp[i][j][z] + 1;
          dp[i + 1][j][i] %= MOD;
        }

        dp[i + 1][j][z] += dp[i][j][z];
        dp[i + 1][j][z] %= MOD;
      }
    }
  }
  ll ans = n;
  rep(j, n)
  {

    rep(i, s.size())
    {
      if (dp[n][i][j])
      {
        cout << j << " " << dp[n][i][j] << " " << m[i] << " " << a[j] << endl;
      }
      ans += dp[n][i][j];
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
__builtin_popcount(i)*/
