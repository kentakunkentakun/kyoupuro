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

template <class T>
using PQ = priority_queue<T>;

template <class T>
using PQR = priority_queue<T, vector<T>, greater<T>>;

// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 62;
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
  ll n;
  cin >> n;
  vll t(0);
  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      t.pb(i);
      if (n / i != i)
      {
        t.pb(n / i);
      }
    }
  }
  ll ans = 0;
  sort(all(t));
  unordered_map<ll, ll> m;
  rep(i, t.size())
  {
    m[t[i]] = i + 1;
  }
  ll N = t.size();
  // 総積, 個数
  vector<vector<pll>> dp(N + 1, vector<pll>(16));
  // 総和, 通り数
  dp[0][0] = {0, 1};
  vll K(16);
  K[0] = 1;
  rep(i, 15)
  {
    K[i + 1] = K[i] * (i + 1);
    K[i + 1] %= MOD;
  }
  // 次の数字
  rep(i, N)
  {
    ll nx = t[i];
    vector<vector<pll>> ndp = dp;

    rep(k, 15)
    {
      rep(j, N + 1)
      {
        auto [sum, cnt] = dp[j][k];
        if (cnt == 0)
          continue;
        ll it = max(0LL, j - 1);
        ll num = t[it];
        if (num*nx != 0 && n % (num * nx) == 0)
        {
          ll nxit = m[num * nx];
          ndp[nxit][k + 1].F += sum + cnt * nx;
          ndp[nxit][k + 1].F %= MOD;
          ndp[nxit][k + 1].S += cnt;
          ndp[nxit][k + 1].S %= MOD;
        }
      }
    }
    swap(ndp, dp);
  }
  rep(k, 15)
  {
    ans += dp[N][k].F * K[k];
    ans %= MOD;
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
