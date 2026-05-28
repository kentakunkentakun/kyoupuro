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
  ll k;
  cin >> n >> k;
  string s = to_string(n);
  ll N = s.size();
  vvll u(4, vll(60, 0));
  vll tmp = {2, 3, 5, 7};
  rep(i, 4)
  {
    u[i][0] = 1;
    rep(j, 55)
    {
      u[i][j + 1] = u[i][j] * tmp[i];
      if (u[i][j + 1] > k)
      {
        break;
      }
    }
  }
  vvll t(10, vll(0));
  t[0].pb(0);
  t[1].pb(1);
  t[2].pb(2);
  t[3].pb(3);
  t[4].pb(2);
  t[4].pb(2);
  t[5].pb(5);
  t[6].pb(2);
  t[6].pb(3);
  t[7].pb(7);
  t[8].pb(2);
  t[8].pb(2);
  t[8].pb(2);
  t[9].pb(3);
  t[9].pb(3);
  map<tuple<ll, ll, ll, ll>, ll> dp[5], ndp[5];
  ndp[0][{0, 0, 0, 0}] = 1;
  rep(i, s.size())
  {
    ll now = s[i] - '0';
    swap(ndp, dp);
    map<tuple<ll, ll, ll, ll>, ll> tmp[5];
    swap(ndp, tmp);
    rep(j, 10)
    {
      rep(z, 5)
      {
        for (auto [T, v] : dp[z])
        {
          auto [a, b, c, d] = T;

          for (auto p : t[j])
          {
            if (p == 2)
            {
              a++;
            }
            else if (p == 3)
            {
              b++;
            }
            else if (p == 5)
            {
              c++;
            }
            else if (p == 7)
            {
              d++;
            }
          }

          if (z == 1)
          {
            if (j == now)
            {
              ndp[1][{0, 0, 0, 0}] += v;
            }
            else if (j < now)
            {
              ndp[3][{0, 0, 0, 0}] += v;
            }
            continue;
          }
          if (z == 3)
          {
            ndp[3][{0, 0, 0, 0}] += v;
            continue;
          }
          if (z == 0)
          {
            if (j == now)
            {
              if (j == 0)
              {
                ndp[1][{0, 0, 0, 0}] += v;
              }
              else
              {
                ndp[0][{a, b, c, d}] += v;
              }
            }
            else if (j < now)
            {
              if (j == 0)
              {
                if (i != 0)
                  ndp[3][{0, 0, 0, 0}] += v;
                else
                {
                  ndp[4][{0, 0, 0, 0}] += v;
                }
              }
              else
              {
                ndp[2][{a, b, c, d}] += v;
              }
            }
          }
          if (z == 2)
          {
            if (j == 0)
            {
              ndp[3][{0, 0, 0, 0}] += v;
            }
            else
              ndp[2][{a, b, c, d}] += v;
          }
          if (z == 4)
          {
            if (j == 0)
            {
              ndp[4][{0, 0, 0, 0}] += v;
            }
            else
            {
              ndp[2][{a, b, c, d}] += v;
            }
          }
        }
      }
    }
  }
  ll ans = 0;
  rep(i, 5) for (auto [T, v] : ndp[i])
  {
    auto [a, b, c, d] = T;
    
    ll nx = 1;
    nx *= u[0][a];
    nx *= u[1][b];
    if (nx > k)
      nx = 0;
    nx *= u[2][c];
    if (nx > k)
      nx = 0;
    nx *= u[3][d];
    if (nx > k)
      nx = 0;
    if (nx == 0)
      continue;
    ans += v;
  }
  ans--;
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
