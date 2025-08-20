#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
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
  vvll t(n + 1, vll(n + 1, INF));
  rep(i, n + 1)
  {
    t[i][i] = 0;
  }
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    chmin(t[a][b], c);
    chmin(t[b][a], c);
  }
  ll k, cost;
  cin >> k >> cost;
  rep(i, k)
  {
    ll d;
    cin >> d;
    d--;
    t[d][n] = cost;
    t[n][d] = 0;
  }
  rep(k, n + 1)
  {
    rep(i, n + 1)
    {
      rep(j, n + 1)
      {
        t[i][j] = min(t[i][k] + t[k][j], t[i][j]);
      }
    }
  }
  ll q;
  cin >> q;
  rep(i, q)
  {
    ll s;
    cin >> s;
    if (s == 1)
    {
      ll x, y, z;
      cin >> x >> y >> z;
      x--;
      y--;
      chmin(t[x][y], z);
      chmin(t[y][x], z);
      rep(i, n + 1)
      {
        rep(j, n + 1)
        {
          chmin(t[i][j], t[i][x] + z + t[y][j]);
          chmin(t[i][j], t[i][y] + z + t[x][j]);
        }
      }
    }
    else if (s == 2)
    {
      ll x;
      cin >> x;
      x--;
      // 絶対costに更新される
      chmin(t[x][n], cost);
      chmin(t[n][x], 0LL);
      rep(i, n + 1)
      {
        rep(j, n + 1)
        {
          chmin(t[i][j], t[i][x] + cost + t[n][j]);
          chmin(t[i][j], t[i][n] + t[x][j]);
        }
      }
    }
    else
    {
      ll ans = 0;
      rep(i, n)
      {
        rep(j, n)
        {
          if (t[i][j] != INF)
          {
            ans += t[i][j];
          }
        }
      }
      cout << ans << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
