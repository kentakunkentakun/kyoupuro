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

// a^n mod を計算する

long long modpow(long long a, long long n, long long mod)
{
  long long res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// a^{-1} mod を計算する

long long modinv(long long a, long long mod)
{
  return modpow(a, mod - 2, mod);
}
int main()
{
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h)
  {
    cin >> s[i];
  }
  vvll t(h, vll(w, -1));
  ll group = 0;
  rep(i, h)
  {
    rep(j, w)
    {
      if (t[i][j] == -1 && s[i][j] == '#')
      {
        queue<pll> que;
        que.push({i, j});
        t[i][j] = group;
        while (que.size())
        {
          auto [x, y] = que.front();
          que.pop();
          rep(z, 4)
          {
            ll ni = dx[z] + x;
            ll nj = dy[z] + y;
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && t[ni][nj] == -1 && s[ni][nj] == '#')
            {
              t[ni][nj] = group;
              que.push({ni, nj});
            }
          }
        }
        group++;
      }
    }
  }
  ll ans = 0;
  ll red = 0;
  rep(i, h)
  {
    rep(j, w)
    {
      if (s[i][j] == '.')
      {
        red++;
        set<ll> tmp;
        rep(z, 4)
        {
          ll ni = dx[z] + i;
          ll nj = dy[z] + j;
          if (ni >= 0 && ni < h && nj >= 0 && nj < w && t[ni][nj] != -1)
          {
            tmp.insert(t[ni][nj]);
          }
        }
        if (tmp.size() > 0)
          ans += group - (tmp.size() - 1);
        else
        {
          ans += group + 1;
        }
        ans %= MOD;
      }
    }
  }

  ans *= modinv(red, MOD);
  cout << ans % MOD << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
