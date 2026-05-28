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
typedef vector<ll> vec;
typedef vector<vec> mat;

// A*Bの計算
mat mul(mat &A, mat &B)
{
  mat c(A.size(), vec(B[0].size()));
  for (int i = 0; i < A.size(); i++)
  {
    for (int k = 0; k < B.size(); k++)
    {
      for (int j = 0; j < B[0].size(); j++)
      {
        c[i][j] = (c[i][j] ^ (A[i][k] & B[k][j]));
      }
    }
  }
  return c;
}

// A^nの計算
mat pow(mat A, ll n)
{
  mat B(A.size(), vec(A.size()));
  for (int i = 0; i < A.size(); i++)
  {
    B[i][i] = (1LL << 32) - 1;
  }
  while (n > 0)
  {
    if (n & 1)
      B = mul(B, A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

int main()
{
  ll k, m;
  cin >> k >> m;
  vll a(k), c(k);
  rep(i, k) cin >> a[i];
  rep(i, k) cin >> c[i];
  if (m <= k)
  {
    cout << a[m - 1] << endl;
    return 0;
  }
  reverse(all(a));
  mat r(k, vec(k));
  rep(i, k)
  {
    r[0][i] = c[i];
  }
  rep(i, k - 1)
  {
    r[i + 1][i] = (1LL << 32) - 1;
  }
  mat C = pow(r, m - k);
  vec res(k);
  for (int u = 0; u < res.size(); u++)
  {
    for (int j = 0; j < res.size(); j++)
    {
      res[u] = (res[u] ^ (C[u][j] & a[j]));
    }
  }
  cout << res[0] << endl;
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
