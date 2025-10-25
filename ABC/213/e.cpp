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
using vvvll = vector<vvll>;
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
  auto ch = [&](ll nx, ll ny)
  {
    if (nx >= 0 && nx < h && ny >= 0 && ny < w)
    {
      return true;
    }
    return false;
  };
  vector<vector<char>> s(h, vector<char>(w));
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> s[i][j];
    }
  }
  vvll t(h, vll(w, INF));
  t[0][0] = 0;
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
  que.push({0, 0, 0});
  while (que.size())
  {
    auto [c, x, y] = que.top();
    que.pop();
    if (c > t[x][y])
      continue;
    rep(i, 4)
    {
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if (ch(nx, ny))
      {
        if (s[nx][ny] == '.')
        {
          if (chmin(t[nx][ny], c))
          {
            que.push({c, nx, ny});
          }
        }
      }
    }
    // 上
    for (int i = x - 1; i <= x + 1; i++)
    {
      for (int j = y - 2; j <= y - 1; j++)
      {
        if (ch(i, j))
        {
          if (chmin(t[i][j], c + 1))
          {
            que.push({c + 1, i, j});
          }
        }
      }
    }
    // 左
    for (int i = x - 2; i <= x - 1; i++)
    {
      for (int j = y + 1; j <= y - 1; j++)
      {
        if (ch(i, j))
        {
          if (chmin(t[i][j], c + 1))
          {
            que.push({c + 1, i, j});
            if (i == 2 && j == 1)
            {
              cout << t[i][j] << " " << x << " " << y << endl;
            }
          }
        }
      }
    }
    // 下
    for (int i = x - 1; i <= x + 1; i++)
    {
      for (int j = y + 1; j <= y + 2; j++)
      {
        if (ch(i, j))
        {
          if (chmin(t[i][j], c + 1))
          {
            que.push({c + 1, i, j});
          }
        }
      }
    }
    // 右
    for (int i = x + 1; i <= x + 2; i++)
    {
      for (int j = y - 1; j <= y + 1; j++)
      {
        if (ch(i, j))
        {
          if (chmin(t[i][j], c + 1))
          {
            que.push({c + 1, i, j});
          }
        }
      }
    }
  }
  cout << t[h - 1][w - 1] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
