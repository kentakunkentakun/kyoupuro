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
ll n;
vll T(15);
string s;
ll dfs(int i, int deep)
{
  if (deep == n)
  {
    if (s[i - 1 - T[deep - 1]] == '1')
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  vll s(3);
  s[0] = dfs(3 * i - 1, deep + 1);
  s[1] = dfs(3 * i, deep + 1);
  s[2] = dfs(3 * i + 1, deep + 1);

  return min(s[0] + s[1], min(s[0] + s[2], s[1] + s[2]));
}
ll dfs0(int i, int deep)
{
  if (deep == n)
  {
    if (s[i - 1 - T[deep - 1]] == '0')
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  vll s(3);
  s[0] = dfs0(3 * i - 1, deep + 1);
  s[1] = dfs0(3 * i, deep + 1);
  s[2] = dfs0(3 * i + 1, deep + 1);

  return min(s[0] + s[1], min(s[0] + s[2], s[1] + s[2]));
}
int main()
{
  T[0] = 1LL;
  ll cnt = 1;
  for (int i = 1; i < 15; i++)
  {
    T[i] = cnt * 3 + T[i - 1];
    cnt *= 3;
  }

  cin >> n;
  cin >> s;
  cout << max(dfs(1, 0), dfs0(1, 0)) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
