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
  rep(i, n) cin >> a[i];
  vvll dp(n + 1, vll(205, 0));
  dp[0][0] = 1;
  rep(i, n)
  {
    rep(j, 201)
    {
      dp[i + 1][(j + a[i]) % 200] = min(dp[i + 1][(j + a[i]) % 200] + dp[i][j], 3LL);
      dp[i + 1][j] = min(dp[i + 1][j] + dp[i][j], 3LL);
    }
  }
  dp[n][0]--;
  ll tmp = -1;
  rep(i, 200)
  {
    if (dp[n][i] > 1)
    {
      tmp = i;
    }
  }
  if (tmp == -1)
  {
    cout << "No" << endl;
    return 0;
  }
  vll ans1(0);
  vll ans2(0);
  bool ch = false;
  ll tmp1 = tmp;
  ll tmp2 = tmp;
  for (int i = n; i >= 1; i--)
  {
    if (!ch)
    {
      ll nx = tmp1 - a[i - 1];
      nx %= 200;
      nx += 200;
      nx %= 200;
      if (dp[i - 1][tmp1] >= 1)
      {
        if (dp[i - 1][nx] >= 1)
        {
          ans1.pb(i);
          tmp1 = nx;
          ch = true;
        }
      }
      else
      {
        ans1.pb(i);
        tmp1 = nx;
        ans2.pb(i);
        tmp2 = nx;
      }
    }
    else
    {
      ll pick1 = tmp1 - a[i - 1];
      pick1 %= 200;
      pick1 += 200;
      pick1 %= 200;
      if (dp[i - 1][pick1] >= 1)
      {
        ans1.pb(i);
        tmp1 = pick1;
      }
      ll pick2 = tmp2 - a[i - 1];
      pick2 %= 200;
      pick2 += 200;
      pick2 %= 200;
      if (dp[i - 1][pick2] >= 1)
      {
        ans2.pb(i);
        tmp2 = pick2;
      }
    }
  }
  reverse(all(ans1));
  reverse(all(ans2));
  cout << "Yes" << endl;
  cout << ans1.size() << " ";
  rep(i, ans1.size()) cout << ans1[i] << " ";
  cout << endl;
  cout << ans2.size() << " ";
  rep(i, ans2.size()) cout << ans2[i] << " ";
  cout << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
