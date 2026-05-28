#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0; i--)
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
const ll MOD = 998244353;
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

struct Aho
{
  using MP = unordered_map<char, ll>;
  vector<MP> to;
  vector<ll> cnt, mask, fail;
  Aho() : to(1), cnt(1), mask(1) {}
  ll add(const string &s, ll i)
  {
    ll v = 0;
    for (char c : s)
    {
      if (!to[v].count(c))
      {
        to[v][c] = to.size();
        to.push_back(MP());
        cnt.push_back(0);
        mask.push_back(0);
      }
      v = to[v][c];
    }
    cnt[v]++;
    mask[v] |= 1 << i;
    return v;
  }
  void init()
  {
    fail = vector<ll>(to.size(), -1);
    queue<ll> q;
    q.push(0);
    while (!q.empty())
    {
      ll v = q.front();
      q.pop();
      for (auto [c, u] : to[v])
      {
        fail[u] = (*this)(fail[v], c);
        cnt[u] += cnt[fail[u]];
        mask[u] |= mask[fail[u]];
        q.push(u);
      }
    }
  }
  ll operator()(ll v, char c) const
  {
    while (v != -1)
    {
      auto it = to[v].find(c);
      if (it != to[v].end())
        return it->second;
      v = fail[v];
    }
    return 0;
  }
  ll operator[](ll v) const { return mask[v]; }
};
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
int main()
{
  ll n, l;
  cin >> n >> l;
  Aho aho;
  rep(i, n)
  {
    string s;
    cin >> s;
    aho.add(s, i);
  }
  aho.init();
  vvll dp(1 << n, vll(aho.to.size()));
  dp[0][0] = 1;
  rep(i, l)
  {
    vvll ndp(1 << n, vll(aho.to.size()));
    rep(j, 1 << n)
    {
      rep(k, aho.to.size())
      {
        if (dp[j][k] != 0)
        {
          rep(z, 26)
          {
            ll v = k;
            char c = (char)('a' + z);
            v = aho(v, c);
            ndp[j | aho[v]][v] += dp[j][k];
            ndp[j | aho[v]][v] %= MOD;
          }
        }
      }
    }
    swap(dp, ndp);
  }
  ll ans = 0;
  rep(i, aho.to.size())
  {
    ans += dp[(1 << n) - 1][i];
    ans %= MOD;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
