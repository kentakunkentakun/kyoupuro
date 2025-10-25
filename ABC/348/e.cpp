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
const ll INF = 1LL << 62;
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

ll n;
vll sum_c(100005, 0);
vll sum_f(100005, 0);
vll c(100005, 0);

pll dfs(ll now, ll par, vvll &t)
{
  ll c_sum = c[now];
  ll f_sum = 0;
  for (auto p : t[now])
  {
    if (p != par)
    {
      pll nx = dfs(p, now, t);
      c_sum += nx.F;
      f_sum += nx.S;
    }
  }
  sum_c[now] = c_sum;
  sum_f[now] = f_sum;
  f_sum += c_sum;
  return pll(c_sum, f_sum);
};
vll ans(100005, INF);
void reroot(ll i, ll par, vvll &t, ll par_sum_c, ll par_sum_f)
{
  ans[i] = par_sum_f + sum_f[i];
  ll next_c = 0;
  ll next_d = 0;
  for (auto p : t[i])
  {
    if (p != par)
    {
      next_c = par_sum_c + sum_c[i] - sum_c[p];
      next_d = par_sum_f + next_c + sum_f[i] - sum_f[p] - sum_c[p];
      reroot(p, i, t, next_c, next_d);
    }
  }
  return;
}
int main()
{
  cin >> n;

  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  rep(i, n) cin >> c[i];

  dfs(0, -1, t);
  reroot(0, -1, t, 0, 0);

  ll res = INF;
  rep(i, n)
  {
    chmin(res, ans[i]);
  }
  cout << res << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
