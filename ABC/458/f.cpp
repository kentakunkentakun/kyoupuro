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

struct Aho
{
  using MP = unordered_map<char, ll>;
  vector<MP> to;
  vector<bool> bad;
  vector<ll> fail;
  Aho() : to(1), bad(1) {}
  ll add(const string &s)
  {
    ll v = 0;
    for (char c : s)
    {
      if (!to[v].count(c))
      {
        to[v][c] = to.size();
        to.push_back(MP());
        bad.pb(false);
      }
      v = to[v][c];
    }
    bad[v] = true;
    return v;
  }
  void init()
  {
    fail = vector<ll>(to.size(), -1);
    queue<ll> q;
    q.push(0);
    while (!q.empty())
    {
      ll v = q.front();
      q.pop();
      for (auto [c, u] : to[v])
      {
        fail[u] = (*this)(fail[v], c);
        bad[u] = bad[u] || bad[fail[u]];
        q.push(u);
      }
    }
  }
  ll operator()(ll v, char c) const
  {
    while (v != -1)
    {
      auto it = to[v].find(c);
      if (it != to[v].end())
        return it->second;
      v = fail[v];
    }
    return 0;
  }
  ll size() const
  {
    return to.size();
  }
  bool operator[](ll v) const
  {
    return bad[v];
  }
};
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
  ll n, k;
  cin >> n >> k;
  Aho aho;
  rep(i, k)
  {
    string s;
    cin >> s;
    aho.add(s);
  }
  aho.init();
  ll m = aho.size();
  mat M(m, vec(m));
  rep(i, m)
  {
    for (char c = 'a'; c <= 'z'; c++)
    {
      ll k = aho(i, c);
      if (!aho.bad[k])
      {
        M[i][k]++;
      }
    }
  }
  mat R = pow(M, n);
  ll ans = 0;
  rep(i, m)
  {
    ans += R[0][i];
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
