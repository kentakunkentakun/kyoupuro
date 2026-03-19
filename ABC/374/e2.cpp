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
  vll a(n), p(n), b(n), q(n);
  rep(i, n)
  {
    cin >> a[i] >> p[i] >> b[i] >> q[i];
  }
  auto judge = [&](ll wj) -> bool
  {
    ll cost = 0;
    rep(i, n)
    {
      ll remain = wj % (a[i] * b[i]);
      ll t = wj;
      if (wj >= a[i] * b[i])
      {
        remain += a[i] * b[i];
        t -= a[i] * b[i];
      }
      if (p[i] * b[i] < q[i] * a[i])
      {
        cost += t / (a[i] * b[i]) * (p[i] * b[i]);
      }
      else
      {
        cost += t / (a[i] * b[i]) * (q[i] * a[i]);
      }
      if (cost > x)
      {
        return false;
      }
      ll c = (remain + a[i] - 1) / a[i] * p[i];
      rep(j, (remain + a[i] - 1) / a[i])
      {
        ll cc = j * p[i] + max((remain - a[i] * j + b[i] - 1), 0LL) / b[i] * q[i];
        chmin(c, cc);
      }
      cost += c;
    }
    if (cost <= x)
    {
      return true;
    }
    else
    {
      return false;
    }
  };
  ll ac = 0, wa = 10010010010;
  while (ac + 1 < wa)
  {
    ll mid = (ac + wa) / 2;
    if (judge(mid))
    {
      ac = mid;
    }
    else
    {
      wa = mid;
    }
  }
  cout << ac << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
