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

// a^{-1} mod を計算する

long long modinv(long long a, long long mod)
{
  return modpow(a, mod - 2, mod);
}
int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  vll t(n);
  rep(i, n) cin >> t[i];
  sort(all(t));
  if (a == 1)
  {
    rep(i, n)
    {
      cout << t[i] << endl;
    }
    return 0;
  }
  else
  {
    multiset<ll> s;
    rep(i, n)
    {
      s.insert(t[i]);
    }
    ll cnt = 0;
    while (1)
    {
      auto mi = s.begin();
      auto ma = s.rbegin();
      if (*mi * a > *ma)
      {
        break;
      }
      cnt++;
      s.insert(*mi * a);
      s.erase(mi);
      if (cnt == b)
      {
        break;
      }
    }
    if (cnt == b)
    {
      for (auto p : s)
      {
        cout << p << endl;
      }
      return 0;
    }
    b -= cnt;
    ll iter = 0;
    for (auto p : s)
    {
      t[iter] = p;
      iter++;
    }
    ll zen = b % n == 0 ? n : b % n;
    ll kou = n - zen;
    ll zen_kake = (b + n - 1) / n;
    ll kou_kake = zen_kake - 1;
    for (int i = n - kou; i < n; i++)
    {
      cout << t[i] * modpow(a, kou_kake, MOD) % MOD << endl;
    }
    rep(i, zen)
    {
      cout << t[i] * modpow(a, zen_kake, MOD) % MOD << endl;
    }
    return 0;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
