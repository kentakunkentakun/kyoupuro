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
int main()
{
  ll n, q;
  cin >> n >> q;
  vll a(n);
  rep(i, n) cin >> a[i];
  vll l(q), r(q);
  rep(i, q)
  {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  ll s = sqrt(q);
  ll k = (n + s - 1) / s;
  vector<vector<tuple<ll, ll, ll>>> t((n + k - 1) / k, vector<tuple<ll, ll, ll>>(0));
  rep(i, q)
  {
    t[r[i] / k].pb({l[i], r[i], i});
  }
  rep(i, t.size())
  {
    sort(all(t[i]));
    if (i % 2)
    {
      reverse(all(t[i]));
    }
  }
  vll ans(q);
  ll res = 0;
  vll m(2 * 100000 + 5, 0);
  tuple<ll, ll, ll> now = {0, -1, -1};
  rep(i, t.size())
  {
    rep(j, t[i].size())
    {
      auto [prevl, prevr, _] = now;
      auto [nowl, nowr, it] = t[i][j];
      bool p = true;
      if (nowr < prevr)
      {
        p = false;
      }
      while (nowr != prevr)
      {
        if (p)
        {
          prevr++;
          if (m[a[prevr]] >= 2)
          {
            res += m[a[prevr]] * (m[a[prevr]] - 1) / 2;
          }
          m[a[prevr]]++;
        }
        else
        {
          if (prevr >= 0)
            m[a[prevr]]--;
          if (m[a[prevr]] >= 2)
          {
            res -= m[a[prevr]] * (m[a[prevr]] - 1) / 2;
          }
          prevr--;
        }
      }
      p = true;
      if (nowl > prevl)
      {
        p = false;
      }
      while (prevl != nowl)
      {
        if (p)
        {
          prevl--;
          if (m[a[prevl]] >= 2)
          {
            res += m[a[prevl]] * (m[a[prevl]] - 1) / 2;
          }
          m[a[prevl]]++;
        }
        else
        {
          if (prevl >= 0)
            m[a[prevl]]--;
          if (prevl >= 0 && m[a[prevl]] >= 2)
          {
            res -= m[a[prevl]] * (m[a[prevl]] - 1) / 2;
          }
          prevl++;
        }
      }
      ans[it] = res;
      now = t[i][j];
    }
  }
  rep(i, q)
  {
    cout << ans[i] << endl;
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
