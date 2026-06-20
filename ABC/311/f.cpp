#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
  ll n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  ll ans = 1;
  vvll dp(n, vll(m));
  fenwick_tree<ll> bit(m + 1);
  vvll c(n, vll(m));
  vector<vector<bool>> ch(n, vector<bool>(m, true));
  rep(i, n)
  {
    rep(j, m)
    {
      if (ch[i][j] && s[i][j] == '#')
      {
        queue<pll> que;
        que.push({i, j});
        ch[i][j] = false;
        while (que.size())
        {
          auto [ni, nj] = que.front();
          que.pop();
          ch[ni][nj] = false;
          ll a = ni + 1;
          ll b = nj;
          if (isIn(a, b, n, m) && ch[a][b])
          {
            ch[a][b] = false;
            que.push({a, b});
          }
          b++;
          if (isIn(a, b, n, m) && ch[a][b])
          {
            ch[a][b] = false;
            que.push({a, b});
          }
        }
      }
    }
  }
  bit.add(0, 1);
  ll cnt = 0;
  rep(s, n + m - 1)
  {
    ll j = s;
    if (j >= m)
    {
      j = m - 1;
    }
    ll i = s - j;
    while (isIn(i, j, n, m))
    {
      cnt++;
      ll ni = n - 1 - i;
      if (ch[ni][j])
      {
        dp[ni][j] = bit.sum(0, j + 1);
        dp[ni][j] %= MOD;
        c[ni][j] = s;
        ans += dp[ni][j];
        ans %= MOD;
      }
      i++;
      j--;
    }
    j = s;
    if (j >= m)
      j = m - 1;
    i = s - j;
    while (isIn(i, j, n, m))
    {

      ll ni = n - 1 - i;
      if (ch[ni][j])
      {
        ll now = bit.sum(j + 1, j + 2);
        bit.add(j + 1, -now);
        now += dp[ni][j];
        now %= MOD;
        bit.add(j + 1, now);
      }
      i++;
      j--;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
