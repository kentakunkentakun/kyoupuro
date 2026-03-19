#include <bits/stdc++.h>
#include <atcoder/segtree>
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
  vector<pll> p;
};
S op(S a, S b)
{
  vector<pll> tmp(0);
  rep(i, a.p.size())
  {
    tmp.pb(a.p[i]);
  }
  rep(i, b.p.size())
  {
    tmp.pb(b.p[i]);
  }
  vector<pll> res(0);
  sort(all(tmp));
  rep(i, min((int)tmp.size(), 2))
  {
    res.pb(tmp[i]);
  }
  return {res};
}
S e()
{
  vector<pll> a(0);
  a.pb({INF, -1});
  return {a};
}
int main()
{
  ll n;
  cin >> n;
  vector<tuple<ll, ll, ll, ll>> t(0);
  set<ll> s;
  vll h(n), w(n), d(n);
  rep(i, n)
  {
    cin >> h[i] >> w[i] >> d[i];
    s.insert(h[i]);
    s.insert(w[i]);
    s.insert(d[i]);
  }
  map<ll, ll> iter;
  ll it = 0;
  for (auto p : s)
  {
    iter[p] = it;
    it++;
  }
  rep(i, n)
  {
    h[i] = iter[h[i]];
    w[i] = iter[w[i]];
    d[i] = iter[d[i]];
  }
  rep(i, n)
  {
    vll a(0);
    a.pb(h[i]);
    a.pb(w[i]);
    a.pb(d[i]);
    sort(all(a));
    t.pb({a[0], a[1], a[2], i});
  }
  sort(all(t));
  segtree<S, op, e> seg(it);
  vector<tuple<ll, ll, ll, ll>> tmp(0);
  rep(i, t.size())
  {
    auto [a, b, c, ii] = t[i];
    vector<pll> p = seg.prod(0, b).p;
    rep(j, p.size())
    {
      if (p[j].F < c && p[j].S != ii)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    tmp.pb({a, b, c, ii});
    if (i < t.size() - 1)
    {
      auto [aa, _, __, ___] = t[i + 1];
      if (aa == a)
      {
        continue;
      }
    }
    rep(j, tmp.size())
    {
      auto [aa, bb, cc, iii] = tmp[j];
      vector<pll> p = seg.get(bb).p;
      p.pb({cc, iii});
      sort(all(p));
      if (p.size() > 2)
      {
        p.pop_back();
      }
      seg.set(bb, {p});
    }
    tmp = {};
  }
  cout << "No" << endl;
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
