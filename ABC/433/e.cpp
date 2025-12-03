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
// const ll MOD = 1000000007LL;
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
  ll t;
  cin >> t;
  vector<pair<string, vvll>> res(0);
  rep(T, t)
  {
    ll n, m;
    cin >> n >> m;
    vll x(n), y(m);
    map<ll, ll> xx;
    map<ll, ll> yy;
    vector<tuple<ll, ll, ll>> u(0);
    vector<pll> xi(n), yi(m);
    bool ok = true;
    rep(i, n)
    {
      cin >> x[i];
      u.pb({x[i], i, 0});
      if (xx.count(x[i]))
      {
        ok = false;
      }
      xx[x[i]] = i;
      xi[i] = {x[i], i};
    }
    rep(i, m)
    {
      cin >> y[i];
      if (yy.count(y[i]))
      {
        ok = false;
      }
      yy[y[i]] = i;
      u.pb({y[i], i, 1});
      yi[i] = {y[i], i};
    }
    if (!ok)
    {
      // cout << "No" << endl;
      res.pb({"No", {}});
      continue;
    }
    sort(all(xi));
    sort(all(yi));
    sort(all(u));
    vvll ans(n, vll(m, -1));
    set<ll> unused;
    rep(i, n * m)
    {
      unused.insert(i + 1);
    }
    rep(i, n)
    {
      if (yy.count(x[i]))
      {
        ans[i][yy[x[i]]] = x[i];
        unused.erase(x[i]);
      }
    }
    repR(i, n + m)
    {
      auto [v, iter, w] = u[i];
      if (!unused.count(v))
        continue;
      if (w == 0)
      {
        repR(j, m)
        {
          if (v < yi[j].F && ans[iter][yi[j].S] == -1)
          {
            ans[iter][yi[j].S] = v;
            unused.erase(v);
            break;
          }
        }
      }
      else
      {
        repR(j, n)
        {
          if (v < xi[j].F && ans[xi[j].S][iter] == -1)
          {
            ans[xi[j].S][iter] = v;
            unused.erase(v);
            break;
          }
        }
      }
      if (unused.count(v))
      {
        ok = false;
        break;
      }
    }
    if (!ok)
    {
      // cout << "No" << endl;
      res.pb({"No", {}});
      continue;
    }
    for (auto [v, iter, w] : u)
    {
      if (w == 0)
      {
        rep(i, m)
        {
          if (ans[iter][i] == -1)
          {
            ll s = *unused.begin();
            if (s < x[iter] && s < y[i])
            {
              ans[iter][i] = s;
            }
            else
            {
              ok = false;
              break;
            }
            unused.erase(s);
          }
        }
      }
      else
      {
        rep(i, n)
        {
          if (ans[i][iter] == -1)
          {
            ll s = *unused.begin();
            if (s < x[i] && s < y[iter])
            {
              ans[i][iter] = s;
            }
            else
            {
              ok = false;
              break;
            }
            unused.erase(s);
          }
        }
      }
      if (!ok)
      {
        break;
      }
    }
    if (!ok)
    {
      // cout << "No" << endl;
      res.pb({"No", {}});
      continue;
    }
    res.pb({"Yes", ans});
  }
  rep(i, t)
  {
    if (res[i].F == "No")
    {
      cout << "No" << endl;
    }
    else
    {
      cout << "Yes" << endl;
      rep(j, res[i].S.size())
      {
        for (auto p : res[i].S[j])
        {
          cout << p << " ";
        }
        cout << endl;
      }
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
