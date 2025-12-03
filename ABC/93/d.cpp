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
// const ll MOD = 1000000007LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
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
  ll q;
  cin >> q;
  auto judge = [&](ll wj, ll v, ll ma) -> bool
  {
    if (v > (ma + 1) * wj)
    {
      return true;
    }
    else
    {
      return false;
    }
  };
  vll ans(q);

  rep(i, q)
  {
    ll a, b;
    cin >> a >> b;
    if (a < b)
      swap(a, b);
    ll ac = 0, wa = a;
    while (ac + 1 < wa)
    {
      ll wj = (ac + wa) / 2;
      if (judge(wj, a * b, b))
      {
        ac = wj;
      }
      else
      {
        wa = wj;
      }
    }

    ll a_cnt = 0;
    ll tmp = ac;
    ll k = 0;
    while (tmp > 0)
    {
      k = (a * b - 1) / tmp;
      a_cnt++;
      k++;
      ll tm = (a * b - 1) / k;
      tmp = tm;
    }
    a_cnt += tmp;
    ac = 0, wa = b;
    while (ac + 1 < wa)
    {
      ll wj = (ac + wa) / 2;
      if (judge(wj, a * b, a))
      {
        ac = wj;
      }
      else
      {
        wa = wj;
      }
    }
    ll b_cnt = 0;
    tmp = ac;
    k = 0;
    while (tmp > 0)
    {
      k = (a * b - 1) / tmp;
      b_cnt++;
      k++;
      ll tm = (a * b - 1) / k;
      tmp = tm;
    }
    b_cnt += tmp;

    ans[i] = a_cnt + b_cnt + min(a - 1 - a_cnt, b - 1 - b_cnt);
  }
  rep(i, q)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
