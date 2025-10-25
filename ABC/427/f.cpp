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
  ll n, m;
  cin >> n >> m;
  vll a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  vll r(n / 2);
  vll l((n + 1) / 2);
  rep(i, (n + 1) / 2)
  {
    l[i] = a[i];
  }
  rep(i, (n / 2))
  {
    r[i] = a[i + (n + 1) / 2];
  }
  reverse(all(r));
  vector<unordered_map<ll, ll>> ldp(2);
  vector<unordered_map<ll, ll>> rdp(2);
  ldp[0][0] = 1;
  rdp[0][0] = 1;
  auto solve = [&](vector<unordered_map<ll, ll>> &dp, vll &k)
  {
    ll n = k.size();
    rep(i, n)
    {
      vector<unordered_map<ll, ll>> old(2);
      swap(old, dp);
      for (auto [v, cnt] : old[0])
      {
        ll nx = (v + k[i]) % m;
        dp[1][nx] += cnt;
        dp[0][v] += cnt;
      }
      for (auto [v, cnt] : old[1])
      {
        dp[0][v] += cnt;
      }
    }
  };
  solve(ldp, l);
  solve(rdp, r);
  ll ans = 0;
  for (auto [v, cnt] : ldp[0])
  {
    ll p = 2 * m - v;
    p %= m;
    ans += cnt * (rdp[0][p] + rdp[1][p]);
  }
  for (auto [v, cnt] : ldp[1])
  {
    ll p = 2 * m - v;
    p %= m;
    ans += cnt * (rdp[0][p]);
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
