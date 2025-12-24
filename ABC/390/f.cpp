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
  return {a.cnt, a.v + f * a.cnt};
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
  ll n;
  cin >> n;
  vll a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  vvll t(n + 1, vll(0));
  rep(i, n)
  {
    a[i]--;
    t[a[i]].pb(i);
  }
  lazy_segtree<S, op, e, ll, mapping, composition, id> seg(n);
  rep(i, n)
  {
    ll last = -1;
    // tの中でのiter
    ll last_it = lower_bound(all(t[a[i]]), i) - t[a[i]].begin() - 1;
    if (last_it >= 0)
    {
      last = t[a[i]][last_it];
    }
    ll mi = -1, ma = -1;
    ll mi_it = 0;
    if (a[i] != 0 && t[a[i] - 1].size() > 0)
    {
      mi_it = lower_bound(all(t[a[i] - 1]), i) - t[a[i] - 1].begin() - 1;
      if (mi_it >= 0)
      {
        mi = t[a[i] - 1][mi_it];
        if (i < mi || mi < last)
        {
          mi = -1;
        }
      }
    }
    if (a[i] != n - 1 && t[a[i] + 1].size() > 0)
    {
      ll ma_it = lower_bound(all(t[a[i] + 1]), i) - t[a[i] + 1].begin() - 1;
      if (ma_it >= 0)
      {
        ma = t[a[i] + 1][ma_it];
        if (i < ma || ma < last)
        {
          ma = -1;
        }
      }
    }
    if (mi != -1 && ma != -1)
    {
      if (mi > ma)
      {
        swap(mi, ma);
      }
      seg.apply(ma + 1, i + 1, 1);
      seg.apply(last + 1, mi + 1, -1);
    }
    else if (mi != -1 || ma != -1)
    {
      ll it = 0;
      if (mi != -1)
        it = mi;
      else
        it = ma;
      seg.apply(it + 1, i + 1, 1);
    }
    else
    {
      seg.apply(last + 1, i + 1, 1);
    }

    ans += seg.prod(0, i + 1).v;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
