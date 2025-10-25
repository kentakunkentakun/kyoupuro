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
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  auto dfs = [&](auto dfs, int i, int from, ll k) -> vll
  {
    vll res = {i};
    if (k == 0)
    {
      return res;
    }
    for (auto p : t[i])
    {
      if (p == from)
        continue;
      vll tmp = dfs(dfs, p, i, k - 1);
      res.reserve(res.size() + tmp.size());
      res.insert(res.end(), all(tmp));
    }
    return res;
  };
  ll q;
  cin >> q;
  vll ans(0);
  rep(i, q)
  {
    ll x, k;
    cin >> x >> k;
    x--;
    vll res = dfs(dfs, x, -1, k);
    sort(all(res));
    res.erase(unique(all(res)), res.end());
    ll cnt = 0;
    rep(j, res.size()) cnt += res[j] + 1;
    ans.pb(cnt);
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

__builtin_popcount(i)*/
