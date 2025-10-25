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
  ll n, m;
  cin >> n >> m;
  vvll t(n, vll(0));

  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[u].pb(v);
    t[v].pb(u);
  }
  ll k;
  cin >> k;
  if (k == 0)
  {
    cout << "Yes" << endl;
    rep(i, n)
    {
      cout << 1;
    }
    cout << endl;
    return 0;
  }
  vll p(k), d(k);
  rep(i, k)
  {
    cin >> p[i] >> d[i];
    p[i]--;
  }
  vll c(n);
  rep(i, k)
  {
    queue<pll> que;
    vll dist(n, -1);
    dist[p[i]] = 0;
    que.push({p[i], -1});
    while (que.size())
    {
      auto [now, par] = que.front();
      que.pop();
      if (dist[now] == d[i])
      {
        c[now] = 1;
        continue;
      }
      for (auto p : t[now])
      {
        if (p != par && dist[p] == -1)
        {
          dist[p] = dist[now] + 1;
          que.push({p, now});
        }
      }
    }
  }
  rep(i, k)
  {
    queue<pll> que;
    vll dist(n, -1);
    dist[p[i]] = 0;
    que.push({p[i], -1});
    while (que.size())
    {
      auto [now, par] = que.front();
      que.pop();
      if (dist[now] == d[i])
      {
        continue;
      }
      if (dist[now] < d[i])
      {
        c[now] = 0;
      }
      for (auto p : t[now])
      {
        if (p != par && dist[p] == -1)
        {
          dist[p] = dist[now] + 1;
          que.push({p, now});
        }
      }
    }
  }
  vll ans(0);
  rep(i, k)
  {
    bool ok = false;
    queue<pll> que;
    vll dist(n, -1);
    dist[p[i]] = 0;
    que.push({p[i], -1});
    while (que.size())
    {
      auto [now, par] = que.front();
      que.pop();
      if (dist[now] == d[i] && c[now] == 1)
      {
        ok = true;
        break;
      }
      for (auto p : t[now])
      {
        if (p != par && dist[p] == -1)
        {
          dist[p] = dist[now] + 1;
          que.push({p, now});
        }
      }
    }
    if (!ok)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  rep(i, n)
  {
    if (c[i])
    {
      cout << '1';
    }
    else
    {
      cout << '0';
    }
  }
  cout << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
