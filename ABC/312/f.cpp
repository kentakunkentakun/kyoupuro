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
  ll n, m;
  cin >> n >> m;
  vll t0(0), x0(0);
  vll t1(0), x1(0);
  vll t2(0), x2(0);
  ll ans = 0;

  rep(i, n)
  {
    ll t, x;
    cin >> t >> x;
    if (t == 0)
    {
      x0.pb(x);
    }
    else if (t == 1)
    {
      x1.pb(x);
    }
    else
    {
      x2.pb(x);
    }
  }
  sort(rall(x0));
  sort(rall(x1));
  sort(rall(x2));
  t0.pb(0);
  t1.pb(0);
  t2.pb(0);
  rep(i, x0.size())
  {
    t0.pb(t0[i] + x0[i]);
  }
  rep(i, x1.size())
  {
    t1.pb(t1[i] + x1[i]);
  }
  rep(i, x2.size())
  {
    t2.pb(t2[i] + x2[i]);
  }
  rep(i, x1.size() + 1)
  {
    ll kiri_cnt = lower_bound(all(t2), i) - t2.begin();
    if (kiri_cnt == t2.size())
    {
      break;
    }
    ll x0_cnt = min(m - kiri_cnt - i, (ll)x0.size());
    if (x0_cnt < 0)
    {
      continue;
    }
    chmax(ans, t1[i] + t0[x0_cnt]);
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
