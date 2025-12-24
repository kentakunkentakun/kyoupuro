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
  ll n;
  cin >> n;
  vll p(n);
  ll minus = 0;
  ll plus = 0;
  ll res = 0;
  ll ans = INF;
  if (n % 2 == 0)
  {
    vvll t(n, vll(2));
    rep(i, n)
    {
      cin >> p[i];
      ll rev, f;
      if (p[i] > i)
      {
        rev = (p[i] - i);
        f = n - (p[i] - i);
      }
      else if (p[i] < i)
      {
        rev = n - (i - p[i]);
        f = i - p[i];
      }
      else
      {
        rev = n;
        f = 0;
      }
      ll mi = min(rev, f);
      res += mi;
      if (rev > f)
      {
        plus++;
        // そこまでプラス
        t[n / 2 - mi][0]++;
      }
      else if (rev < f)
      {
        t[mi][1]++;
        minus++;
      }
      else if (mi == n / 2)
      {
        t[0][0]++;
        plus++;
      }
      else
      {
        t[0][1]++;
        minus++;
      }
    }
    rep(i, n)
    {
      chmin(ans, res);
      minus += t[i][0] - t[i][1];
      plus += t[i][1] - t[i][0];
      res = res + plus - minus;
      if (i + n / 2 < n)
      {
        t[i + n / 2][1] += t[i][0];
        t[i + n / 2][0] += t[i][1];
      }
    }
    chmin(ans, res);
    cout << ans << endl;
  }
  else
  {
    vvll t(n, vll(3));
    rep(i, n)
    {
      cin >> p[i];
      ll rev, f;
      if (p[i] > i)
      {
        rev = (p[i] - i);
        f = n - (p[i] - i);
      }
      else if (p[i] < i)
      {
        rev = n - (i - p[i]);
        f = i - p[i];
      }
      else
      {
        rev = n;
        f = 0;
      }
      ll mi = min(rev, f);
      res += mi;
      if (rev > f)
      {
        if (f < n / 2)
        {
          plus++;
          // そこまでプラス
          t[n / 2 - mi][0]++;
        }
        else
        {
          t[n / 2 - mi + 1][1]++;
        }
      }
      else if (rev < f)
      {
        if (rev < n / 2)
        {
          t[mi][2]++;
          minus++;
        }
        else
        {
          t[n / 2][2]++;
          minus++;
        }
      }
      else
      {
        t[0][2]++;
        minus++;
      }
    }
    rep(i, n)
    {
      chmin(ans, res);
      minus += t[i][1] - t[i][2];
      plus += t[i][2] - t[i][0];
      if (i + 1 < n)
      {
        t[i + 1][1] += t[i][0];
      }
      res = res + plus - minus;
      if (i + n / 2 < n)
      {
        t[i + n / 2][2] += t[i][1];
        t[i + n / 2][0] += t[i][2];
      }
    }
    chmin(ans, res);
    cout << ans << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
