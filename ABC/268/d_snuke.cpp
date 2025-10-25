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
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  set<string> ts;
  rep(i, m)
  {
    string t;
    cin >> t;
    ts.insert(t);
  }
  ll max_cnt = 16 - (n - 1);
  rep(i, n) max_cnt -= S[i].size();
  if (n == 1)
    max_cnt = 0;

  vector<bool> used(n);
  auto dfs = [&](auto f, int i, string s, int u) -> bool
  {
    if (i == n)
    {
      if (s.size() < 3)
        return false;
      if (ts.count(s))
        return false;
      cout << s << endl;
      return true;
    }
    if (u)
    {
      if (f(f, i, s + '_', u - 1))
      {
        return true;
      }
    }
    rep(j, n)
    {
      if (!used[j])
      {
        used[j] = true;
        if (f(f, i + 1, s + '_' + S[j], u))
        {
          return true;
        }
        used[j] = false;
      }
    }
    return false;
  };
  rep(i, n)
  {
    used[i] = true;
    if (dfs(dfs, 1, S[i], max_cnt))
    {
      return 0;
    }
    used[i] = false;
  }
  cout << -1 << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
