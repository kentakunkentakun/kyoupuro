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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  rep(i, n)
  {
    if (s[i] != '1')
    {
      if (i - 1 >= 0 && s[i - 1] != '1')
      {
        cout << -1 << endl;
        return 0;
      }
      if (i + 1 < n && s[i + 1] != '1')
      {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  reverse(all(s));
  ll ans = 0;
  rep(i, n)
  {
    if (i == 0)
    {
      ans++;
      continue;
    }
    ll c = (s[i - 1] - '0') - 1;
    ans += c * ans + 1;
    ans %= MOD;
  }
  cout << ans - 1 << endl;
  // string tmp = s;
  // ll cnt = 0;
  // while (s.size())
  // {
  //   cnt++;
  //   string tmp = "";
  //   rep(i, s.size() - 1)
  //   {
  //     rep(j, s[i + 1] - '0')
  //     {
  //       tmp += s[i];
  //     }
  //   }
  //   // cout << tmp << endl;
  //   swap(s, tmp);
  // }
  // ll n = tmp.size();
  // s = tmp;
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
