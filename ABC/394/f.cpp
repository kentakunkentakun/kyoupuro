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
  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  vll dp(n, 0);
  auto dfs = [&](auto dfs, int i, int f) -> ll
  {
    if (t[i].size() == 1)
    {
      dp[i] = 2;
      return dp[i];
    }
    vll res(0);
    for (auto p : t[i])
    {
      if (p != f)
      {
        ll a = dfs(dfs, p, i);
        res.pb(a);
      }
    }

    sort(all(res));
    if (t[i].size() < 4)
    {
      dp[i] = 2;
      return 2;
    }
    else
    {
      ll cnt = 2;
      if (res.size() == 3)
      {
        rep(h, 3)
        {
          cnt += res[h] - 1;
        }
        dp[i] = cnt;
        return dp[i];
      }
      else
      {
        for (ll h = (ll)res.size() - 1; h >= (ll)res.size() - 4; h--)
        {
          cnt += res[h] - 1;
        }
        cnt--;
        dp[i] = cnt;
        ll re = 2;
        for (ll h = res.size() - 1; h >= res.size() - 3; h--)
        {
          re += res[h] - 1;
        }
        return re;
      }
    }
  };
  ll s = 0;
  rep(i, n)
  {
    if (t[i].size() >= 4)
    {
      s = i;
      break;
    }
  }
  dfs(dfs, s, -1);

  ll ans = 0;
  rep(i, n)
  {
    chmax(ans, dp[i]);
  }
  if (ans == 2)
  {
    cout << -1 << endl;
  }
  else
    cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
