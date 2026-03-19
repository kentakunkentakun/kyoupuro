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
using i128 = __int128_t;

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
  ll n, k;
  cin >> n >> k;
  vll a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(all(a));
  sort(all(b));
  sort(all(c));
  set<tuple<i128, ll, ll, ll>> s;
  s.insert({(i128)a[n - 1] * (b[n - 1] + c[n - 1]) + (i128)b[n - 1] * c[n - 1], n - 1, n - 1, n - 1});
  ll ans = 0;
  rep(i, k)
  {
    auto [sum, ai, bi, ci] = *s.rbegin();
    s.erase({sum, ai, bi, ci});
    if (ai > 0)
    {
      s.insert({sum - (i128)a[ai] * (b[bi] + c[ci]) + (i128)a[ai - 1] * (b[bi] + c[ci]), ai - 1, bi, ci});
    }
    if (bi > 0)
    {
      s.insert({sum - (i128)b[bi] * (a[ai] + c[ci]) + (i128)b[bi - 1] * (a[ai] + c[ci]), ai, bi - 1, ci});
    }
    if (ci > 0)
    {
      s.insert({sum - (i128)c[ci] * (a[ai] + b[bi]) + (i128)c[ci - 1] * (a[ai] + b[bi]), ai, bi, ci - 1});
    }
    ans = sum;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())
  auto min3 = [&](ll x, ll y, ll z) ->
  {
    return min(x, min(y, z));
  };

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
