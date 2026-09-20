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
const ll MOD = 998244353LL;
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
/*
 * IntervalSet
 *
 * 整数の半開区間 [l, r) の集合を管理する。
 * 重複または隣接する区間は自動的にマージする。
 *
 * 例:
 *   [1,3) + [3,5) -> [1,5)
 *   [1,3) + [4,6) -> [1,3), [4,6)
 *
 * 常に、保持されている区間同士は
 * 「重複せず、隣接もしない」状態になる。
 *
 * insert(l, r)
 *   [l,r) を追加する。
 *   重複・隣接区間は自動でマージする。
 *
 * insert(x)
 *   整数 x を表す区間 [x,x+1) を追加する。
 *
 * contains(x)
 *   x がいずれかの区間に含まれるか。
 *
 * intersects(l, r)
 *   [l,r) が、いずれかの区間と交差するか。
 *   端点が接するだけなら交差とはみなさない。
 *
 * next_free(x)
 *   x 以上で、どの区間にも含まれない最小の整数を返す。
 *
 * size()
 *   現在保持している区間数。
 */
struct IntervalSet
{
  set<pair<ll, ll>> st;

  // 半開区間 [l, r) を追加
  void insert(ll l, ll r)
  {
    if (l >= r)
      return;

    auto it = st.lower_bound({l, -INF});

    // 左隣と重複・隣接している可能性
    if (it != st.begin())
    {
      auto pre = prev(it);

      // [a,b) と [l,r) が重複または隣接
      // b >= l ならマージ可能
      if (pre->second >= l)
        it = pre;
    }

    // 重複・隣接する区間をすべて吸収
    while (it != st.end() && it->first <= r)
    {
      l = min(l, it->first);
      r = max(r, it->second);

      it = st.erase(it);
    }

    st.insert({l, r});
  }

  // 整数 x を追加
  // x は半開区間 [x, x+1) として表現
  void insert(ll x)
  {
    insert(x, x + 1);
  }

  // x がいずれかの区間に含まれるか
  bool contains(ll x) const
  {
    auto it = st.upper_bound({x, INF});

    if (it == st.begin())
      return false;

    --it;

    return it->first <= x && x < it->second;
  }

  // 半開区間 [l,r) が、いずれかの区間と交差するか
  bool intersects(ll l, ll r) const
  {
    if (l >= r)
      return false;

    auto it = st.lower_bound({l, -INF});

    // l 以上から始まる最初の区間
    // [a,b) と [l,r) が交差する条件は a < r
    if (it != st.end() && it->first < r)
      return true;

    // l より左から始まる区間が l を越えていれば交差
    if (it != st.begin())
    {
      auto pre = prev(it);

      if (pre->second > l)
        return true;
    }

    return false;
  }

  // x 以上で最初の未使用整数を返す
  ll next_free(ll x) const
  {
    auto it = st.upper_bound({x, INF});

    if (it != st.begin())
    {
      auto pre = prev(it);

      if (pre->first <= x && x < pre->second)
        return pre->second;
    }

    return x;
  }

  // 管理中の区間数
  ll size() const
  {
    return st.size();
  }

  bool empty() const
  {
    return st.empty();
  }
};
int main()
{
  ll t;
  cin >> t;
  rep(T, t)
  {
    IntervalSet s;

    ll n;
    cin >> n;
    vector<pll> p(n);
    rep(i, n)
    {
      cin >> p[i].S >> p[i].F;
    }
    sort(all(p));
    bool ok = true;
    rep(i, n)
    {
      auto [r, l] = p[i];
      ll nx = s.next_free(l);
      if (nx > r || nx > 1e9)
      {
        ok = false;
        break;
      }
      s.insert(nx);
    }
    if (ok)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
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
__builtin_popcount(i)*/
