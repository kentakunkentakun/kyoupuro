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
// gcd lcm
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
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
        c[i][j] = (c[i][j] + A[i][k] * B[k][j]);
      }
    }
  }
  return c;
}
vec mul_v(mat &A, vec B)
{
  vec C(B.size());
  rep(i, A.size())
  {
    rep(j, B.size())
    {
      C[i] += A[i][j] * B[j];
    }
  }
  return C;
}
int main()
{
  ll n;
  cin >> n;
  vll x(n), y(n);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }

  mat t(3, vec(3));
  t[0][0] = 1;
  t[1][1] = 1;
  t[2][2] = 1;

  ll m;
  cin >> m;
  vector<pll> op(m);
  rep(i, m)
  {
    cin >> op[i].F;
    if (op[i].F > 2)
    {
      cin >> op[i].S;
    }
  }
  ll q;
  cin >> q;
  map<ll, vector<pll>> query;
  rep(i, q)
  {
    ll a, b;
    cin >> a >> b;
    b--;
    query[a].pb({b, i});
  }
  vector<pll> ans(q);
  rep(i, m + 1)
  {
    if (query.count(i))
    {
      for (auto [b, it] : query[i])
      {
        vec ini(3);
        ini[0] = x[b];
        ini[1] = y[b];
        ini[2] = 1;
        vec res = mul_v(t, ini);
        ans[it] = {res[0], res[1]};
      }
    }
    if (i == m)
      break;
    auto [q, p] = op[i];
    mat s(3, vec(3));
    if (q == 1)
    {
      s[0][1] = 1;
      s[1][0] = -1;
      s[2][2] = 1;
    }
    else if (q == 2)
    {
      s[0][1] = -1;
      s[1][0] = 1;
      s[2][2] = 1;
    }
    else if (q == 3)
    {
      s[0][0] = -1;
      s[0][2] = 2 * p;
      s[1][1] = 1;
      s[2][2] = 1;
    }
    else
    {
      s[0][0] = 1;
      s[1][1] = -1;
      s[1][2] = 2 * p;
      s[2][2] = 1;
    }
    t = mul(s, t);
  }
  rep(i, q)
  {
    cout << ans[i].F << " " << ans[i].S << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
