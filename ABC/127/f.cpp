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
struct MedianSet
{
  multiset<ll> L, R; // L:小さい半分 R:大きい半分

  ll cost = 0; // 中央値と全値との距離

  void rebalance()
  {
    // サイズ: |L| == |R| または |L| == |R+1|
    while (L.size() < R.size())
    {

      auto it = R.begin();
      cost += (*it - median_lower()) * L.size() - (*it - median_lower()) * R.size();
      L.insert(*it);
      R.erase(it);
    }
    while (L.size() > R.size() + 1)
    {
      auto it = prev(L.end());
      R.insert(*it);
      L.erase(it);
    }
  }
  void add(ll x)
  {

    if (L.empty() || x <= *prev(L.end()))
    {
      if (!L.empty())
      {
        cost += median_lower() - x;
      }
      L.insert(x);
    }
    else
    {
      cost += x - median_lower();
      R.insert(x);
    }
    rebalance();
  }

  void erase_one(ll x)
  {

    auto itL = L.find(x);
    if (itL != L.end())
    {
      L.erase(itL);
    }
    else
    {
      auto itR = R.find(x);
      if (itR != R.end())
        R.erase(itR);
    }
    rebalance();
  }

  ll median_lower()
  {
    if (L.empty())
    {
      return -1;
    }
    return *prev(L.end());
  }
  ll median_upper()
  {
    if (L.empty())
    {
      return -1;
    }
    if (L.size() > R.size())
      return *prev(L.end());
    return *R.begin();
  }
  ll get_cost()
  {
    return cost;
  }
  int size() const
  {
    return (int)L.size() + (int)R.size();
  }
};

int main()
{
  ll q;
  cin >> q;
  ll c = 0;
  MedianSet ms;
  rep(i, q)
  {
    ll op;
    cin >> op;
    if (op == 1)
    {
      ll a, b;
      cin >> a >> b;
      c += b;
      ms.add(a);
    }
    else
    {
      cout << ms.median_lower() << " " << ms.get_cost() + c << endl;
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
