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
  vll a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll q;
  cin >> q;
  rep(i, q)
  {
    ll x, y;
    cin >> x >> y;
  }
  a.pb(INF);
  b.pb(INF);
  vector<pll> sa(0);
  vector<pll> sb(0);
  ll b_iter = 0;
  ll b_before = 0;
  ll a_iter = 0;
  ll a_before = 0;
  set<ll> b_need;
  set<ll> a_need;
  set<ll> b_have;
  set<ll> a_have;
  while (1)
  {
    if (a[a_iter] != b[b_iter])
    {
      
      if (a_need.count(a[a_iter]))
      {
        a_need.erase(a[a_iter]);
      }
      if (b_need.count(b[b_iter]))
      {
        b_need.erase(b[b_iter]);
      }
      a_need.insert(a[a_iter]);
      b_need.insert(b[b_iter]);
    }
    while (a[a_iter] == a[a_iter + 1])
      a_iter++;
    while (b[b_iter] == b[b_iter + 1])
      b_iter++;
    a_iter++;
    b_iter++;
    sa.pb(pll(a_before, a_iter));
    sb.pb(pll(b_before, b_iter));
    a_before = a_iter;
    b_before = b_iter;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
