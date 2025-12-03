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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct edge
{
  ll to, cost;
};
int main()
{
  ll n, m, l;
  cin >> n >> m >> l;
  vector<vector<edge>> t(n, vector<edge>(0));
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    if (c <= l)
    {
      t[a].pb({b, c});
      t[b].pb({a, c});
    }
  }
  vvvll dist(n, vvll(n, vll(n + 1, -1)));
  rep(i, n)
  {
    vb used(n, false);
    dist[i][i][0] = l;
    // now,給油回数,残リット
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    que.push({0, -l, i});
    while (que.size())
    {
      auto [cnt, li, now] = que.top();
      que.pop();
      li *= -1;
      if (used[now])
        continue;
      if (dist[i][now][cnt] > li)
        continue;
      used[now] = true;
      for (auto [to, cost] : t[now])
      {
        if (!used[to])
        {
          ll next_l = li - cost;
          ll next_k = cnt;
          if (next_l < 0)
          {
            next_l = l - cost;
            next_k++;
          }
          if (chmax(dist[i][to][next_k], next_l))
          {
            que.push({next_k, -1 * next_l, to});
          }
        }
      }
    }
  }
  ll q;
  cin >> q;
  vll ans(q, INF);
  rep(i, q)
  {
    ll s, t;
    cin >> s >> t;
    s--;
    t--;
    rep(u, n + 1)
    {
      if (dist[s][t][u] != -1)
      {
        chmin(ans[i], u);
      }
    }
    if (ans[i] == INF)
      ans[i] = -1;
  }

  rep(i, q)
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
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
