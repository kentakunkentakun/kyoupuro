#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0; i--)
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
  ll h, w, y;
  cin >> h >> w >> y;
  vvll a(h, vll(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<vector<pair<ll, ll>>> q(100005, vector<pair<ll, ll>>(0));
  vector<vector<bool>> face_sea(h, vector<bool>(w, false));
  rep(i, h)
  {
    if (!face_sea[i][0])
    {
      q[a[i][0]].pb(mp(i, 0));
      face_sea[i][0] = true;
    }
    if (!face_sea[i][w - 1])
    {
      q[a[i][w - 1]].pb(mp(i, w - 1));
      face_sea[i][w - 1] = true;
    }
  }
  for (int j = 1; j < w - 1; j++)
  {
    if (!face_sea[0][j])
    {
      q[a[0][j]].pb(mp(0, j));
      face_sea[0][j] = true;
    }
    if (!face_sea[h - 1][j])
    {
      q[a[h - 1][j]].pb(mp(h - 1, j));
      face_sea[h - 1][j] = true;
    }
  }
  ll land_count = 0;
  for (int i = 1; i <= y; i++)
  {
    ll iter = 0;
    ll que_size = q[i].size();
    while (iter < que_size)
    {
      rep(z, 4)
      {
        ll ni = q[i][iter].F + dx[z];
        ll nj = q[i][iter].S + dy[z];
        if (ni >= 0 && ni < h && nj >= 0 && nj < w && !face_sea[ni][nj])
        {
          if (a[ni][nj] <= i)
          {
            q[i].pb(mp(ni, nj));
            face_sea[ni][nj] = true;
            que_size++;
          }
          else
          {
            q[a[ni][nj]].pb(mp(ni, nj));
            face_sea[ni][nj] = true;
          }
        }
      }
      iter++;
    }
    land_count += que_size;
    cout << h * w - land_count << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
