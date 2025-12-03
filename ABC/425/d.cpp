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
  ll h, w;
  cin >> h >> w;
  set<pll> b;
  queue<pll> que;
  vector<vector<char>> s(h, vector<char>(w));
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> s[i][j];
      if (s[i][j] == '#')
      {
        b.insert({i, j});
        que.push({i, j});
      }
    }
  }
  auto canBlack = [&](ll nx, ll ny, ll h, ll w) -> bool
  {
    if (s[nx][ny] == '#')
      return false;
    ll cnt = 0;
    rep(i, 4)
    {
      ll nnx = nx + dx[i];
      ll nny = ny + dy[i];
      if (isIn(nnx, nny, h, w) && s[nnx][nny] == '#')
      {
        cnt++;
      }
    }
    return cnt == 1;
  };
  while (1)
  {
    vector<pll> up(0);
    while (que.size())
    {
      auto [x, y] = que.front();
      que.pop();
      rep(z, 4)
      {
        ll nx = dx[z] + x;
        ll ny = dy[z] + y;
        if (isIn(nx, ny, h, w) && canBlack(nx, ny, h, w))
        {
          up.pb({nx, ny});
        }
      }
    }
    if (up.size() == 0)
      break;
    rep(i, up.size())
    {
      que.push(up[i]);
      s[up[i].F][up[i].S] = '#';
    }
  }
  ll ans = 0;
  rep(i, h)
  {
    rep(j, w)
    {
      if (s[i][j] == '#')
        ans++;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
