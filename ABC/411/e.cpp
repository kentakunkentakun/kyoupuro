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
// a^n mod を計算する

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
  PQR(pll)
  que;
  rep(i, n)
  {
    rep(j, 6)
    {
      ll a;
      cin >> a;
      que.push(pll(a, i));
    }
  }
  set<ll> s;
  vll t(n + 1, 0);
  ll ans = 0;
  ll cnt = 1;
  ll b_cnt = 0;
  while (que.size())
  {
    auto [a, _] = que.top();
    map<ll, ll> m;
    while (que.size() && que.top().F == a)
    {
      auto [tmp, i] = que.top();
      que.pop();
      s.insert(i);
      m[i]++;
    }

    for (auto p : m)
    {
      if (t[p.F] != 0)
      {
        cnt *= modinv(t[p.F], MOD);
        cnt %= MOD;
      }
      cnt *= (t[p.F] + p.S);
      cnt %= MOD;
      t[p.F] += p.S;
    }
    if (s.size() == n)
    {
      ans += ((a * (cnt - b_cnt) % MOD) + MOD) % MOD;
      ans %= MOD;
      b_cnt = cnt;
    }
  }
  ll div = modinv(6, MOD);
  rep(i, n)
  {
    ans *= div;
    ans %= MOD;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
