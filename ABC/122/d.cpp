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
  string c = "AGCT";
  vector<string> t = {
      "AGC", "GAC", "ACG", "AGGC", "ATGC", "AGGC", "AGTC"};
  vector<string> pfx;
  rep(i, t.size())
  {
    rep(j, t[i].size() + 1)
    {
      pfx.push_back(t[i].substr(0, j));
    }
  }
  sort(all(pfx));
  pfx.erase(unique(all(pfx)), pfx.end());
  ll k = pfx.size();
  vvll next(k, vll(4));
  vb ng(k, false);
  rep(i, k)
  {
    rep(j, t.size())
    {
      if (t[j] == pfx[i])
        ng[i] = true;
    }
    rep(j, 4)
    {
      string s = pfx[i] + c[j];
      ll ne;
      for (;;)
      {
        ne = lower_bound(all(pfx), s) - pfx.begin();
        if (ne < pfx.size() && pfx[ne] == s)
          break;
        s = s.substr(1);
      }
      next[i][j] = ne;
    }
  }
  vvll dp(n + 1, vll(k + 2, 0));
  dp[0][0] = 1;
  rep(i, n)
  {
    rep(k, pfx.size())
    {
      if (ng[k])
        continue;
      rep(j, 4)
      {
        ll to = next[k][j];
        dp[i + 1][to] += dp[i][k];
        dp[i + 1][to] %= MOD;
      }
    }
  }
  ll ans = 0;
  rep(i, k)
  {
    if (!ng[i])
    {
      ans += dp[n][i];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
