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
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x, vector<x>, greater<x>>
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
  string s;
  cin >> s;
  string t;
  cin >> t;
  string ss = "";
  string tt = "";
  rep(i, s.size())
  {
    if (s[i] != 'A')
      ss += s[i];
  }
  rep(i, t.size())
  {
    if (t[i] != 'A')
      tt += t[i];
  }
  if (ss == tt)
  {
    ll ans = 0;
    vll s_cnt(ss.size() + 1);
    vll t_cnt(ss.size() + 1);
    ll it = 0;
    ll cnt = 0;
    rep(i, s.size())
    {
      if (s[i] == 'A')
      {
        cnt++;
      }
      else
      {
        s_cnt[it] = cnt;
        it++;
        cnt = 0;
      }
    }
    if (cnt > 0)
    {
      s_cnt[it] = cnt;
    }
    cnt = 0;
    it = 0;
    rep(i, t.size())
    {
      if (t[i] == 'A')
      {
        cnt++;
      }
      else
      {
        t_cnt[it] = cnt;
        it++;
        cnt = 0;
      }
    }
    if (cnt > 0)
    {
      t_cnt[it] = cnt;
    }
    rep(i, s_cnt.size())
    {
      ans += abs(s_cnt[i] - t_cnt[i]);
    }
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
