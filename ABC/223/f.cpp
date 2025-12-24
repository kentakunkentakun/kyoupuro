#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#include <atcoder/segtree>
using namespace atcoder;
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
ll op(ll a, ll b)
{
  return min(a, b);
}
ll e()
{
  return INF;
}
struct Act
{
  ll a;
};
ll mapping(Act a, ll b)
{
  return b + a.a;
}
Act composition(Act a, Act b)
{
  return {a.a + b.a};
}
Act id()
{
  return {0};
}

ll op2(ll a, ll b)
{
  return a + b;
}
ll e2()
{
  return 0;
}

int main()
{
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vll ini(n, 0);
  vll inisum(n, 0);
  rep(i, n)
  {
    if (s[i] == '(')
    {
      ini[i]++;
      inisum[i]++;
    }
    else
    {
      ini[i]--;
      inisum[i]--;
    }
    if (i > 0)
    {
      ini[i] += ini[i - 1];
    }
  }
  lazy_segtree<ll, op, e, Act, mapping, composition, id> seg(ini);
  segtree<ll, op2, e2> seg_sum(inisum);
  vector<string> ans(0);
  rep(i, q)
  {
    ll t;
    cin >> t;
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    if (t == 1)
    {
      if (s[l] == s[r])
        continue;
      else if (s[l] == '(')
      {
        seg.apply(l, r, {-2});
        seg_sum.set(l, -1);
        seg_sum.set(r, 1);
      }
      else
      {
        seg.apply(l, r, {2});
        seg_sum.set(l, 1);
        seg_sum.set(r, -1);
      }
      swap(s[l], s[r]);
    }
    else
    {
      ll left = 0;
      if (l >= 1)
      {
        left = seg_sum.prod(0, l);
      }
      ll v = seg.prod(l, r + 1);
      ll sum = seg_sum.prod(l, r + 1);
      if (v - left >= 0 && sum == 0)
      {
        ans.pb("Yes");
      }
      else
      {
        ans.pb("No");
      }
    }
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
__builtin_popcount(i)*/
