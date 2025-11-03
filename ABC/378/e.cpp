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
struct LazySegmentTree
{
private:
  int n;           // 葉の数（2 の冪）
  vector<ll> node; // 各区間の現在の総和
  vector<ll> lazy; // 要素あたりの未反映加算量 Δ

  /* 子へ押し下げる */
  void push(int k, int l, int r)
  {
    if (lazy[k] == 0 || r - l == 1)
      return; // 葉 or 仕事なし
    int m = (l + r) >> 1;
    apply(k << 1, lazy[k], m - l);     // 左子
    apply(k << 1 | 1, lazy[k], r - m); // 右子
    lazy[k] = 0;
  }

  /* ノード k (区間長 len) へ Δ を適用 */
  inline void apply(int k, ll delta, int len)
  {
    node[k] += delta * len; // 総和を更新
    lazy[k] += delta;       // 子・孫への先送り分
  }

public:
  /*--- コンストラクタ ---*/
  LazySegmentTree(const vector<ll> &v)
  {
    int sz = (int)v.size();
    n = 1;
    while (n < sz)
      n <<= 1;
    node.assign(2 * n, 0);
    lazy.assign(2 * n, 0);

    for (int i = 0; i < sz; ++i)
      node[i + n] = v[i];
    for (int i = n - 1; i > 0; --i)
      node[i] = node[i << 1] + node[i << 1 | 1];
  }

  /*--- 区間 [a,b) に +x ---*/
  void add(int a, int b, ll x, int k = 1, int l = 0, int r = -1)
  {
    if (r == -1)
      r = n;
    if (b <= l || r <= a)
      return; // 完全に外
    if (a <= l && r <= b)
    { // 完全に内
      apply(k, x, r - l);
      return;
    }
    push(k, l, r); // 部分的なら子へ
    int m = (l + r) >> 1;
    add(a, b, x, k << 1, l, m);
    add(a, b, x, k << 1 | 1, m, r);
    node[k] = node[k << 1] + node[k << 1 | 1];
  }

  /*--- 区間 [a,b) の総和 ---*/
  ll getsum(int a, int b, int k = 1, int l = 0, int r = -1)
  {
    if (r == -1)
      r = n;
    if (b <= l || r <= a)
      return 0; // 完全に外
    if (a <= l && r <= b)
      return node[k]; // 完全に内
    push(k, l, r);    // 子に潜る前に伝播
    int m = (l + r) >> 1;
    return getsum(a, b, k << 1, l, m) +
           getsum(a, b, k << 1 | 1, m, r);
  }
};
int main()
{
  ll n, m;
  cin >> n >> m;
  vll a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  ll ans = 0;
  vll ini(n);
  LazySegmentTree seg(ini);
  rep(i, n)
  {
    seg.add(0, i + 1, a[i]);
    ll sum = seg.getsum(0, i + 1);
    cout<<sum<<endl;
    sum %= m;
    ans += sum;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
