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
struct point
{
  ll x, y, iter;
};

long long cross(const point &a, const point &b)
{
  return a.x * b.y - a.y * b.x;
}

bool cmp(const point &a, const point &b)
{
  ll ah = (a.y < 0 or (a.y == 0 and a.x < 0));
  ll bh = (b.y < 0 or (b.y == 0 and b.x < 0));
  if (ah != bh)
    return ah < bh;
  return cross(a, b) > 0;
}
bool cmp2(const point &a, const point &b)
{
  ll ah = (a.y < 0 or (a.y == 0 and a.x < 0));
  ll bh = (b.y < 0 or (b.y == 0 and b.x < 0));
  if (ah != bh)
    return true;
  return cross(a, b) != 0;
}

void argument_sort(vector<point> &points)
{
  sort(points.begin(), points.end(), cmp);
}

int main()
{
  ll n, q;
  cin >> n >> q;
  vll x(n), y(n);
  vector<point> p(n);
  rep(i, n)
  {
    cin >> p[i].x >> p[i].y;
    p[i].iter = i;
  }
  argument_sort(p);
  ll iter = 0;
  vll d(n + 1);
  vll it(n);
  rep(i, n)
  {
    if (i == 0 || cmp2(p[i - 1], p[i]))
    {
      iter++;
      d[iter] += d[iter - 1];
    }
    d[iter]++;
    it[p[i].iter] = iter;
  }
  rep(i, q)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    if (it[a] < it[b])
    {
      cout << d[it[a]] + d[iter] - d[it[b] - 1] << endl;
    }
    else
    {
      cout << d[it[a]] - d[it[b] - 1] << endl;
    }
  }
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
