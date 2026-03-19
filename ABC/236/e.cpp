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
  // ave
  {
    auto judge = [&](double wj) -> bool
    {
      vector<vector<double>> dp(n + 1, vector<double>(2, -INF));
      dp[0][0] = 0;
      rep(i, n)
      {
        chmax(dp[i + 1][0], dp[i][0] + a[i] - wj);
        chmax(dp[i + 1][0], dp[i][1] + a[i] - wj);
        chmax(dp[i + 1][1], dp[i][0]);
      }
      if (dp[n][0] >= 0 || dp[n][1] >= 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    };
    double ac = 0, wa = INF;
    rep(T, 75)
    {
      double mid = (ac + wa) / 2;
      if (judge(mid))
      {
        ac = mid;
      }
      else
      {
        wa = mid;
      }
    }
    cout << fixed << setprecision(10);

    cout << ac << endl;
  }
  // mid
  {
    auto judge = [&](ll wj) -> bool
    {
      ll up = 0, down = 0;
      bool skip = false;
      rep(i, n)
      {
        if (a[i] >= wj)
        {
          skip = false;
          up++;
        }
        else if (skip)
        {
          skip = false;
          down++;
        }
        else
        {
          skip = true;
        }
      }
      if (up > down)
      {
        return true;
      }
      else
      {
        return false;
      }
    };
    ll ac = 0, wa = INF;
    while (ac + 1 < wa)
    {
      ll mid = (ac + wa) / 2;
      if (judge(mid))
      {
        ac = mid;
      }
      else
      {
        wa = mid;
      }
    }
    cout << ac << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
