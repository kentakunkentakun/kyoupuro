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
  vll a(n);
  rep(i, n) cin >> a[i];
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
  vector<pll> cost(n);
  vll cc(n, 0);

  rep(i, n)
  {
    for (auto p : t[i])
    {
      cost[i].F += a[p];
      cc[i] += a[p];
    }
    cost[i].S = i;
  }
  sort(all(cost));
  auto judge = [&](ll mid) -> bool
  {
    stack<pll> st;
    vll c_now = cc;
    vb ch(n, false);
    rep(i, n)
    {
      if (cost[i].F <= mid)
      {
        st.push(cost[i]);
        ch[cost[i].S] = true;
      }
    }
    ll cnt = n;
    while (st.size())
    {
      auto [c, now] = st.top();
      st.pop();
      cnt--;
      for (auto p : t[now])
      {
        if (!ch[p])
        {
          c_now[p] -= a[now];
          if (c_now[p] <= mid)
          {
            ch[p] = true;
            st.push(pll(c_now[p], p));
          }
        }
      }
    }
    if (cnt == 0)
      return true;
    else
      return false;
  };
  ll ac = INF;
  ll wa = -1;
  while (wa + 1 < ac)
  {
    ll mid = (ac + wa) / 2;
    if (judge(mid))
    {
      ac = mid;
    }
    else
    {
      wa = mid;
    }
  }
  cout << ac << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
