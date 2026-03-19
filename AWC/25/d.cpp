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
int main()
{
  ll n, s, q;
  cin >> n >> s >> q;
  vector<pll> x(n);
  rep(i, n)
  {
    cin >> x[i].F;
    x[i].S = i;
  }
  vb used(n);
  sort(all(x));
  ll now = 0;
  rep(i, n)
  {
    if (x[i].S == s - 1)
      now = i;
  }

  used[now] = true;
  ll cnt = q;
  rep(i, min(2 * n, q))
  {
    if (now > 0 && now < n - 1)
    {
      if (abs(x[now - 1].F - x[now].F) < abs(x[now].F - x[now + 1].F))
      {
        now--;
        used[now] = true;
      }
      else if (abs(x[now - 1].F - x[now].F) == abs(x[now + 1].F - x[now].F))
      {
        if (x[now - 1].S < x[now + 1].S)
        {
          now--;
          used[now] = true;
        }
        else
        {
          now++;
        }
      }
      else
      {
        now++;
        used[now] = true;
      }
    }
    else if (now > 0)
    {
      now--;
      used[now] = true;
    }
    else
    {
      now++;
      used[now] = true;
    }
    cnt--;
  }

  if (cnt > 0)
  {
    if (cnt % 2 == 0)
    {
      cout << x[now].S + 1 << endl;
    }
    else
    {
      if (now > 0 && now < n - 1)
      {
        if (abs(x[now - 1].F - x[now].F) < abs(x[now].F - x[now + 1].F))
        {
          now--;
          used[now] = true;
        }
        else if (abs(x[now - 1].F - x[now].F) == abs(x[now + 1].F - x[now].F))
        {
          if (x[now - 1].S < x[now + 1].S)
          {
            now--;
            used[now] = true;
          }
          else
          {
            now++;
          }
        }
        else
        {
          now++;
          used[now] = true;
        }
      }
      else if (now > 0)
      {
        now--;
        used[now] = true;
      }
      else
      {
        now++;
        used[now] = true;
      }
      cout << x[now].S + 1 << endl;
    }
  }
  else
  {
    cout << x[now].S + 1 << endl;
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
