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
#define repR(i, n) for (ll i = n; i >= 0; i--)
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

int main()
{
  ll n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  vvll dpa(n + 5, vll(n + 5, 0));
  vvll dpb(n + 5, vll(n + 5, 0));
  dpa[a][0] = 1;
  dpb[b][0] = 1;
  ll a_inv = modinv(p, MOD);
  ll b_inv = modinv(q, MOD);
  vll a_invd(n + 1, 1);
  vll b_invd(n + 1, 1);
  rep(i, n)
  {
    a_invd[i + 1] = a_invd[i] * a_inv;
    a_invd[i + 1] %= MOD;
    b_invd[i + 1] = b_invd[i] * b_inv;
    b_invd[i + 1] %= MOD;
  }
  for (ll i = a; i < n; i++)
  {
    rep(j, n + 1)
    {
      for (int z = 1; z <= p; z++)
      {
        dpa[min(i + z, n)][j + 1] += dpa[i][j];
        dpa[min(i + z, n)][j + 1] %= MOD;
      }
    }
  }
  for (ll i = b; i < n; i++)
  {
    rep(j, n + 1)
    {
      for (int z = 1; z <= q; z++)
      {
        dpb[min(i + z, n)][j + 1] += dpb[i][j];
        dpb[min(i + z, n)][j + 1] %= MOD;
      }
    }
  }
  ll ans = 0;
  rep(i, n + 1)
  {
    ll k = dpa[n][i] * a_invd[i];
    k %= MOD;
    ll tmp = 0;
    for (int j = n; j >= i; j--)
    {
      tmp += dpb[n][j] * b_invd[j];
      tmp %= MOD;
    }
    ans += k * tmp;
    ans %= MOD;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
