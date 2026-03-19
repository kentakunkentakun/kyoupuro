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
  ll n, k;
  cin >> n >> k;
  n++;
  vll t(n), y(n);
  vll s(0);
  rep(i, n)
  {
    if (i == n - 1)
      break;
    cin >> t[i + 1] >> y[i + 1];
  }
  t[0] = 1;
  y[0] = 0;
  repR(i, n)
  {
    if (t[i] == 1)
    {
      s.pb(i);
    }
    if (s.size() == k + 1)
      break;
  }
  reverse(all(s));
  set<pll> se;
  ll sum = 0;
  repR(i, n)
  {
    if (t[i] == 2)
    {
      sum += y[i];
      se.insert({y[i], i});
    }
    if (i == s[0])
      break;
  }
  ll ans = -INF;
  ll p = k - s.size() + 1;
  rep(i, s.size())
  {
    while (p)
    {
      pll it = *se.begin();
      if (it.F > 0)
        break;
      sum -= it.first;
      se.erase(it);
      p--;
    }
    chmax(ans, y[s[i]] + sum);
    p++;
    if (i < s.size() - 1)
    {
      for (int j = s[i] + 1; j < s[i + 1]; j++)
      {
        if (t[j] == 2 && !se.count({y[j], j}))
        {
          p++;
        }
        if (t[j] == 2 && se.count({y[j], j}))
        {
          sum -= y[j];
          se.erase({y[j], j});
        }
      }
    }
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
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
