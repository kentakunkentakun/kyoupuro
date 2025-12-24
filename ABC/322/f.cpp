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
typedef pair<int, int>
    pii;
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
  ll max_num_zero, max_num_one, right_num, right_len, left_num, left_len;

  bool all, empty;
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
  ll ma_one = max(a.max_num_one, b.max_num_one);
  ll ma_zero = max(a.max_num_zero, b.max_num_zero);
  if (a.right_num == b.left_num)
  {
    if (a.right_num == 0)
      chmax(ma_zero, a.right_len + b.left_len);
    else
    {
      chmax(ma_one, a.right_len + b.left_len);
    }
  }
  ll nright_num = b.right_num;
  ll nright_len = b.right_len;
  ll nleft_num = a.left_num;
  ll nleft_len = a.left_len;
  if (b.all && b.right_num == a.right_num)
  {
    nright_num = b.right_num;
    nright_len = a.right_len + b.right_len;
  }
  if (a.all && a.left_num == b.left_num)
  {
    nleft_num = a.left_num;
    nleft_len = a.left_len + b.left_len;
  }
  bool nall = false;
  if (a.all && b.all && a.right_num == b.right_num)
  {
    nall = true;
  }
  return {
      ma_zero, ma_one, nright_num, nright_len, nleft_num, nleft_len, nall, false};
}
S e()
{
  return {
      0, 0, 0, 0, 0, 0, false, false};
}

struct Act
{
  ll v;
};

S mapping(Act f, S a)
{
  if (f.v)
  {
    return {
        a.max_num_one, a.max_num_zero, 1 - a.right_num, a.right_len, 1 - a.left_num, a.left_len, a.all, a.empty};
  }
  return a;
}
Act composition(Act f, Act g)
{
  return {(f.v + g.v) % 2};
}
Act id()
{
  return {
      0};
}
int main()
{
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<S> ini(n);
  rep(i, n)
  {
    if (s[i] == '0')
    {
      ini[i] = {
          1, 0, s[i] - '0', 1, s[i] - '0', 1, true, false};
    }
    else
    {
      ini[i] = {
          0,
          1,
          s[i] - '0',
          1,
          s[i] - '0',
          1,
          true,
          false};
    }
  }
  lazy_segtree<S, op, e, Act, mapping, composition, id> seg(ini);
  vll ans(0);
  rep(i, q)
  {
    ll c, l, r;
    cin >> c >> l >> r;
    l--;
    r--;
    if (c == 1)
    {
      seg.apply(l, r + 1, {1});
    }
    else
    {
      ans.pb(seg.prod(l, r + 1).max_num_one);
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

__builtin_popcount(i)*/
