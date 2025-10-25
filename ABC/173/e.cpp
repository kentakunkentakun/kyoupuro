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
using vvvll = vector<vvll>;
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
  vll a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  vll minus(0);
  vll plus(0);
  ll zero = 0;
  rep(i, n)
  {
    if (a[i] < 0)
    {
      minus.pb(a[i]);
    }
    if (a[i] > 0)
    {
      plus.pb(a[i]);
    }
    if (a[i] == 0)
      zero++;
  }
  if (plus.size() == 0)
  {
    if (zero > 0)
    {
      if (k % 2)
      {
        cout << 0 << endl;
      }
      else
      {
        if (minus.size() >= k)
        {
          ll ans = 1;
          rep(i, k)
          {
            ans *= minus[i];
            ans %= MOD;
          }
          cout << (ans + MOD) % MOD << endl;
        }
        else
        {
          cout << 0 << endl;
        }
      }
    }
    else
    {
      if (k % 2)
      {
        ll ans = 1;
        reverse(all(a));
        repR(i, k)
        {
          ans *= a[i];
          ans %= MOD;
        }
        cout << (ans + MOD) % MOD << endl;
      }
      else
      {
        ll ans = 1;
        rep(i, k)
        {
          ans *= a[i];
          ans %= MOD;
        }
        cout << (ans + MOD) % MOD << endl;
      }
    }
  }
  else
  {
    if (plus.size() + minus.size() < k)
    {
      cout << 0 << endl;
    }
    else if (plus.size() + minus.size() == k)
    {
      if (minus.size() % 2)
      {
        if (zero)
        {
          cout << 0 << endl;
        }
        else
        {
          ll ans = 1;
          rep(i, minus.size())
          {
            ans *= minus[i];
            ans %= MOD;
          }
          rep(i, plus.size())
          {
            ans *= plus[i];
            ans %= MOD;
          }
          cout << (ans + MOD) % MOD << endl;
        }
      }
      else
      {
        ll ans = 1;
        rep(i, minus.size())
        {
          ans *= minus[i];
          ans %= MOD;
        }
        rep(i, plus.size())
        {
          ans *= plus[i];
          ans %= MOD;
        }
        cout << (ans + MOD) % MOD << endl;
      }
    }
    else
    {
      if (k == 1)
      {
        cout << plus[plus.size() - 1] << endl;
        return 0;
      }
      vll minus_d(minus.size() + 1, 1);
      vll plus_d(plus.size() + 1, 1);
      reverse(all(plus));
      rep(i, minus.size())
      {
        minus_d[i + 1] = minus[i] * minus_d[i];
        minus_d[i + 1] %= MOD;
      }
      rep(i, plus.size())
      {
        plus_d[i + 1] = plus[i] * plus_d[i];
        plus_d[i + 1] %= MOD;
      }
      ll ans = 0;
      ll mi = 1;
      ll pl = 1;

      ll plus_s = 0;
      if (k <= plus.size())
      {
        plus_s = k;
      }
      else
      {
        if (k % 2)
        {
          plus_s = plus.size();
          if (!(plus_s % 2))
            plus_s--;
        }
        else
        {
          plus_s = plus.size();
          if (plus_s % 2)
            plus_s--;
        }
      }
      ll minus_s = k - plus_s;
      ans = plus_d[plus_s] * minus_d[minus_s];
      for (int i = minus_s; i <= minus.size(); i += 2)
      {
        ll plus_cnt = k - i;
        if (plus_cnt <= plus.size())
        {
          if (i > minus_s)
          {
            mi = minus[i - 2] * minus[i - 1];
            pl = plus[plus_cnt] * plus[plus_cnt + 1];
            if (mi < pl)
            {
              break;
            }
          }
          ans = minus_d[i] * plus_d[plus_cnt];
        }
      }
      cout << (ans + MOD) % MOD << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
