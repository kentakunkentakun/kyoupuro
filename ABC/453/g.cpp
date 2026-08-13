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
template <class S, S (*op)(S, S), S (*e)()>
struct PersistentSegTree
{
  struct Node
  {
    S val;
    int left, right;
    Node(S val = e(), int left = -1, int right = -1)
        : val(val), left(left), right(right) {}
  };

  int n, root;
  vector<Node> nodes;

  PersistentSegTree() {}
  PersistentSegTree(const vector<S> &v)
  {
    int sz = (int)v.size();
    n = 1;
    while (n < sz)
      n <<= 1;
    nodes.reserve(4 * n);
    root = build(v, 0, n);
  }

  int new_node(const Node &node)
  {
    nodes.push_back(node);
    return (int)nodes.size() - 1;
  }

  int build(const vector<S> &v, int l, int r)
  {
    if (r - l == 1)
    {
      if (l < (int)v.size())
        return new_node(Node(v[l]));
      else
        return new_node(Node(e()));
    }
    int m = (l + r) / 2;
    int lc = build(v, l, m);
    int rc = build(v, m, r);
    return new_node(Node(op(nodes[lc].val, nodes[rc].val), lc, rc));
  }

  int set(int root, int p, S x)
  {
    return set_rec(root, p, x, 0, n);
  }

  int set_rec(int k, int p, S x, int l, int r)
  {
    if (r - l == 1)
    {
      return new_node(Node(x));
    }

    int m = (l + r) / 2;
    int lc = nodes[k].left;
    int rc = nodes[k].right;

    if (p < m)
    {
      lc = set_rec(lc, p, x, l, m);
    }
    else
    {
      rc = set_rec(rc, p, x, m, r);
    }

    return new_node(Node(op(nodes[lc].val, nodes[rc].val), lc, rc));
  }

  S prod(int root, int ql, int qr)
  {
    return prod_rec(root, ql, qr, 0, n);
  }

  S prod_rec(int k, int ql, int qr, int l, int r)
  {
    if (qr <= l || r <= ql)
      return e();
    if (ql <= l && r <= qr)
      return nodes[k].val;

    int m = (l + r) / 2;
    S vl = prod_rec(nodes[k].left, ql, qr, l, m);
    S vr = prod_rec(nodes[k].right, ql, qr, m, r);
    return op(vl, vr);
  }

  S get(int root, int p)
  {
    return prod(root, p, p + 1);
  }
};
ll op(ll a, ll b)
{
  return a + b;
}
ll e()
{
  return 0;
}
int main()
{
  ll n, m, q;
  cin >> n >> m >> q;
  vll ini(m, 0);
  PersistentSegTree<ll, op, e> seg(ini);
  vll k(n, seg.root);
  rep(i, q)
  {
    ll Q;
    cin >> Q;
    if (Q == 1)
    {
      ll x, y;
      cin >> x >> y;
      x--;
      y--;
      k[x] = k[y];
    }
    else if (Q == 2)
    {
      ll x, y, z;
      cin >> x >> y >> z;
      x--;
      y--;
      k[x] = seg.set(k[x], y, z);
    }
    else
    {
      ll x, l, r;
      cin >> x >> l >> r;
      x--;
      l--;
      cout << seg.prod(k[x], l, r) << endl;
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
