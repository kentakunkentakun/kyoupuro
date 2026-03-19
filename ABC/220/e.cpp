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
  ll n, d;
  cin >> n >> d;
  vll po(d + 1, 1);
  ll tmp = 1;
  rep(i, d + 1)
  {
    po[i] *= tmp;
    po[i] %= MOD;
    tmp *= 2;
    tmp %= MOD;
  }
  vll f(n + 1), g(n + 1);
  rep(i, n + 1)
  {
    if (i == 0)
      continue;
    ll l = i, r = d - l;
    ll leaf = 0;
    if (r <= l && r >= 0)
    {
      leaf = po[max(l - 1, 0LL)] * po[max(r - 1, 0LL)];
      if (r != l)
        leaf *= 2;
      leaf %= MOD;
    }
    g[i] = leaf;
    cout << i << " " << leaf << endl;
  }
  rep(i, n)
  {
    f[i + 1] = f[i] * 3 + g[i + 1] * 2;
    f[i + 1] %= MOD;
    cout << i + 1 << " " << f[i + 1] << endl;
  }
  cout << f[n - 1] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
