#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define ul unsigned long long
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll k;
  cin >> k;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vvll used(n, vll(n, -1));
  set<ul> u;
  vvll dist(n, vll(n, 0));
  auto bfs = [&](auto bfs, ll x, ll y, ll remain, ll num, ll px, ll py) -> void
  {
    if (remain == 0)
    {
      u.insert(num);
      return;
    }
    rep(i, 4)
    {
      ll nx = dx[i] + x;
      ll ny = dy[i] + y;
      if (isIn(nx, ny, n, n) && s[nx][ny] == '.' && used[nx][ny] == -1)
      {
        used[nx][ny] = 0;
        dist[nx][ny] = dist[x][y] + 1;
        bfs(bfs, nx, ny, remain - 1, num + (1UL << (nx + 8 * ny)), x, y);
        dist[nx][ny] = 0;
        used[nx][ny] = -1;
      }
      else if (isIn(nx, ny, n, n) && s[nx][ny] == '.' && used[nx][ny] == 0 && (dist[nx][ny] < dist[x][y]))
      {
        bfs(bfs, nx, ny, remain, num, x, y);
      }
    }
  };
  rep(i, n)
  {
    rep(j, n)
    {
      if (s[i][j] == '.')
      {
        used[i][j] = 0;
        dist[i][j] = 0;
        bfs(bfs, i, j, k - 1, 1UL << (i + j * 8), i, j);
        used[i][j] = -1;
      }
    }
  }
  cout << u.size() << endl;
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
