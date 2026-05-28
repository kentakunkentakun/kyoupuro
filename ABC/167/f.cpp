#include <bits/stdc++.h>
#include <atcoder/segtree>
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
struct S
{
  ll v, minus, empty;
};
S op(S a, S b)
{
  if (a.empty)
  {
    return b;
  }
  else if (b.empty)
  {
    return a;
  }
  if (a.v == b.v)
  {
    if (a.minus < b.minus)
    {
      return b;
    }
    else
    {
      return a;
    }
  }
  else if (a.v > b.v)
  {
    return a;
  }
  return b;
}
S e()
{
  return {-INF, 0, true};
}
int main()
{
  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  ll cnt = 0;
  rep(i, n)
  {
    rep(j, s[i].size())
    {
      if (s[i][j] == ')')
      {
        cnt--;
      }
      else
      {
        cnt++;
      }
    }
  }
  if (cnt != 0)
  {
    cout << "No" << endl;
    return 0;
  }
  vector<pll> l(0);
  vector<pll> r(0);
  rep(i, n)
  {
    ll tmp = 0;
    ll saitei = INF;
    rep(j, s[i].size())
    {
      if (s[i][j] == ')')
      {
        tmp--;
      }
      else
      {
        tmp++;
      }
      chmin(saitei, tmp);
    }
    if (tmp >= 0)
    {
      l.pb({saitei, tmp});
    }
    else
    {
      saitei = INF;
      tmp = 0;
      repR(j, s[i].size())
      {
        if (s[i][j] == '(')
        {
          tmp--;
        }
        else
        {
          tmp++;
        }
        chmin(saitei, tmp);
      }
      r.pb({saitei, tmp});
    }
  }
  sort(rall(l));
  sort(rall(r));
  auto f = [&](vector<pll> &v) -> bool
  {
    ll n = v.size();
    ll tmp = 0;
    rep(i, n)
    {
      auto [saitei, k] = v[i];
      if (saitei < 0 && tmp < -1 * saitei)
      {
        return false;
      }
      tmp += k;
    }
    return true;
  };
  if (f(l) && f(r))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
