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
  ll n, x, y;
  cin >> n >> x >> y;
  vll a(n);
  rep(i, n) cin >> a[i];
  auto judge = [&](ll t, vll k) -> ll
  {
    unordered_map<ll, ll> l, r;
    ll L = k.size() / 2;
    ll R = (k.size() + 1) / 2;
    rep(i, 2)
    {
      ll h = (k.size() + i) / 2;
      ll of = 0;
      if (i)
        of = L;
      for (int bit = 0; bit < (1 << h); bit++)
      {
        ll res = 0;
        rep(j, h)
        {
          if ((bit >> j) & 1)
          {
            res += k[of + j];
          }
          else
          {
            res -= k[of + j];
          }
        }
        if (i == 0)
        {
          l[res] = bit;
        }

        else
        {
          r[res] = bit;
        }
      }
    }
    for (auto [p, v] : l)
    {
      ll a = t - p;
      if (r.count(a))
      {
        ll rv = r[a];
        rv <<= L;
        rv += v;
        return rv;
      }
    }
    return -1;
  };
  vll X(0), Y(0);
  rep(i, n)
  {
    if (i % 2 == 0)
      Y.pb(a[i]);
    else
      X.pb(a[i]);
  }
  ll xv = judge(x, X);
  ll yv = judge(y, Y);
  if (xv != -1 && yv != -1)
  {
    cout << "Yes" << endl;
    ll now = 1;
    rep(i, n)
    {
      if (i % 2 == 0)
      {
        ll tmp = (yv >> (i / 2) & 1);
        if (tmp)
        {
          if (now)
          {
            cout << 'L';
          }
          else
          {
            cout << 'R';
          }
          now = 1;
        }
        else
        {
          if (now)
          {
            cout << 'R';
          }
          else
          {
            cout << 'L';
          }
          now = 0;
        }
      }
      else
      {
        ll tmp = (xv >> (i / 2) & 1);
        if (tmp)
        {
          if (now)
          {
            cout << 'R';
          }
          else
          {
            cout << 'L';
          }
          now = 1;
        }
        else
        {
          if (now)
          {
            cout << 'L';
          }
          else
          {
            cout << 'R';
          }
          now = 0;
        }
      }
    }
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
