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
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
vector<ll> res(0);
void yakusuu(ll n)
{
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      res.pb(i);
      if (i != n / i)
        res.pb(n / i);
    }
  }
  return;
}
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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  yakusuu(n);
  sort(all(res));
  vll cnt(n + 1, 0);
  rep(i, res.size())
  {
    // res[i]のパターン
    ll tmp = res[i];
    for (int j = 0; j < res[i]; j++)
    {
      bool ch = true;
      ll iter = j;
      while (iter < s.size())
      {
        if (s[iter] == '.')
          ch = false;
        iter += res[i];
      }
      if (!ch)
        tmp--;
    }
    cnt[res[i]] += modpow(2, tmp, MOD);
    for (int j = 2; j * res[i] <= n; j++)
    {
      cnt[j * res[i]] -= cnt[res[i]];
      cnt[j * res[i]] %= MOD;
      cnt[j * res[i]] += MOD;
      cnt[j * res[i]] %= MOD;
    }
  }
  ll ans = 0;
  rep(i, res.size() - 1)
  {
    ans += cnt[res[i]];
    ans %= MOD;
  }
  cout << ((ans % MOD) + MOD) % MOD << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
