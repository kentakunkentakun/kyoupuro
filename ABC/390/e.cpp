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
  ll n, x;
  cin >> n >> x;
  vll v1(0), v1_c(0), v2(0), v2_c(0), v3(0), v3_c(0);
  rep(i, n)
  {
    ll v, a, c;
    cin >> v >> a >> c;
    if (v == 1)
    {
      v1.pb(a);
      v1_c.pb(c);
    }
    else if (v == 2)
    {
      v2.pb(a);
      v2_c.pb(c);
    }
    else
    {
      v3.pb(a);
      v3_c.pb(c);
    }
  }
  vvll dp1(v1.size() + 1, vll(5005, -1));
  vvll dp2(v2.size() + 1, vll(5005, -1));
  vvll dp3(v3.size() + 1, vll(5005, -1));
  dp1[0][0] = 0;
  dp2[0][0] = 0;
  dp3[0][0] = 0;
  rep(i, v1.size())
  {
    rep(j, 5001)
    {
      chmax(dp1[i + 1][j], dp1[i][j]);
      if (dp1[i][j] >= 0 && j + v1_c[i] <= 5000)
      {
        chmax(dp1[i + 1][j + v1_c[i]], dp1[i][j] + v1[i]);
      }
    }
  }
  rep(i, v2.size())
  {
    rep(j, 5001)
    {
      chmax(dp2[i + 1][j], dp2[i][j]);
      if (dp2[i][j] >= 0 && j + v2_c[i] <= 5000)
      {
        chmax(dp2[i + 1][j + v2_c[i]], dp2[i][j] + v2[i]);
      }
    }
  }
  rep(i, v3.size())
  {
    rep(j, 5001)
    {
      chmax(dp3[i + 1][j], dp3[i][j]);
      if (dp3[i][j] >= 0 && j + v3_c[i] <= 5000)
      {
        chmax(dp3[i + 1][j + v3_c[i]], dp3[i][j] + v3[i]);
      }
    }
  }
  ll V1 = v1.size();
  ll V2 = v2.size();
  ll V3 = v3.size();
  auto judge = [&](ll wj) -> bool
  {
    ll c1 = -1, c2 = -1, c3 = -1;
    rep(i, 5005)
    {
      if (dp1[V1][i] >= wj && c1 == -1)
      {
        c1 = i;
      }
      if (dp2[V2][i] >= wj && c2 == -1)
      {
        c2 = i;
      }
      if (dp3[V3][i] >= wj && c3 == -1)
      {
        c3 = i;
      }
    }
    if (c1 < 0 || c2 < 0 || c3 < 0)
      return false;
    if (c1 + c2 + c3 <= x)
    {
      return true;
    }
    else
    {
      return false;
    }
  };
  ll ac = 0, wa = INF;
  while (ac + 1 < wa)
  {
    ll wj = (ac + wa) / 2;
    if (judge(wj))
    {
      ac = wj;
    }
    else
    {
      wa = wj;
    }
  }
  cout << ac << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
