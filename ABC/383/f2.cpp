#include <bits/stdc++.h>
#include <atcoder/dsu>
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
int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<tuple<ll, ll, ll>> p(m);
  rep(i, m)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    p[i] = {w, u, v};
  }
  sort(all(p));
  vll a(n, 0), b(n, 0);
  rep(i, k)
  {
    ll v;
    cin >> v;
    v--;
    a[v]++;
  }
  rep(i, k)
  {
    ll v;
    cin >> v;
    v--;
    b[v]++;
  }
  ll ans = 0;
  dsu uf(n);
  rep(i, m)
  {
    auto [w, u, v] = p[i];
    if (!uf.same(u, v))
    {
      ll A = a[uf.leader(u)] + a[uf.leader(v)];
      ll B = b[uf.leader(u)] + b[uf.leader(v)];
      ans += min(A, B) * w;
      ll t = min(A, B);
      A -= t;
      B -= t;
      uf.merge(u, v);
      ll r = uf.leader(u);
      a[r] = A;
      b[r] = B;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
