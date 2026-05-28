#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
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
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T>
using PQ = priority_queue<T>;

template <class T>
using PQR = priority_queue<T, vector<T>, greater<T>>;

// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
const double INF_D = numeric_limits<double>::infinity();

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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
int main()
{
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 0;
  map<ll, map<ll, ll>> m;
  ll res = 0;
  vll c_cnt(n + 1);
  m[0][0]++;
  ll rr = 0;
  rep(i, n)
  {
    if (s[i] == 'A')
      res++;
    if (s[i] == 'B')
      res--;
    c_cnt[i + 1] += c_cnt[i];
    if (s[i] == 'C')
    {
      c_cnt[i + 1]++;
    }
    ll k = c_cnt[i + 1] * 3 - (i + 1);

    if (m.count(res) && m[res].count(k))
      rr += m[res][k];
    m[res][k]++;
  }
  rep(x, 3)
  {
    for (int y = x + 1; y < 3; y++)
    {
      ll r = 0;
      vll c(2 * n + 1);
      c[n] = 1;
      ll cnt = n;
      rep(i, n)
      {
        if (s[i] - 'A' == x)
        {
          cnt++;
        }
        else if (s[i] - 'A' == y)
        {
          cnt--;
        }
        ans += c[cnt];
        r += c[cnt];
        c[cnt]++;
      }
    }
  }
  cout << n * (n + 1) / 2 - ans + 2 * rr << endl;
}
