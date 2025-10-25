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
  ll h, w, q;
  cin >> h >> w >> q;
  vector<set<ll>> th(w);
  vector<set<ll>> tw(h);
  rep(i, w)
  {
    rep(j, h)
    {
      th[i].insert(j);
    }
  }
  rep(i, h)
  {
    rep(j, w)
    {
      tw[i].insert(j);
    }
  }
  rep(i, q)
  {
    ll r, c;
    cin >> r >> c;
    r--;
    c--;
    if (th[c].count(r))
    {
      th[c].erase(r);
    }
    else
    {
      auto l_iter = th[c].lower_bound(r);
      auto r_iter = th[c].upper_bound(r);
      if (l_iter != th[c].begin())
      {
        l_iter = prev(l_iter);

        tw[*l_iter].erase(c);
        th[c].erase(l_iter);
      }
      if (r_iter != th[c].end())
      {
        tw[*r_iter].erase(c);
        th[c].erase(r_iter);
      }
    }
    if (tw[r].count(c))
    {
      tw[r].erase(c);
    }
    else
    {
      auto l_iter = tw[r].lower_bound(c);
      auto r_iter = tw[r].upper_bound(c);

      if (l_iter != tw[r].begin())
      {
        l_iter = prev(l_iter);
        th[*l_iter].erase(r);
        tw[r].erase(l_iter);
      }
      if (r_iter != tw[r].end())
      {
        th[*r_iter].erase(r);
        tw[r].erase(r_iter);
      }
    }
  }
  ll ans = 0;
  rep(i, h)
  {
    ans += tw[i].size();
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
