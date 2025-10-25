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
const ll MOD = 1000000007LL;
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
<<<<<<< Updated upstream
  string x;
  cin >> x;
  vll a(x.size());
  rep(i, x.size())
  {
    a[i] = x[i] - '0';
  }
  ll m;
  cin >> m;
  reverse(all(a));
  if (a.size() == 1)
  {
    if (a[0] <= m)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
    return 0;
  }
  auto judge = [&](__int128 wj) -> bool
  {
    __int128 sum = 0;
    __int128 cnt = 1;
    rep(i, a.size())
    {
      if (cnt > m)
      {
        return false;
      }
      sum += a[i] * cnt;
      cnt *= wj;

      if (sum > m)
      {
        return false;
      }
    }
    return true;
  };
  __int128 ac = 0;
  __int128 wa = INF;
  while (ac + 1 < wa)
  {
    __int128 mid = (ac + wa) / 2;
    if (judge(mid))
    {
      ac = mid;
    }
    else
    {
      wa = mid;
    }
  }
  __int128 ma = 0;
  rep(i, a.size())
  {
    chmax(ma, (__int128)a[i]);
  }
  cout << max((ll)(ac - ma), 0LL) << endl;
=======
>>>>>>> Stashed changes
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
<<<<<<< Updated upstream
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
=======

>>>>>>> Stashed changes
__builtin_popcount(i)*/
