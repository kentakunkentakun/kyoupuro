#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0; i--)
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
  ll n, d;
  cin >> n >> d;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  map<ll, ll> m;
  rep(i, n)
  {
    m[a[i]]++;
  }
  ll ans = 0;
  if (d == 0)
  {
    for (auto p : m)
    {
      if (p.S > 0)
        ans += p.S - 1;
    }
    cout << ans << endl;
    return 0;
  }

  vector<bool> ch(1000005, false);
  for (auto p : m)
  {
    if (!ch[p.F])
    {
      ll now = p.F;
      vll t = {};
      while (now < 1000005)
      {
        ch[now] = true;
        if (m[now] != 0)
          t.pb(m[now]);
        if (m[now] == 0 && t.size() > 0 && t.back() != 0)
          t.pb(m[now]);

        now += d;
      }
      vvll dp(t.size() + 1, vll(2, INF));
      dp[0][0] = 0;
      // rep(i, 10)
      // {
      //   cout << t[i] << " ";
      // }
      // cout << endl;
      rep(i, t.size())
      {

        if (dp[i][0] != INF)
        {
          chmin(dp[i + 1][1], dp[i][0]);
          chmin(dp[i + 1][0], dp[i][0] + t[i]);
        }
        if (dp[i][1] != INF)
        {
          chmin(dp[i + 1][0], dp[i][1] + t[i]);
        }
        if (dp[i][1] != INF && t[i] == 0)
        {
          chmin(dp[i + 1][1], dp[i][1] + t[i]);
        }
      }
      // rep(i, 10)
      // {
      //   // cout << dp[i][0] << " ";
      // }
      ans += min(dp[t.size()][0], dp[t.size()][1]);
      // cout << endl;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
