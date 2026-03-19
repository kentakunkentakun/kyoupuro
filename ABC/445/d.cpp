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
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
const double INF_D = numeric_limits<double>::infinity();
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
ll MA = 1e7 + 5;
// vll arr(MA, 0);
// vector<ll> insu(MA);

// void Eratosthenes()
// {
//   for (ll i = 2; i < MA; i++)
//   {
//     arr[i] = 1;
//     insu[i] = i;
//   }
//   for (int i = 2; i < sqrt(MA); i++)
//   {
//     if (arr[i])
//     {
//       for (int j = 0; i * (j + 2) < MA; j++)
//       {
//         arr[i * (j + 2)] = 0;
//         insu[i * (j + 2)] = i;
//       }
//     }
//   }
// }
vll arr(MA, 0);
vector<ll> insu(MA);

void Eratosthenes()
{
  vll prime_list(0);
  for (int i = 2; i <= MA; i++)
  {
    if (insu[i] == 0)
    {
      insu[i] = i;
      prime_list.pb(i);
    }
    for (auto p : prime_list)
    {
      if (p * i > MA || p > insu[i])
        break;
      insu[p * i] = p;
    }
  }
}
// a^n mod を計算する

long long modpow(long long a, long long n, long long mod)
{
  a %= mod;
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
long long modinv(long long a, long long mod)
{
  return modpow(a, mod - 2, mod);
}
int main()
{
  Eratosthenes();
  ll t;
  cin >> t;
  rep(T, t)
  {
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    map<ll, pll> m;
    vector<vector<pll>> insu_rui(n, vector<pll>(0));
    rep(i, n)
    {
      ll tmp = a[i];
      ll cnt = 0;
      if (a[i] == 1)
      {
        insu_rui[i].pb({1, 1});
        continue;
      }
      while (tmp != 1)
      {
        ll cnt = 0;
        ll ss = insu[tmp];
        while (tmp % ss == 0)
        {
          cnt++;
          tmp /= ss;
        }
        insu_rui[i].pb({ss, cnt});
      }
    }
    rep(i, n)
    {
      for (auto p : insu_rui[i])
      {
        auto [num, cnt] = p;
        auto [f, s] = m[num];
        if (cnt > s)
        {
          if (f > cnt)
          {
            m[num] = {f, cnt};
          }
          else
          {
            m[num] = {cnt, f};
          }
        }
      }
    }
    ll res = 1;
    for (auto p : m)
    {
      auto [num, pp] = p;
      res = res * modpow(num, pp.first, MOD);
      res %= MOD;
    }
    // cout << T << " " << res << endl;
    rep(i, n)
    {
      ll tmp = res;
      for (auto p : insu_rui[i])
      {
        auto [num, cnt] = p;
        auto [f, s] = m[num];
        if (cnt == f && f != s)
        {
          ll div = modpow(num, (f - s), MOD);
          tmp *= modinv(div, MOD);
          tmp %= MOD;
        }
      }
      cout << tmp << " ";
    }
    cout << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
