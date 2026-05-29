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
int main()
{
  ll n, m;
  cin >> n >> m;
  vll d(n);
  rep(i, n) cin >> d[i];
<<<<<<< Updated upstream
  dsu uf(n);

  bool ok = true;
=======
>>>>>>> Stashed changes
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
<<<<<<< Updated upstream
    if (uf.same(a, b))
    {
      ok = false;
    }
    d[a]--;
    d[b]--;
    uf.merge(a, b);
  }
  vector<vector<pll>> t(n, vector<pll>(0));

=======
    d[a]--;
    d[b]--;
  }
  queue<ll> q;
  priority_queue<pll, vector<pll>, greater<pll>> que;
>>>>>>> Stashed changes
  rep(i, n)
  {
    if (d[i] < 0)
    {
<<<<<<< Updated upstream
      ok = false;
      break;
    }
  }
  if (!ok)
  {
    cout << -1 << endl;
    return 0;
  }
  ll cnt = 0;
  set<ll> s;
  rep(i, n)
  {
    s.insert(uf.leader(i));
    if (d[i] > 0)
    {
      t[uf.leader(i)].pb({d[i], i});
      cnt += d[i];
    }
  }
  if ((s.size() - 1) * 2 != cnt)
  {
    cout << -1 << endl;
    return 0;
  }
  priority_queue<pll> que;
  rep(i, n)
  {
    ll cn = 0;
    for (auto [dd, it] : t[i])
    {
      cn += dd;
    }
    if (cn > 0)
    {
      que.push({cn, i});
    }
    if (s.count(i) && cn == 0)
    {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<pll> ans(0);
  while (que.size())
  {
    auto [fcn, fit] = que.top();
    que.pop();
    auto [scn, sit] = que.top();
    que.pop();
    auto [fc, fi] = t[fit].back();
    t[fit].pop_back();
    auto [sc, si] = t[sit].back();
    t[sit].pop_back();
    ans.pb({fi, si});
    fcn--;
    scn--;
    fc--;
    sc--;
    if (fc > 0)
    {
      t[fit].pb({fc, fi});
    }
    if (sc > 0)
    {
      t[sit].pb({sc, si});
    }
    if (t[fit].size() < t[sit].size())
    {
      swap(fit, sit);
    }
    for (auto [C, I] : t[sit])
    {
      t[fit].pb({C, I});
    }
    fcn += scn;
    if (fcn > 0)
    {
      que.push({fcn, fit});
    }
  }
  rep(i, ans.size())
  {
    cout << ans[i].F + 1 << " " << ans[i].S + 1 << endl;
=======
      cout << -1 << endl;
      return 0;
    }
    if (d[i] == 1)
    {
      q.push(i);
    }
    else if (d[i] > 1)
    {
      que.push({d[i], i});
    }
  }
  vector<pll> ans(0);
  while (q.size())
  {
    ll i = q.front();
    q.pop();
    if (que.size())
    {
      auto [cnt, it] = que.top();
      que.pop();
      cnt--;
      ans.pb({i, it});
      if (cnt == 1)
      {
        q.push(it);
      }
      else
      {
        que.push({cnt, it});
      }
    }
    else
    {
      if (q.size() == 1)
      {
        ll ni = q.front();
        q.pop();
        ans.pb({i, ni});
        break;
      }
      else
      {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if (que.size() > 0)
  {
    cout << -1 << endl;
  }
  else
  {
    rep(i, ans.size())
    {
      cout << ans[i].F + 1 << " " << ans[i].S + 1 << endl;
    }
>>>>>>> Stashed changes
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
