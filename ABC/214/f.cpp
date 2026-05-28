#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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

const ll MOD = 1e9 + 7LL;
// const ll MOD = 998244353LL;
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
ll op(ll a, ll b)
{
  return (a + b) % MOD;
}
ll e()
{
  return 0;
}
int main()
{
  string s;
  cin >> s;
  ll n = s.size();
  vvll t(26, vll(1, 0));
  rep(i, n)
  {
    t[s[i] - 'a'].pb(i + 1);
  }
  segtree<ll, op, e> seg(n + 1);
  seg.set(0, 1);
  seg.set(1, 1);
  rep(i, n)
  {
    if (i < 1)
      continue;
    ll l;
    auto lit = lower_bound(all(t[s[i] - 'a']), i + 1);
    lit--;
    // cout << i << " lit " << *lit << endl;
    if (*lit == 0)
    {
      l = 0;
    }
    else
    {
      l = max(1LL, *lit - 1);
    }
    if (l >= i)
      continue;
    ll res = seg.prod(l, i);
    // cout << i << " " << l << " " << res << endl;
    seg.set(i + 1, res);
  }
  cout << seg.prod(1, n + 1) << endl;
}
