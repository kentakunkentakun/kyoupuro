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
        c[i][j] = (c[i][j] + A[i][k] * B[k][j]) % MOD;
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
    B[i][i] = 1;
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
  ll h, w;
  cin >> h >> w;
  mat a((1 << h), vec((1 << h)));
  vll k(7);
  k[0] = 1;
  k[1] = 1;
  k[2] = 2;
  k[3] = 3;
  k[4] = 5;
  k[5] = 8;
  k[6] = 13;
  for (int bit = 0; bit < (1 << h); bit++)
  {
    ll s = (1 << h) - 1;
    s -= bit;
    for (int sub = s; sub >= 0; sub = (sub - 1) & s)
    {
      ll t = s ^ sub;
      vll tmp(0);
      ll cnt = 0;
      rep(i, h)
      {
        if (t >> i & 1)
        {
          cnt++;
        }
        else
        {
          tmp.pb(cnt);
          cnt = 0;
        }
      }
      tmp.pb(cnt);
      ll res = 1;
      rep(i, tmp.size())
      {
        res *= k[tmp[i]];
      }
      a[sub][bit] += res;
      a[sub][bit] %= MOD;
      if (sub == 0)
        break;
    }
  }
  mat res = pow(a, w);
  cout << res[0][0] << endl;
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
