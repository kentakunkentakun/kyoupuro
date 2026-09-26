#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define ul unsigned long long
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

template <class T>
using PQ = priority_queue<T>;

template <class T>
using PQR = priority_queue<T, vector<T>, greater<T>>;

// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 62;
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

template <
    class S, S (*op)(S, S), S (*e)(),
    class F, S (*mapping)(F, S),
    F (*composition)(F, F), F (*id)()>
struct PersistentLazySegTree
{
  struct Node
  {
    S val;
    F lazy;
    int left, right;
    bool has_lazy;

    Node(S val = e(), int left = -1, int right = -1)
        : val(val), lazy(id()), left(left), right(right), has_lazy(false) {}
  };

  int n, size;
  int root; // 初期状態の根。更新しても、この値は変わらない
  vector<Node> nodes;

  PersistentLazySegTree() : PersistentLazySegTree(0) {}

  explicit PersistentLazySegTree(int n)
      : PersistentLazySegTree(vector<S>(n, e())) {}

  explicit PersistentLazySegTree(const vector<S> &v)
      : n((int)v.size()), size(1)
  {
    while (size < n)
      size <<= 1;

    nodes.reserve((size_t)size * 2);
    root = build(v, 0, size);
  }

  // 指定した状態の a[p] を x に変更した、新しい根を返す
  int set(int root, int p, S x)
  {
    assert(0 <= p && p < n);
    return set_rec(root, p, x, 0, size);
  }

  // 指定した状態の [l, r) に f を作用させた、新しい根を返す
  int apply(int root, int l, int r, F f)
  {
    assert(0 <= l && l <= r && r <= n);
    if (l == r)
      return root;

    return apply_rec(root, l, r, f, 0, size);
  }

  // 1点に作用
  int apply(int root, int p, F f)
  {
    assert(0 <= p && p < n);
    return apply(root, p, p + 1, f);
  }

  // 指定した状態の [l, r) の集約値
  S prod(int root, int l, int r) const
  {
    assert(0 <= l && l <= r && r <= n);
    if (l == r)
      return e();

    return prod_rec(root, l, r, 0, size, id());
  }

  S get(int root, int p) const
  {
    assert(0 <= p && p < n);
    return prod(root, p, p + 1);
  }

  S all_prod(int root) const
  {
    return nodes[root].val;
  }

private:
  int new_node(Node node)
  {
    nodes.push_back(node);
    return (int)nodes.size() - 1;
  }

  int clone(int k)
  {
    return new_node(nodes[k]);
  }

  int build(const vector<S> &v, int l, int r)
  {
    if (r - l == 1)
      return new_node(Node(l < n ? v[l] : e()));

    int m = (l + r) / 2;
    int lc = build(v, l, m);
    int rc = build(v, m, r);

    return new_node(Node(op(nodes[lc].val, nodes[rc].val), lc, rc));
  }

  void pull(int k)
  {
    nodes[k].val = op(
        nodes[nodes[k].left].val,
        nodes[nodes[k].right].val);
  }

  // コピー済みのノードにだけ適用する
  void all_apply(int k, F f)
  {
    nodes[k].val = mapping(f, nodes[k].val);

    if (nodes[k].left != -1)
    {
      // composition(f, g) は「g の後に f」
      nodes[k].lazy = composition(f, nodes[k].lazy);
      nodes[k].has_lazy = true;
    }
  }

  void push(int k)
  {
    if (!nodes[k].has_lazy)
      return;

    F f = nodes[k].lazy;

    int lc = clone(nodes[k].left);
    int rc = clone(nodes[k].right);

    all_apply(lc, f);
    all_apply(rc, f);

    nodes[k].left = lc;
    nodes[k].right = rc;
    nodes[k].lazy = id();
    nodes[k].has_lazy = false;
  }

  int set_rec(int k, int p, S x, int l, int r)
  {
    k = clone(k);

    if (r - l == 1)
    {
      nodes[k].val = x;
      return k;
    }

    push(k);

    int m = (l + r) / 2;
    int lc = nodes[k].left;
    int rc = nodes[k].right;

    if (p < m)
      lc = set_rec(lc, p, x, l, m);
    else
      rc = set_rec(rc, p, x, m, r);

    nodes[k].left = lc;
    nodes[k].right = rc;
    pull(k);

    return k;
  }

  int apply_rec(
      int k, int ql, int qr, F f, int l, int r,
      bool copied = false)
  {
    if (qr <= l || r <= ql)
      return k;

    // 親のpush()でコピー済みなら、再度コピーしない
    if (!copied)
      k = clone(k);

    if (ql <= l && r <= qr)
    {
      all_apply(k, f);
      return k;
    }

    // push()が両方の子をコピーするか記録
    bool pushed = nodes[k].has_lazy;
    push(k);

    int m = (l + r) / 2;

    int lc = apply_rec(
        nodes[k].left, ql, qr, f, l, m, pushed);
    int rc = apply_rec(
        nodes[k].right, ql, qr, f, m, r, pushed);

    nodes[k].left = lc;
    nodes[k].right = rc;
    pull(k);

    return k;
  }

  S prod_rec(int k, int ql, int qr, int l, int r, F acc) const
  {
    if (qr <= l || r <= ql)
      return e();

    if (ql <= l && r <= qr)
      return mapping(acc, nodes[k].val);

    // 子には「このノードの遅延値 → 祖先の遅延値」の順に作用
    acc = composition(acc, nodes[k].lazy);

    int m = (l + r) / 2;
    S vl = prod_rec(nodes[k].left, ql, qr, l, m, acc);
    S vr = prod_rec(nodes[k].right, ql, qr, m, r, acc);

    return op(vl, vr);
  }
};
struct S
{
  ll cnt, v;
};
S op(S a, S b)
{
  return {a.cnt + b.cnt, a.v + b.v};
}
S e()
{
  return {1, 0};
}
S mapping(ll f, S a)
{
  return {a.cnt, a.cnt * f + a.v};
}
ll composition(ll f, ll g)
{
  return f + g;
}
ll id()
{
  return 0;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, q;
  cin >> n >> m >> q;
  vll l(n), r(n);
  rep(i, n)
  {
    cin >> l[i] >> r[i];
    l[i]--;
  }
  vector<tuple<ll, ll, ll, ll, ll>> que(q);
  rep(i, q)
  {
    ll a, b, c, d;

    cin >> a >> b >> c >> d;

    c--;
    d--;
    que[i] = {b, a, c, d, i};
  }
  vll ans(q);
  sort(all(que));
  vll root(n + 1);
  PersistentLazySegTree<S, op, e, ll, mapping, composition, id> seg(m);
  root[0] = seg.root;
  rep(i, n)
  {
    root[i + 1] = seg.apply(root[i], l[i], r[i], 1);
  }
  rep(i, q)
  {
    auto [b, a, c, d, it] = que[i];
    ans[it] = seg.prod(root[b], c, d + 1).v - seg.prod(root[a - 1], c, d + 1).v;
  }
  rep(i, ans.size())
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
