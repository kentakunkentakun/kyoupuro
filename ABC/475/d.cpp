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
ll n = 1e8;
// エラトステネスの篩
vll arr(n);
void Eratosthenes()
{
  for (ll i = 2; i < n; i++)
  {
    arr[i] = 1;
  }
  for (int i = 2; i < sqrt(n); i++)
  {
    if (arr[i])
    {
      for (int j = 0; i * (j + 2) < n; j++)
      {
        arr[i * (j + 2)] = 0;
      }
    }
  }

  for (int i = 2; i < n; i++)
  {
    if (arr[i])
    {
      // cout << i << endl;
    }
  }
}
string s;
vll c(26, -1);
ll num = 0;
vll used(10, 0);
ll dfs(ll now)
{
  if (now == s.size())
  {
    if (arr[num])
    {
      return num;
    }
    return -1;
  }
  ll cc = s[now] - 'a';
  num *= 10;
  if (c[cc] != -1)
  {
    num += c[cc];
    ll RES = dfs(now + 1);
    num -= c[cc];
    num /= 10;
    return RES;
  }
  else
  {
    ll S = 0;
    if (now == 0)
      S++;
    for (int i = S; i <= 9; i++)
    {
      if (used[i])
        continue;
      num += i;
      c[s[now] - 'a'] = i;
      used[i] = 1;
      ll res = dfs(now + 1);
      if (res != -1)
      {
        return res;
      }
      c[s[now] - 'a'] = -1;
      used[i] = 0;
      num -= i;
    }
  }
  num /= 10;
  return -1;
};
int main()
{
  cin >> s;
  Eratosthenes();
  ll res = dfs(0);
  cout << res << endl;
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
