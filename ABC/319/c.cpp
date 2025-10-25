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
  cout << fixed << setprecision(15);
  vll c(9);
  rep(i, 3)
  {
    rep(j, 3)
    {
      cin >> c[i * 3 + j];
    }
  }
  vll t(9);
  rep(i, 9) t[i] = i;
  auto ch = [&](vll &u) -> bool
  {
    bool ok = true;

    rep(i, 3)
    {
      ll n0 = 0 + i * 3;
      ll n1 = 1 + i * 3;
      ll n2 = 2 + i * 3;
      if (c[n0] == c[n1] && max(u[n0], u[n1]) < u[n2])
      {
        ok = false;
      }
      if (c[n1] == c[n2] && max(u[n1], u[n2]) < u[n0])
      {
        ok = false;
      }
      if (c[n0] == c[n2] && max(u[n0], u[n2]) < u[n1])
      {
        ok = false;
      }
    }
    rep(i, 3)
    {
      ll n0 = 0 + i;
      ll n1 = 3 + i;
      ll n2 = 6 + i;
      if (c[n0] == c[n1] && max(u[n0], u[n1]) < u[n2])
      {
        ok = false;
      }
      if (c[n1] == c[n2] && max(u[n1], u[n2]) < u[n0])
      {
        ok = false;
      }
      if (c[n0] == c[n2] && max(u[n0], u[n2]) < u[n1])
      {
        ok = false;
      }
    }
    ll n0 = 0;
    ll n1 = 4;
    ll n2 = 8;
    if (c[n0] == c[n1] && max(u[n0], u[n1]) < u[n2])
    {
      ok = false;
    }
    if (c[n1] == c[n2] && max(u[n1], u[n2]) < u[n0])
    {
      ok = false;
    }
    if (c[n0] == c[n2] && max(u[n0], u[n2]) < u[n1])
    {
      ok = false;
    }
    n0 = 2;
    n1 = 4;
    n2 = 6;
    if (c[n0] == c[n1] && max(u[n0], u[n1]) < u[n2])
    {
      ok = false;
    }
    if (c[n1] == c[n2] && max(u[n1], u[n2]) < u[n0])
    {
      ok = false;
    }
    if (c[n0] == c[n2] && max(u[n0], u[n2]) < u[n1])
    {
      ok = false;
    }
    return ok;
  };
  double k = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;
  double ans = k;
  do
  {
    if (!ch(t))
    {
      ans--;
    }
  } while (next_permutation(all(t)));
  cout << ans / k << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
