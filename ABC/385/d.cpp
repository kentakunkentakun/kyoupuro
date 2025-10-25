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
int main()
{
  ll n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  map<ll, vll> x, y;
  rep(i, n)
  {
    ll X, Y;
    cin >> X >> Y;
    y[X].pb(Y);
    x[Y].pb(X);
  }
  for (auto &[p, v] : x)
  {
    sort(all(v));
  }
  for (auto &[p, v] : y)
  {
    sort(all(v));
  }
  map<ll, vector<pll>> dx, dy;
  rep(i, m)
  {
    char d;
    ll c;
    cin >> d >> c;
    if (d == 'U')
    {
      if (y.count(sx))
      {
        dy[sx].pb({sy, sy + c});
      }
      sy += c;
    }
    else if (d == 'D')
    {
      if (y.count(sx))
      {
        dy[sx].pb({sy - c, sy});
      }
      sy -= c;
    }
    else if (d == 'L')
    {
      if (x.count(sy))
      {
        dx[sy].pb({sx - c, sx});
      }
      sx -= c;
    }
    else
    {
      if (x.count(sy))
      {
        dx[sy].pb({sx, sx + c});
      }
      sx += c;
    }
  }
  set<pll> ans;

  for (auto &[yy, v] : dx)
  {
    sort(all(v));
    vector<pll> tmp(0);
    ll s, g;
    ll V = v.size();
    rep(i, V)
    {
      if (i == 0)
      {
        s = v[i].F;
        g = v[i].S;
      }

      if (g >= v[i].F)
      {
        chmax(g, v[i].S);
      }
      else
      {
        tmp.pb({s, g});
        s = v[i].F;
        g = v[i].S;
      }
    }
    tmp.pb({s, g});

    for (auto &[s, g] : tmp)
    {

      auto siter = lower_bound(all(x[yy]), s);
      auto eiter = upper_bound(all(x[yy]), g);
      while (siter < eiter)
      {
        ans.insert({*siter, yy});
        ++siter;
      }
    }
  }

  for (auto &[xx, v] : dy)
  {
    sort(all(v));
    vector<pll> tmp(0);
    ll s, g;
    ll V = v.size();

    rep(i, V)
    {
      if (i == 0)
      {
        s = v[i].F;
        g = v[i].S;
      }

      if (g >= v[i].F)
      {
        chmax(g, v[i].S);
      }
      else
      {
        tmp.pb({s, g});
        s = v[i].F;
        g = v[i].S;
      }
    }
    tmp.pb({s, g});

    for (auto &[s, g] : tmp)
    {

      auto siter = lower_bound(all(y[xx]), s);
      auto eiter = upper_bound(all(y[xx]), g);
      while (siter != eiter)
      {
        ans.insert({xx, *siter});
        ++siter;
      }
    }
  }
  cout << sx << " " << sy << " " << ans.size() << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
