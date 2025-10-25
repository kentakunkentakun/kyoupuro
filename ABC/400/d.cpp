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
  vector<string> s(h);
  rep(i, h)
  {
    cin >> s[i];
  }
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  b--;
  c--;
  d--;
  vvll dist(h, vll(w, INF));
  dist[c][d] = 0;
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
  que.push({0, c, d});
  while (que.size())
  {
    auto [cost, i, j] = que.top();
    que.pop();
    if (dist[i][j] < cost)
      continue;
    rep(z, 4)
    {
      ll nx = i + dx[z];
      ll nx2 = i + dx[z] * 2;
      ll ny = j + dy[z];
      ll ny2 = j + dy[z] * 2;
      if (nx >= 0 && nx < h && ny >= 0 && ny < w)
      {
        if (s[nx][ny] == '#')
        {
          if (chmin(dist[nx][ny], cost + 1))
          {
            que.push({cost + 1, nx, ny});
          }
          if (nx2 >= 0 && nx2 < h && ny2 >= 0 && ny2 < w && s[nx2][ny2] == '#' && chmin(dist[nx2][ny2], cost + 1))
          {
            que.push({cost + 1, nx2, ny2});
          }
        }
        else
        {
          if (chmin(dist[nx][ny], cost))
          {
            que.push({cost, nx, ny});
          }
        }
      }
    }
  }
  cout << dist[a][b] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
