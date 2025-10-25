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
  ll n, m;
  cin >> n >> m;
  vll a(n);
  set<ll> s;
  rep(i, 2 * 100001)
  {
    s.insert(i);
  }
  rep(i, n) cin >> a[i];

  // いずれ0~nに入る者たち。
  vector<tuple<ll, ll, ll>> start(0);
  rep(i, n)
  {
    if (a[i] < 0)
    {
      ll re = (0 - a[i] + i) / (i + 1);
      if (re * (i + 1) + a[i] < 0)
        continue;
      start.pb({re, i + 1, a[i] + re * (i + 1)});
    }
  }
  vector<pll> now(n);
  sort(all(start));
  ll iter = 0;
  unordered_set<ll> si;

  rep(i, n)
  {
    if (a[i] >= 0 && a[i] <= n)
    {
      now[i] = pll(i + 1, a[i]);
      s.erase(a[i]);
      si.insert(i);
    }
  }

  rep(i, m)
  {
    vll d(0);
    vll e(0);
    for (auto j : si)
    {
      auto [cnt, num] = now[j];
      s.insert(num);
      if (cnt + num > n)
      {
        d.pb(j);
        continue;
      }
      now[j] = pll(cnt, num + cnt);
      e.pb(now[j].S);
    }
    rep(j, d.size())
    {
      si.erase(d[j]);
    }
    rep(j, e.size())
    {
      s.erase(e[j]);
    }

    while (iter < start.size())
    {
      auto [re, cnt, num] = start[iter];
      if (re > i + 1)
        break;
      now[cnt - 1] = pll(cnt, num);
      si.insert(cnt - 1);
      s.erase(num);
      iter++;
    }

    cout << *s.begin() << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
