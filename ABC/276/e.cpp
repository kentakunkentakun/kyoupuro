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
  ll h, w;
  cin >> h >> w;
  ll sx, sy;
  vector<vector<char>> c(h, vector<char>(w));
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> c[i][j];
      if (c[i][j] == 'S')
      {
        sx = i;
        sy = j;
      }
    }
  }
  queue<tuple<ll, ll, ll>> que;
  vvll ch(h, vll(w, -1));
  ch[sx][sy] = 0;
  rep(i, 4)
  {
    ll nx = sx + dx[i];
    ll ny = sy + dy[i];
    if (nx >= 0 && nx < h && ny >= 0 && ny < w && c[nx][ny] != '#')
    {
      que.push({nx, ny, i + 1});
      ch[nx][ny] = i + 1;
    }
  }
  while (que.size())
  {
    auto [x, y, u] = que.front();
    que.pop();
    rep(i, 4)
    {
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if (nx >= 0 && nx < h && ny >= 0 && ny < w && c[nx][ny] != '#')
      {
        if (ch[nx][ny] == -1)
        {
          ch[nx][ny] = u;
          que.push({nx, ny, u});
        }
        else if (ch[nx][ny] != 0 && ch[nx][ny] != u)
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
