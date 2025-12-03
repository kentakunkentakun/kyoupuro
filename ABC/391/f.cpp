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
  ll n, k;
  cin >> n >> k;
  vvll t(3, vll(n));
  rep(i, 3)
  {
    rep(j, n) cin >> t[i][j];
    sort(all(t[i]));
  }
  multiset<tuple<ll, ll, ll, ll>> s;
  auto culc = [&](ll x, ll y, ll z) -> ll
  {
    return x * y + x * z + y * z;
  };
  vvll ano(3, vll(2));
  ano[0][0] = 1;
  ano[0][1] = 2;
  ano[1][0] = 0;
  ano[1][1] = 2;
  ano[2][0] = 0;
  ano[2][1] = 1;
  vvll its(3, vll(3, n - 1));
  auto mi = [&](vll &tmp, ll now) -> pll
  {
    ll res = -1;
    ll iter = -1;
    ll a0 = ano[now][0];
    ll a1 = ano[now][1];
    if (tmp[now] > 0)
      if (chmax(res, culc(t[now][tmp[now] - 1], t[a0][tmp[a0]], t[a1][tmp[a1]])))
      {
        iter = now;
      }
    if (tmp[a0] > 0 && tmp[now] < tmp[a0])
    {
      if (chmax(res, culc(t[now][tmp[now]], t[a0][tmp[a0] - 1], t[a1][tmp[a1]])))
      {
        iter = a0;
      }
    }
    if (tmp[a1] > 0 && tmp[now] < tmp[a1])
    {
      if (chmax(res, culc(t[now][tmp[now]], t[a0][tmp[a0]], t[a1][tmp[a1] - 1])))
      {
        iter = a1;
      }
    }
    return {res, iter};
  };
  s.insert({culc(t[0][n - 1], t[1][n - 1], t[2][n - 1]), n - 1, n - 1, n - 1});
  while ((ll)s.size() < k)
  {
    rep(i, 3)
    {
      ll a0 = ano[i][0];
      ll a1 = ano[i][1];
      if (mi(its[i], i).F >= mi(its[a0], a0).F && mi(its[i], i).F >= mi(its[a1], a1).F)
      {
        auto [res, iter] = mi(its[i], i);
        its[i][iter]--;
        cout << res << " " << its[i][0] << " " << its[i][1] << " " << its[i][2] << endl;

        s.insert({res, its[i][0], its[i][1], its[i][2]});
        break;
      }
    }
  }
  for (auto [res, x, y, z] : s)
  {
    // cout << res << " " << x << " " << y << " " << z << endl;
  }
  while (s.size() > k)
  {
    s.erase(s.begin());
  }
  auto [res, x, y, z] = *s.begin();
  cout << res << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())
  auto min3 = [&](ll x, ll y, ll z) ->
  {
    return min(x, min(y, z));
  };

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
