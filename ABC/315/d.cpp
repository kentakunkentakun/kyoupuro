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
  ll h, w;
  cin >> h >> w;
  vector<vc> c(h, vc(w));
  vector<vector<ll>> hs(h, vll(26, 0));
  vector<vll> ws(w, vll(26, 0));
  rep(i, h) rep(j, w)
  {
    cin >> c[i][j];
    hs[i][c[i][j] - 'a']++;
    ws[j][c[i][j] - 'a']++;
  }
  ll ans = h * w;

  vll h_d(26, 0);
  vll w_d(26, 0);
  while (1)
  {
    bool ch = false;
    rep(i, h)
    {
      ll all_cnt = accumulate(all(hs[i]), 0LL);
      if (all_cnt > 1)
      {
        rep(j, 26)
        {
          if (all_cnt == hs[i][j])
          {
            ch = true;
            ans -= all_cnt;
            h_d[j] += 1;
            hs[i][j] = 0;
          }
        }
      }
    }
    rep(i, w)
    {
      ll all_cnt = accumulate(all(ws[i]), 0LL);
      if (all_cnt > 1)
      {
        rep(j, 26)
        {
          if (all_cnt == ws[i][j])
          {
            ch = true;
            ans -= all_cnt - h_d[j];
            w_d[j] += 1;
            ws[i][j] = 0;
          }
        }
      }
      rep(j, 26)
      {
        ws[i][j] = max(ws[i][j] - h_d[j], 0LL);
      }
    }
    rep(i, h)
    {
      rep(j, 26)
      {
        hs[i][j] = max(hs[i][j] - w_d[j], 0LL);
      }
    }
    if (!ch)
      break;
    vll tmp(26, 0);
    h_d = tmp;
    w_d = tmp;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
