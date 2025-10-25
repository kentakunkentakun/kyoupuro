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
  ll n, x, y;
  cin >> n >> x >> y;

  vll p(n - 1);
  vll t(n - 1);
  multiset<ll> s;
  rep(i, n - 1)
  {
    cin >> p[i] >> t[i];
    map<ll, ll> soin;
    if (p[i] == 8)
    {
      soin[2] = 3;
    }
    else if (p[i] == 4)
    {
      soin[2] = 2;
    }
    else if (p[i] == 6)
    {
      soin[2] = 1;
      soin[3] = 1;
    }
    else
    {
      soin[p[i]] = 1;
    }
    for (auto [v, cnt] : soin)
    {
      if (s.count(v) < cnt)
      {
        rep(j, cnt - s.count(v))
        {
          s.insert(v);
        }
      }
    }
  }

  ll N = 1;
  for (auto p : s)
  {
    N *= p;
  }
  N = 1680;
  vll d(N + 1);

  rep(i, N + 1)
  {
    ll now = i;
    rep(j, n - 1)
    {
      now += now % p[j] != 0 ? p[j] - (now % p[j]) : 0;
      now += t[j];
    }
    d[i] = now + y;
  }
  ll q;
  cin >> q;
  vll ans(0);
  vll query(q);
  rep(i, q)
  {
    cin >> query[i];
  }
  rep(i, q)
  {
    query[i] += x;
    ans.pb(d[query[i] % N] + (query[i] / N) * N);
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

__builtin_popcount(i)*/
