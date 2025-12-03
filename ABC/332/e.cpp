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
const double INF_D = numeric_limits<double>::infinity();
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
  cout << fixed << setprecision(10);

  ll n, d;
  cin >> n >> d;
  vector<double> w(n);
  rep(i, n) cin >> w[i];
  double mid = 0.0;
  rep(i, n)
  {
    mid += w[i];
  }
  mid /= d;
  vector<double> t(1 << n, 0);
  rep(i, 1 << n)
  {
    rep(j, n)
    {
      if ((i >> j) & 1)
      {
        t[i] += w[j];
      }
    }
    t[i] = (t[i] - mid) * (t[i] - mid);
  }

  vector<vector<double>> dp(d + 1, vector<double>(1 << n, INF_D));
  dp[0][0] = 0.0;
  rep(i, d)
  {
    rep(bit, 1 << n)
    {
      for (ll b = bit; b > 0; b = (b - 1) & bit)
      {
        chmin(dp[i + 1][bit], dp[i][bit - b] + t[b]);
      }
    }
  }
  cout << dp[d][(1 << n) - 1] / (double)d << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
