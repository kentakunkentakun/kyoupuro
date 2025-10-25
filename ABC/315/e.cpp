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
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  vvll rt(n, vll(0));
  rep(i, n)
  {
    ll c;
    cin >> c;
    rep(j, c)
    {
      ll p;
      cin >> p;
      p--;
      t[p].pb(i);
      rt[i].pb(p);
    }
  }
  vll dist(n, INF);
  vb used(n);
  vll ans(0);
  auto dfs = [&](auto dfs, int v, vb &used, vll &ans) -> void
  {
    used[v] = true;
    for (auto e : t[v])
    {
      if (!used[e])
      {
        dfs(dfs, e, used, ans);
      }
    }
    ans.pb(v);
  };
  rep(i, n)
  {
    if (!used[i])
    {
      dfs(dfs, i, used, ans);
    }
  }
  reverse(all(ans));

  set<ll> s;
  used = vb(n, false);
  queue<ll> que;
  used[0] = true;
  que.push(0);
  while (que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto p : rt[now])
    {
      if (used[p])
        continue;
      used[p] = true;
      que.push(p);
      s.insert(p);
    }
  }
  rep(i, ans.size())
  {
    if (s.count(ans[i]))
    {
      cout << ans[i] + 1 << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
