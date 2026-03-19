#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
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
  ll ma_v;
  ll front, back;
};
S op(S a, S b)
{
  return {
      max(a.ma_v, b.ma_v),
      a.front + b.front,
      a.back + b.back};
}
S e()
{
  return {
      0, 0, 0};
}
struct Act
{
  ll x, flip;
  bool id;
};
S mapping(Act f, S a)
{
  S res = a;
  if (f.id)
  {
    return a;
  }
  if (f.flip)
  {
    res.ma_v = 0;
  }
  if (f.flip % 2)
  {
    swap(res.front, res.back);
  }
  if (res.front > 0)
  {
    res.ma_v += f.x;
  }
  return res;
}
Act composition(Act f, Act g)
{
  if (f.id)
  {
    return g;
  }
  else if (g.id)
  {
    return f;
  }
  Act res = g;
  if (f.flip)
  {
    res.x = f.x;
  }
  else
  {
    res.x += f.x;
  }
  res.flip += f.flip;

  return res;
}
Act id()
{
  return {
      0, 0, true};
}

int main()
{
  ll n, q;
  cin >> n >> q;
  vector<S> ini(n);
  rep(i, n)
  {
    ini[i] = {0, 1, false};
  }
  lazy_segtree<S, op, e, Act, mapping, composition, id> seg(ini);
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll l, r, x;
      cin >> l >> r >> x;
      l--;
      seg.apply(l, r, {x, 0, false});
    }
    else if (t == 2)
    {
      ll l, r;
      cin >> l >> r;
      l--;
      seg.apply(l, r, {0, 1, false});
    }
    else
    {
      ll l, r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l, r).ma_v << endl;
    }
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
