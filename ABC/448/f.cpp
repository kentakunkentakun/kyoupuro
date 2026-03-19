#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
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
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
const double INF_D = numeric_limits<double>::infinity();
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct Mo
{
  ll n;
  vector<pair<ll, ll>> qs;
  Mo(ll n) : n(n) {}
  void add_query(ll l, ll r) { qs.push_back({l, r}); } // [l, r)

  vector<ll> build()
  {
    ll q = qs.size();
    ll bs = max(1LL, (ll)(2 * 1e7 / max(1.0, sqrt((double)n))));
    vector<ll> ord(q);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](ll a, ll b)
         {
            auto [l1, r1] = qs[a];
            auto [l2, r2] = qs[b];
            ll b1 = l1 / bs, b2 = l2 / bs;
            if (b1 != b2) return b1 < b2;
            return (b1 & 1) ? (r1 > r2) : (r1 < r2); });
    return ord;
  }
};
int main()
{
  ll n;
  cin >> n;
  vll l(n), r(n);
  Mo mo = Mo(n);
  rep(i, n)
  {
    cin >> l[i] >> r[i];
    mo.add_query(l[i], r[i]);
  }
  vll ord = mo.build();
  ll s = 0;
  rep(i, ord.size())
  {
    if (ord[i] == 0)
    {
      s = i;
      break;
    }
  }
  for (int i = s; i < n; i++)
  {
    cout << ord[i] + 1 << " ";
  }
  for (int i = 0; i < s; i++)
  {
    cout << ord[i] + 1 << " ";
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
