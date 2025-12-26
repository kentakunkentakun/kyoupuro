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
struct edge
{
  ll to, cost;
};
int main()
{
  ll n, m;
  cin >> n >> m;
  vll x(n), y(n);
  rep(i, n) cin >> x[i];
  rep(i, n) cin >> y[i];
  vector<tuple<ll, ll, ll>> t(m);
  rep(i, m)
  {
    ll a, b, z;
    cin >> a >> b >> z;
    a--;
    b--;
    t[i] = {a, b, z};
  }
  ll ans = INF;
  rep(u, 4)
  {
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    rep(i, m)
    {
      auto [a, b, z] = t[i];
      que.push({z, a, b});
    }
    if (u == 1 || u == 3)
    {
      rep(i, n)
      {
        que.push({x[i], i, n});
      }
    }
    if (u == 2)
    {
      rep(i, n)
      {
        que.push({y[i], i, n});
      }
    }
    if (u == 3)
    {
      rep(i, n)
      {
        que.push({y[i], i, n + 1});
      }
    }
    ll si = n;
    if (u == 3)
    {
      si += 2;
    }
    else if (u == 1 || u == 2)
    {
      si++;
    }
    dsu uf(si);
    ll res = 0;
    while (que.size() && uf.size(0) != si)
    {
      auto [cost, a, b] = que.top();
      que.pop();
      if (!uf.same(a, b))
      {
        uf.merge(a, b);
        res += cost;
      }
    }
    if (uf.size(0) == si)
    {
      chmin(ans, res);
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
