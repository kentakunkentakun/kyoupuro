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
  ll r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  ll n, m, l;
  cin >> n >> m >> l;
  vector<char> s(m), t(l);
  vll a(m), b(l);
  rep(i, m)
  {
    cin >> s[i] >> a[i];
  }
  rep(i, l)
  {
    cin >> t[i] >> b[i];
  }
  ll a_cnt = 0;
  ll b_cnt = 0;
  ll iter_a = 0;
  ll iter_b = 0;
  ll ans = 0;
  while (iter_a < m)
  {
    ll next_a = a[iter_a] - a_cnt;
    ll next_b = b[iter_b] - b_cnt;
    ll k = min(next_a, next_b);
    ll r1_a = r1, c1_a = c1, r2_b = r2, c2_b = c2;
    if (s[iter_a] == 'U')
      r1_a = r1 - k;
    else if (s[iter_a] == 'D')
      r1_a = r1 + k;
    else if (s[iter_a] == 'L')
      c1_a = c1 - k;
    else if (s[iter_a] == 'R')
      c1_a = c1 + k;
    if (t[iter_b] == 'U')
      r2_b = r2 - k;
    else if (t[iter_b] == 'D')
      r2_b = r2 + k;
    else if (t[iter_b] == 'L')
      c2_b = c2 - k;
    else if (t[iter_b] == 'R')
      c2_b = c2 + k;

    if (r1 == r2 && c1 == c2)
    {
      if (s[iter_a] == t[iter_b])
      {
        ans += k;
      }
    }
    else if (c1 == c2)
    {
      if (r1 > r2 && s[iter_a] == 'U' && t[iter_b] == 'D')
      {
        if (r2_b >= r1_a && r1 % 2 == r2 % 2)
        {
          ans++;
        }
      }
      else if (r1 < r2 && s[iter_a] == 'D' && t[iter_b] == 'U')
      {
        if (r2_b <= r1_a && r1 % 2 == r2 % 2)
        {
          ans++;
        }
      }
    }
    else if (r1 == r2)
    {
      if (c1 > c2 && s[iter_a] == 'L' && t[iter_b] == 'R')
      {
        if (c2_b >= c1_a && c1 % 2 == c2 % 2)
        {
          ans++;
        }
      }
      else if (c1 < c2 && s[iter_a] == 'R' && t[iter_b] == 'L')
      {
        if (c2_b <= c1_a && c1 % 2 == c2 % 2)
        {
          ans++;
        }
      }
    }
    else if (r1 != r2 && c1 != c2)
    {
      if (
          // case A: 1体目が縦(U/D)、2体目が横(L/R)
          (((s[iter_a] == 'U' || s[iter_a] == 'D') && (t[iter_b] == 'L' || t[iter_b] == 'R')) &&
           ((r2 - r1) * (s[iter_a] == 'U' ? -1 : 1) == (c1 - c2) * (t[iter_b] == 'L' ? -1 : 1)) &&
           (1 <= (r2 - r1) * (s[iter_a] == 'U' ? -1 : 1)) &&
           ((r2 - r1) * (s[iter_a] == 'U' ? -1 : 1) <= k)) ||
          // case B: 1体目が横(L/R)、2体目が縦(U/D)
          (((s[iter_a] == 'L' || s[iter_a] == 'R') && (t[iter_b] == 'U' || t[iter_b] == 'D')) &&
           ((c2 - c1) * (s[iter_a] == 'L' ? -1 : 1) == (r1 - r2) * (t[iter_b] == 'U' ? -1 : 1)) &&
           (1 <= (c2 - c1) * (s[iter_a] == 'L' ? -1 : 1)) &&
           ((c2 - c1) * (s[iter_a] == 'L' ? -1 : 1) <= k)))
        ans++;
    }
    r1 = r1_a;
    c1 = c1_a;
    r2 = r2_b;
    c2 = c2_b;
    a_cnt += k;
    b_cnt += k;
    if (a_cnt == a[iter_a])
    {
      iter_a++;
      a_cnt = 0;
    }
    if (b_cnt == b[iter_b])
    {
      iter_b++;
      b_cnt = 0;
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
