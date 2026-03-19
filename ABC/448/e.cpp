#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
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
// const ll MOD = 10007LL;
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
int main()
{
  ll k, m;
  cin >> k >> m;
  const ll MOD = m * 10007;
  auto kee = [&](ll keta) -> ll
  {
    ll now = 10;
    ll res = 1;
    while (keta)
    {
      if (keta % 2)
      {
        res *= now;
        res %= MOD;
      }
      now *= now;
      now %= MOD;
      keta /= 2;
    }
    return res;
  };
  auto f = [&](ll v, ll keta) -> ll
  {
    ll now = v % MOD;
    ll res = 0;
    ll k = 10;
    ll cnt = 1;
    ll now_cnt = 0;

    while (keta)
    {
      if (keta % 2)
      {
        res += now * kee(now_cnt);
        res %= MOD;
        now_cnt += cnt;
      }
      now *= (k + 1);
      now %= MOD;
      k *= k;
      k %= MOD;
      cnt *= 2;
      keta /= 2;
    }
    return res;
  };

  ll ans = 0;
  ll keta = 0;
  rep(i, k)
  {
    ll c, l;
    cin >> c >> l;
    ll res = f(c, l);
    ans *= kee(l);
    ans += res;
    ans %= MOD;
    ans %= MOD;
  }
  cout << ans / m << endl;
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
