#include <bits/stdc++.h>
#include <atcoder/all>
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
  ll t;
  cin >> t;
  vll ans(t);
  rep(T, t)
  {
    ll h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i, h)
    {
      rep(j, w)
      {
        cin >> s[i][j];
      }
    }
    if (h > w)
    {
      vector<vector<char>> tmp(w, vector<char>(h));
      rep(i, h)
      {
        rep(j, w)
        {
          tmp[j][i] = s[i][j];
        }
      }
      s = tmp;
      swap(h, w);
    }
    vvll t(w, vll(h + 1));
    rep(i, w)
    {
      rep(j, h)
      {
        t[i][j + 1] += t[i][j] + ((s[j][i] == '#') ? -1 : 1);
      }
    }
    vll tmp(2 * h * w + 5, 0);
    ll mid = (h * w);

    ll res = 0;
    rep(i, h)
    {
      for (int j = i + 1; j <= h; j++)
      {
        
        tmp[mid]++;
        ll cnt = mid;
        vll c(w);
        rep(z, w)
        {
          cnt += t[z][j] - t[z][i];
          res += tmp[cnt];
          tmp[cnt]++;
          c[z] = cnt;
        }
        rep(z, w)
        {
          tmp[c[z]]--;
        }
        tmp[mid] = 0;
      }
    }
    ans[T] = res;
  }
  rep(i, t)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
