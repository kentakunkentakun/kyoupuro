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
struct S
{
  ll it, v;
  bool empty;
};
S op(S a, S b)
{
  if (a.empty)
  {
    return b;
  }
  else if (b.empty)
  {
    return a;
  }
  if (a.v && b.v)
  {
    return b;
  }
  else if (a.v)
  {
    return a;
  }
  else if (b.v)
  {
    return b;
  }
  return a;
}
S e()
{
  return {
      0, 0, true};
}
int main()
{
  string s;
  cin >> s;
  vvll t(3, vll(0));
  ll n = s.size();
  vector<S> aa(n);
  vector<S> bb(n);
  vector<S> cc(n);
  rep(i, n)
  {
    aa[i] = {i, 0, false};
    bb[i] = {i, 0, false};
    cc[i] = {i, 0, false};
    if (s[i] == 'A')
    {
      aa[i] = {i, 1, false};
    }
    else if (s[i] == 'B')
    {
      bb[i] = {i, 1, false};
    }
    else
    {
      cc[i] = {i, 1, false};
    }
  }
  segtree<S, op, e> a(aa);
  segtree<S, op, e> b(bb);
  segtree<S, op, e> c(cc);

  ll ans = 0;
  while (1)
  {
    S c_ma = c.prod(0, n);

    if (c_ma.v == 0)
      break;
    c_ma.v = 0;
    c.set(c_ma.it, c_ma);
    S b_ma = b.prod(0, c_ma.it);
    if (b_ma.v == 0)
    {
      break;
    }
    b_ma.v = 0;
    b.set(b_ma.it, b_ma);

    S a_ma = a.prod(0, b_ma.it);
    if (a_ma.v == 0)
      break;

    a_ma.v = 0;
    a.set(a_ma.it, a_ma);

    ans++;
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
