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
struct edge
{
  ll from, to, c;
};
struct BellmanFordMax
{
  BellmanFordMax() {}
  BellmanFordMax(ll n) { init(n); }
  vector<vector<pair<ll, ll>>> E;
  ll N;
  void init(ll n)
  {
    N = n;
    E.resize(0);
    E.clear();
    E.resize(n);
  }
  void add(ll a, ll b, ll c) { E[a].push_back({b, c}); }
  vector<ll> solve(ll s)
  {
    vector<ll> res(N, -INF);
    res[s] = 0;

    rep(i, N - 1)
    {
      rep(cu, N) if (-INF < res[cu]) for (auto p : E[cu])
      {
        chmax(res[p.first], res[cu] + p.second);
      }
    }

    vector<bool> pos(N);
    rep(i, N)
    {
      rep(cu, N) if (-INF < res[cu]) for (auto p : E[cu])
      {
        if (chmax(res[p.first], res[cu] + p.second))
        {
          pos[p.first] = true;
        }
        if (pos[cu])
          pos[p.first] = true;
      }
    }

    rep(cu, N) if (pos[cu]) res[cu] = INF;

    return res;
  }
};
int main()
{
  ll n, m, p;
  cin >> n >> m >> p;
  BellmanFordMax bell(n);
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    bell.add(a, b, c - p);
  }
  vll res = bell.solve(0);
  if (res[n - 1] == INF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << max(0LL, res[n - 1]) << endl;
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
