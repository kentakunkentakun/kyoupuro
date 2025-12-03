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
  ll n, m, l;
  cin >> n >> m >> l;
  vll a(n), b(m), c(l);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  rep(i, l) cin >> c[i];
  vector<pll> p(0);
  ll ak = 0;
  ll bk = 0;
  ll ck = 0;
  rep(i, n)
  {
    p.pb({a[i], 0});
  }
  rep(i, m)
  {
    p.pb({b[i], 1});
  }
  rep(i, l)
  {
    p.pb({c[i], 2});
  }
  sort(all(p));

  repR(i, p.size())
  {
    ak *= 2;
    bk *= 2;
    ck *= 2;
    if (p[i].S == 0)
    {
      ak++;
    }
    else if (p[i].S == 1)
    {
      bk++;
    }
    else
    {
      ck++;
    }
  }
  ll k = n + m + l;
  map<tuple<ll, ll, ll, ll>, int> dp;
  auto dfs = [&](auto dfs, ll ak, ll bk, ll ck, ll turn) -> int
  {
    if (dp.count({ak, bk, ck, turn}))
    {
      return dp[{ak, bk, ck, turn}];
    }

    if (turn == 0 && ak == 0)
    {
      return dp[{ak, bk, ck, turn}] = 0;
    }
    if (turn == 1 && bk == 0)
    {
      return dp[{ak, bk, ck, turn}] = 0;
    }
    int res = 1;
    if (turn == 0)
    {
      vector<pll> tehuda(0);
      vector<pll> ba(0);
      rep(i, k)
      {
        if (ak >> i & 1)
        {
          tehuda.pb({p[i].F, i});
        }
        if (ck >> i & 1)
        {
          ba.pb({p[i].F, i});
        }
      }
      rep(i, tehuda.size())
      {
        rep(j, ba.size())
        {
          if (tehuda[i].F > ba[j].F)
          {
            ll nx_ak = ak & ~(1 << tehuda[i].S);
            nx_ak |= (1 << ba[j].S);
            ll nx_ck = ck & ~(1 << ba[j].S);
            nx_ck |= (1 << tehuda[i].S);
            chmin(res, dfs(dfs, nx_ak, bk, nx_ck, 1 - turn));
          }
        }
        ll nx_ak = ak & ~(1 << tehuda[i].S);
        ll nx_ck = ck | (1 << tehuda[i].S);
        chmin(res, dfs(dfs, nx_ak, bk, nx_ck, 1 - turn));
      }
    }
    else
    {
      vector<pll> tehuda(0);
      vector<pll> ba(0);
      rep(i, k)
      {
        if (bk >> i & 1)
        {
          tehuda.pb({p[i].F, i});
        }
        if (ck >> i & 1)
        {
          ba.pb({p[i].F, i});
        }
      }
      rep(i, tehuda.size())
      {
        rep(j, ba.size())
        {
          if (tehuda[i].F > ba[j].F)
          {
            ll nx_bk = bk & ~(1LL << tehuda[i].S);
            nx_bk |= (1 << ba[j].S);
            ll nx_ck = ck & ~(1LL << ba[j].S);
            nx_ck |= (1 << tehuda[i].S);
            chmin(res, dfs(dfs, ak, nx_bk, nx_ck, 1 - turn));
          }
        }
        ll nx_bk = bk & ~(1LL << tehuda[i].S);
        ll nx_ck = ck | (1LL << tehuda[i].S);
        chmin(res, dfs(dfs, ak, nx_bk, nx_ck, 1 - turn));
      }
    }
    return dp[{ak, bk, ck, turn}] = 1 - res;
  };
  if (dfs(dfs, ak, bk, ck, 0))
  {
    cout << "Takahashi" << endl;
  }
  else
  {
    cout << "Aoki" << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
