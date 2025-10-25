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
  vll w(n), b(n);
  rep(i, n) cin >> w[i];
  rep(i, n) cin >> b[i];
  vvll g(55, vll(1500, 0));
  rep(i, 51)
  {
    multiset<ll> s;
    rep(j, 1400)
    {
      if (i >= 1)
      {
        s.insert(g[i - 1][j + i]);
      }
      if (j >= 2)
      {
        if (j % 2)
        {
          s.erase(s.find(g[i][(j - 1) / 2]));
          s.insert(g[i][j - 1]);
        }
        else
        {
          s.insert(g[i][j - 1]);
        }
      }
      while (s.find(g[i][j]) != s.end())
        g[i][j]++;
      if (i >= 1)
      {
        s.erase(s.find(g[i - 1][j + i]));
      }
    }
  }
  ll xorSum = 0;
  rep(i, n)
  {
    xorSum ^= g[w[i]][b[i]];
  }
  if (xorSum != 0)
  {
    cout << "First" << endl;
  }
  else
  {
    cout << "Second" << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
