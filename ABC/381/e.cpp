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
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vll one(0);
  vll two(0);
  vll slash(0);
  rep(i, n)
  {
    if (s[i] == '1')
      one.pb(i);
    if (s[i] == '2')
      two.pb(i);
    if (s[i] == '/')
      slash.pb(i);
  }
  auto judge = [&](ll l, ll r, ll mid) -> bool
  {
    if (mid == 0)
    {
      ll slash_iter = lower_bound(all(slash), l) - slash.begin();
      if (slash_iter == slash.size() || slash[slash_iter] > r)
      {
        return false;
      }
      return true;
    }
    ll one_l = lower_bound(all(one), l) - one.begin();
    if (one.size() <= one_l + mid - 1 || one[one_l + mid - 1] > r)
    {
      return false;
    }
    ll slash_iter = lower_bound(all(slash), one[one_l + mid - 1]) - slash.begin();
    if (slash_iter == slash.size() || slash[slash_iter] > r)
    {
      return false;
    }
    ll two_l = lower_bound(all(two), slash[slash_iter]) - two.begin();
    if (two.size() <= two_l + mid - 1 || two[two_l + mid - 1] > r)
    {
      return false;
    }
    return true;
  };
  rep(i, q)
  {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    ll left = 0;
    ll right = n;
    while (left + 1 < right)
    {
      ll mid = (left + right) / 2;
      if (judge(l, r, mid))
      {
        left = mid;
      }
      else
      {
        right = mid;
      }
    }
    if (left == 0)
    {
      ll slash_iter = lower_bound(all(slash), l) - slash.begin();
      if (slash_iter == slash.size() || slash[slash_iter] > r)
      {
        cout << 0 << endl;
      }
      else
      {
        cout << 1 << endl;
      }
    }
    else
    {
      cout << left * 2 + 1 << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
