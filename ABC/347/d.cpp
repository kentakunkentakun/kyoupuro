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
long long modpow(long long a, long long n, long long mod)
{
  long long res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  if (a + b > 2 * 60 - __builtin_popcountll(c) || a + b < __builtin_popcountll(c) || abs(a - b) > __builtin_popcountll(c) || (__builtin_popcountll(c) - abs(a - b)) % 2 != 0)
  {
    cout << -1 << endl;
    return 0;
  }
  ll aa = 0;
  ll bb = 0;
  ll iter = 0;
  set<ll> A;
  set<ll> B;
  while (c)
  {
    if (c % 2)
    {
      if (a > b)
      {
        aa += modpow(2, iter, INF * 2);
        a--;
        A.insert(iter);
      }
      else
      {
        bb += modpow(2, iter, INF * 2);
        b--;
        B.insert(iter);
      }
    }
    iter++;
    c /= 2;
  }
  ll remain = a + b;
  iter = 0;
  while (remain)
  {
    if (!A.count(iter) && !B.count(iter))
    {
      aa += modpow(2, iter, INF * 2);
      bb += modpow(2, iter, INF * 2);
      remain -= 2;
    }
    iter++;
  }
  cout << aa << " " << bb << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
