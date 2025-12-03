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
// const ll MOD = 1000000007LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct LazySegmentTree
{
private:
  int n;           // 葉の数（2 の冪）
  vector<ll> node; // 各区間の最小値
  vector<ll> lazy; // 区間一括代入値（未反映なら INF）

  /* ノード k へ「区間を x にする」更新を適用 */
  inline void apply(int k, ll x)
  {
    node[k] = x;
    lazy[k] = x;
  }

  /* 子へ押し下げる */
  void push(int k)
  {
    if (lazy[k] == INF || k >= n)
      return;                   // 仕事なし or 葉
    apply(k << 1, lazy[k]);     // 左子
    apply(k << 1 | 1, lazy[k]); // 右子
    lazy[k] = INF;
  }

public:
  /*--- コンストラクタ ---*/
  LazySegmentTree(const vector<ll> &v)
  {
    int sz = (int)v.size();
    n = 1;
    while (n < sz)
      n <<= 1;
    node.assign(2 * n, INF);
    lazy.assign(2 * n, INF);

    for (int i = 0; i < sz; ++i)
      node[i + n] = v[i];
    for (int i = n - 1; i > 0; --i)
      node[i] = min(node[i << 1], node[i << 1 | 1]);
  }

  /*--- 区間 [a,b) を x に代入 ---*/
  void assign(int a, int b, ll x, int k = 1, int l = 0, int r = -1)
  {
    if (r == -1)
      r = n;
    if (b <= l || r <= a)
      return; // 完全に外

    if (a <= l && r <= b)
    { // 完全に内
      apply(k, x);
      return;
    }

    push(k); // 部分的なら子へ
    int m = (l + r) >> 1;
    assign(a, b, x, k << 1, l, m);
    assign(a, b, x, k << 1 | 1, m, r);
    node[k] = min(node[k << 1], node[k << 1 | 1]);
  }

  /*--- 区間 [a,b) の最小値 ---*/
  ll getmin(int a, int b, int k = 1, int l = 0, int r = -1)
  {
    if (r == -1)
      r = n;
    if (b <= l || r <= a)
      return INF; // 完全に外
    if (a <= l && r <= b)
      return node[k]; // 完全に内

    push(k); // 子に潜る前に伝播
    int m = (l + r) >> 1;
    return min(getmin(a, b, k << 1, l, m),
               getmin(a, b, k << 1 | 1, m, r));
  }
};

int main()
{
  ll n, q;
  cin >> n >> q;
  vll tmp(n - 2, n - 2);
  LazySegmentTree seg1(tmp);
  LazySegmentTree seg2(tmp);
  ll ans = (n - 2) * (n - 2);
  ll min_1 = n - 1;
  ll min_2 = n - 1;
  rep(i, q)
  {
    ll t, x;
    cin >> t >> x;
    x -= 2;
    if (t == 1)
    {
      ll c = seg1.getmin(x, x + 1);
      ans -= c;
      if (chmin(min_1, x))
      {
        seg2.assign(0, c + 1, min_1);
      }
    }
    else
    {
      ll c = seg2.getmin(x, x + 1);
      ans -= c;
      if (chmin(min_2, x))
      {
        seg1.assign(0, c + 1, min_2);
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
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
