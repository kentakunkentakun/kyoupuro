#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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
  ll n;
  cin >> n;
  vll p(n);
  ll k = 0;
  vll t(n);
  rep(i, n)
  {
    cin >> p[i];
    t[p[i] - 1] = i;
    if (p[i] == n)
    {
      k = i;
    }
  }
  set<ll> s;
  s.insert(k);
  ll ans = 0;
  repR(j, n - 1)
  {
    ll i = t[j];
    auto it = s.lower_bound(i);
    ll left, right = 0;
    if (it == s.end())
    {
      right = n - i;
      it--;
      if (it == s.begin())
      {
        left = *it + 1;
      }
      else
      {
        ll tmp = *it;
        it--;
        left = tmp - *it;
      }
      ans += left * right * p[i];
    }
    else if (it == s.begin())
    {
      left = i + 1;
      ll tmp = *it;
      it++;
      if (it == s.end())
      {
        right = n - tmp;
      }
      else
      {
        right = *it - tmp;
      }
      ans += left * right * p[i];
    }
    else
    {
      auto rit = it;
      auto lit = it;
      lit--;
      if (lit == s.begin())
      {
        left = *lit + 1;
      }
      else
      {
        ll tmp = *lit;
        lit--;
        left = tmp - *lit;
        lit++;
      }
      ans += left * (*rit - i) * p[i];
      ll tmp = *rit;
      rit++;
      if (rit == s.end())
      {
        right = n - tmp;
      }
      else
      {
        right = *rit - tmp;
      }
      ans += right * (i - *lit) * p[i];
    }
    s.insert(i);
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
