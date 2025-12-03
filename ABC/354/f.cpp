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
  ll t;
  cin >> t;
  rep(T, t)
  {
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll dp(n + 1, INF);
    vll cnt(n, 0);
    rep(i, n)
    {
      auto iter = lower_bound(all(dp), a[i]) - dp.begin();
      dp[iter] = a[i];
      cnt[i] = iter;
    }
    ll len = lower_bound(all(dp), INF) - dp.begin();
    vll ra = a;
    reverse(all(ra));
    rep(i, n)
    {
      ra[i] *= -1;
    }
    vll rdp(n + 1, INF);
    vll back_cnt(n, 0);
    rep(i, n)
    {
      auto iter = lower_bound(all(rdp), ra[i]) - rdp.begin();
      rdp[iter] = ra[i];
      back_cnt[n - i - 1] = iter;
    }
    vll ans(0);
    rep(i, n)
    {
      if (cnt[i] + back_cnt[i] + 1 == len)
      {
        ans.pb(i + 1);
      }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    printArray(ans);
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
