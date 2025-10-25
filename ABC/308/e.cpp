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
  ll n;
  cin >> n;
  vll a(n);
  rep(i, n) cin >> a[i];
  string s;
  cin >> s;
  vll m(3, 0);
  vll x(3, 0);
  rep(i, n)
  {
    if (s[i] == 'X')
    {
      x[a[i]]++;
    }
  }
  ll ans = 0;
  rep(i, n)
  {
    bool ch = (m[0] == 0 && m[1] == 0 && m[2] == 0) || (x[0] == 0 && x[1] == 0 && x[2] == 0);
    if (!ch && s[i] == 'E')
    {
      if (a[i] == 0)
      {
        ans += 1 * ((m[2] + m[0]) * (x[0] + x[2]));
        ans += 2 * ((m[0] + m[1]) * (x[0] + x[1]) - (m[0] * x[0]));
        ans += 3 * (m[1] * x[2] + m[2] * x[1]);
      }
      if (a[i] == 1)
      {
        ans += 2 * ((m[0] + m[1]) * (x[0] + x[1]) - m[1] * x[1]);
        ans += 3 * (m[0] * x[2] + m[2] * x[0]);
      }
      if (a[i] == 2)
      {
        ans += 1 * (x[0] * m[0] + m[0] * x[2] + m[2] * x[0]);
        ans += 3 * (m[0] * x[1] + m[1] * x[0]);
      }
    }
    if (s[i] == 'X')
    {
      x[a[i]]--;
    }
    if (s[i] == 'M')
    {
      m[a[i]]++;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
