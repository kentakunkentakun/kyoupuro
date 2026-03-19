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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
int main()
{
  ll h, w, n;
  cin >> h >> w >> n;
  ll sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  map<ll, vector<ll>> yoko;
  map<ll, vector<ll>> tate;
  vll x(n), y(n);
  map<pll, ll> it;
  ll iter = 0;
  it[{sx, sy}] = iter;
  iter++;
  rep(i, n)
  {
    cin >> x[i] >> y[i];
    rep(z, 4)
    {
      ll nx = x[i] + dx[z];
      ll ny = y[i] + dy[z];
      if (!it.count({nx, ny}) && isIn(nx - 1, ny - 1, h, w))
      {
        it[{nx, ny}] = iter;
        iter++;
      }
    }
    yoko[x[i]].pb(y[i]);
    tate[y[i]].pb(x[i]);
  }
  vvll t(iter, vll(0));

  for (auto &[x, v] : yoko)
  {
    sort(all(v));
  }
  for (auto &[_, v] : tate)
  {
    sort(all(v));
  }
  if (!it.count({gx, gy}))
  {
    cout << -1 << endl;
    return 0;
  }
  vll dist(iter, INF);
  dist[0] = 0;
  queue<pll> que;
  que.push({sx, sy});
  while (que.size())
  {
    auto [nx, ny] = que.front();
    que.pop();
    ll V = dist[it[{nx, ny}]];
    if (yoko.count(nx))
    {
      vll &v = yoko[nx];
      auto lower = lower_bound(all(v), ny);
      if (lower != v.begin())
      {
        lower--;
        ll l = *lower + 1;
        if (l < ny && chmin(dist[it[{nx, l}]], V + 1))
        {
          que.push({nx, l});
        }
      }
      auto upper = upper_bound(all(v), ny);
      if (upper != v.end())
      {
        ll u = *upper - 1;
        if (ny < u && chmin(dist[it[{nx, u}]], V + 1))
        {
          que.push({nx, u});
        }
      }
    }
    if (tate.count(ny))
    {
      vll &v = tate[ny];
      auto lower = lower_bound(all(v), nx);
      if (lower != v.begin())
      {
        lower--;
        ll l = *lower + 1;
        if (l < nx && chmin(dist[it[{l, ny}]], V + 1))
        {
          que.push({l, ny});
        }
      }
      auto upper = upper_bound(all(v), nx);
      if (upper != v.end())
      {
        ll u = *upper - 1;
        if (nx < u && chmin(dist[it[{u, ny}]], V + 1))
        {
          que.push({u, ny});
        }
      }
    }
  }
  ll ans = dist[it[{gx, gy}]];
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
