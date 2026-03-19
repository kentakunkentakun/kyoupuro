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
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
int main()
{
  ll n, k;
  cin >> n >> k;
  vll x(n), y(n), rx(n), ry(n), dx(n + 1), dy(n + 1), drx(n + 1), dry(n + 1);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }
  sort(all(x));
  sort(all(y));
  rep(i, n)
  {
    rx[i] = 1001001001 - x[n - 1 - i];
    ry[i] = 1001001001 - y[n - 1 - i];
  }
  rep(i, n)
  {
    dx[i + 1] += dx[i] + x[i];
    dy[i + 1] += dy[i] + y[i];
    drx[i + 1] += drx[i] + rx[i];
    dry[i + 1] += dry[i] + ry[i];
  }
  auto judge = [&](ll wj) -> bool
  {
    ll costX = INF;
    ll costY = INF;

    rep(i, n)
    {
      ll right = x[i] + wj;
      ll lower_x = lower_bound(all(x), x[i]) - x.begin();
      ll upper_x = (upper_bound(all(x), right) - x.begin());
      ll c = x[i] * (lower_x)-dx[(lower_x)];
      c += dx[n] - dx[upper_x] - right * (n - upper_x);
      chmin(costX, c);
    }

    rep(i, n)
    {
      ll right = rx[i] + wj;
      ll lower_rx = lower_bound(all(rx), rx[i]) - rx.begin();
      ll upper_rx = (upper_bound(all(rx), right) - rx.begin());
      ll c = rx[i] * lower_rx - drx[lower_rx];
      c += drx[n] - drx[upper_rx] - right * (n - upper_rx);
      chmin(costX, c);
    }

    rep(i, n)
    {
      ll right = y[i] + wj;
      ll lower_y = lower_bound(all(y), y[i]) - y.begin();
      ll upper_y = (upper_bound(all(y), right) - y.begin());
      ll c = y[i] * lower_y - dy[lower_y];
      c += dy[n] - dy[upper_y] - right * (n - upper_y);
      chmin(costY, c);
    }

    rep(i, n)
    {
      ll right = ry[i] + wj;
      ll lower_ry = lower_bound(all(ry), ry[i]) - ry.begin();
      ll upper_ry = upper_bound(all(ry), right) - ry.begin();
      ll c = ry[i] * lower_ry - dry[lower_ry];
      c += dry[n] - dry[upper_ry] - right * (n - upper_ry);
      chmin(costY, c);
    }
    if (costX + costY <= k)
    {
      return true;
    }
    else
    {
      return false;
    }
  };
  ll wa = -1, ac = 1e9;
  while (wa + 1 < ac)
  {
    ll mid = (wa + ac) / 2;
    if (judge(mid))
    {
      ac = mid;
    }
    else
    {
      wa = mid;
    }
  }
  cout << ac << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
