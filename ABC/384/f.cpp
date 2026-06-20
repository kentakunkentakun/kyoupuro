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
struct PairHash
{
  size_t operator()(const pll &p) const
  {
    return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
  }
};
int main()
{
  ll n;
  cin >> n;
  vll a(n);
  rep(i, n) cin >> a[i];
  vector<pll> p(n);
  rep(i, n)
  {
    ll t = a[i];
    ll cnt = 0;
    while (t % 2 == 0)
    {
      t /= 2;
      cnt++;
    }
    p[i] = {cnt, a[i]};
  }
  sort(all(p));

  map<ll, vector<ll>> m;
  rep(i, n)
  {
    auto [cnt, v] = p[i];
    m[cnt].pb(v);
  }
  ll ans = 0;
  ll sum = 0;
  vector<ll> d(24);

  for (auto [cnt, v] : m)
  {
    ans += sum * v.size();
    for (auto p : v)
    {
      ll t = p;
      rep(i, 24)
      {
        if (t % 2)
        {
          break;
        }
        ans += d[i] * t;
        t /= 2;
      }
      sum += t;
    }
    for (auto p : v)
    {
      ll t = p;
      rep(i, 24)
      {
        if (t % 2)
        {
          d[i]++;
          break;
        }
        t /= 2;
      }
    }

    // 2のk,あまり -> cnt,sum
    unordered_map<pll, pll, PairHash> m;
    for (auto p : v)
    {
      ll t = 2;
      rep(i, 24)
      {
        m[{t, p % t}].F++;
        m[{t, p % t}].S += p;
        t *= 2;
      }
      t = 2;

      pll res = {m[{t, (t - p % t) % t}].F, m[{t, (t - p % t) % t}].S};
      rep(i, 24)
      {
        t *= 2;
        pll tmp = {m[{t, (t - p % t) % t}].F,
                   m[{t, (t - p % t) % t}].S};

        if (res.F > tmp.F)
        {
          ans += ((res.F - tmp.F) * p + res.S - tmp.S) / (t / 2);
          res = tmp;
        }
        if (res.F == 0)
          break;
      }
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
