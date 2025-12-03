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
ll dx[2] = {0, 1};
ll dy[2] = {1, 0};
ll ddx[2] = {0, -1};
ll ddy[2] = {-1, 0};
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
int main()
{
  ll n;
  cin >> n;
  vvll a(n, vll(n));
  rep(i, n)
  {
    rep(j, n) cin >> a[i][j];
  }
  vvvll t(n, vvll(n, vll(0)));
  t[0][0].pb(a[0][0]);
  t[n - 1][n - 1].pb(a[n - 1][n - 1]);
  rep(i, n - 1)
  {
    for (int j = 0; i + j < n - 1; j++)
    {
      for (auto p : t[i][j])
      {
        rep(z, 2)
        {
          ll nx = i + dx[z];
          ll ny = j + dy[z];
          if (isIn(nx, ny, n, n))
          {
            t[nx][ny].pb(p ^ a[nx][ny]);
          }
        }
      }
    }
  }
  for (int i = n - 1; i >= 2; i--)
  {
    for (int j = n - 1; i + j >= n + 1; j--)
    {
      for (auto p : t[i][j])
      {
        rep(z, 2)
        {
          ll nx = i + ddx[z];
          ll ny = j + ddy[z];
          if (isIn(nx, ny, n, n))
          {
            t[nx][ny].pb(p ^ a[nx][ny]);
          }
        }
      }
    }
  }
  vector<vector<map<ll, ll>>> m(n, vector<map<ll, ll>>(n));
  for (int i = 1; i < n; i++)
  {
    ll j = n - i;
    for (auto p : t[i][j])
    {
      m[i][j][p]++;
    }
  }
  ll ans = 0;
  rep(i, n)
  {
    ll j = n - i - 1;
    rep(z, 2)
    {
      ll nx = i + dx[z];
      ll ny = j + dy[z];
      if (isIn(nx, ny, n, n))
      {
        for (auto p : t[i][j])
        {
          ans += m[nx][ny][p];
        }
      }
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
