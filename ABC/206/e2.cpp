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
struct Eratosthenes
{
  // テーブル
  vector<bool> isprime;

  // 整数 i を割り切る最小の素数
  vector<ll> minfactor;

  // メビウス関数値
  vector<int> mobius;

  // コンストラクタで篩を回す
  Eratosthenes(ll N) : isprime(N + 1, true),
                       minfactor(N + 1, -1),
                       mobius(N + 1, 1)
  {
    // 1 は予めふるい落としておく
    isprime[1] = false;
    minfactor[1] = 1;

    // 篩
    for (ll p = 2; p <= N; ++p)
    {
      // すでに合成数であるものはスキップする
      if (!isprime[p])
        continue;

      // p についての情報更新
      minfactor[p] = p;
      mobius[p] = -1;

      // p 以外の p の倍数から素数ラベルを剥奪
      for (ll q = p * 2; q <= N; q += p)
      {
        // q は合成数なのでふるい落とす
        isprime[q] = false;

        // q は p で割り切れる旨を更新
        if (minfactor[q] == -1)
          minfactor[q] = p;
        if ((q / p) % p == 0)
          mobius[q] = 0;
        else
          mobius[q] = -mobius[q];
      }
    }
  }

  // 高速素因数分解
  // pair (素因子, 指数) の vector を返す
  vector<pair<ll, ll>> factorize(ll n)
  {
    vector<pair<ll, ll>> res;
    while (n > 1)
    {
      ll p = minfactor[n];
      ll exp = 0;

      // n で割り切れる限り割る
      while (minfactor[n] == p)
      {
        n /= p;
        ++exp;
      }
      res.emplace_back(p, exp);
    }
    return res;
  }

  // 高速約数列挙
  vector<ll> divisors(ll n)
  {
    vector<ll> res({1});

    // n を素因数分解 (メンバ関数使用)
    auto pf = factorize(n);

    // 約数列挙
    for (auto p : pf)
    {
      ll s = (ll)res.size();
      for (ll i = 0; i < s; ++i)
      {
        ll v = 1;
        for (ll j = 0; j < p.second; ++j)
        {
          v *= p.first;
          res.push_back(res[i] * v);
        }
      }
    }
    return res;
  }
};

int main()
{
  ll l, r;
  cin >> l >> r;
  Eratosthenes er(r + 1);
  ll ans = 0;
  vll d(r + 1);
  for (ll i = r; i > 1; i--)
  {
    ll res = r / i - (l - 1) / i;
    auto div = er.divisors(i);
    for (auto v : div)
    {
      if (v == i)
        continue;
      d[v] += res * (res - 1) - d[i];
    }
    if (l - 1 < i)
      res--;
    ans += res * (res - 1) - d[i];
  }
  cout << ans << endl;
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
