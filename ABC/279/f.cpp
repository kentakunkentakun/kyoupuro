#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
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

  ll n, q;
  cin >> n >> q;

  ll MAX_B = 6 * 100000 + 5;
  dsu uf(MAX_B);
  vvll box(n, vll(0));
  vll root(MAX_B);
  vll ball(MAX_B);

  rep(i, n)
  {
    box[i].pb(i);
    root[i] = i;
    ball[i] = i;
  }
  ll ma = n - 1;
  vll ans(0);
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll x, y;
      cin >> x >> y;
      x--;
      y--;

      if (box[y].size() == 0)
        continue;
      if (box[x].size() == 0)
      {
        root[uf.leader(box[y][0])] = x;
        box[x].pb(box[y][0]);
        box[y] = {};
        continue;
      }
      uf.merge(box[x][0], box[y][0]);
      root[uf.leader(box[x][0])] = x;
      box[y] = {};
    }
    else if (t == 2)
    {
      ll x;
      cin >> x;
      x--;
      ma++;
      if (box[x].size())
      {
        uf.merge(box[x][0], ma);
        root[uf.leader(ma)] = x;
      }
      else
      {
        box[x].pb(ma);
        root[uf.leader(ma)] = x;
      }
    }
    else
    {
      ll x;
      cin >> x;
      x--;
      ans.pb(root[uf.leader(x)] + 1);
    }
  }
  rep(i, ans.size())
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
