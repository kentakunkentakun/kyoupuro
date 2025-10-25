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
int main()
{
  ll n, k;
  cin >> n >> k;
  vll a(n);
  map<ll, ll> m;
  rep(i, n)
  {
    cin >> a[i];
    m[a[i]]++;
  }
  sort(all(a));
  a.erase(unique(a.begin(), a.end()), a.end());
  sort(rall(a));
  a.pb(0);
  ll ans = 0;
  ll cnt = 0;
  n = a.size();
  rep(i, n)
  {
    if (i == n - 1)
      break;
    cnt += m[a[i]];
    if (cnt * (a[i] - a[i + 1]) >= k)
    {
      ll cu = k / cnt;
      ll remain = k % cnt;
      ans += cnt * (a[i] * (a[i] + 1) / 2 - (a[i] - cu) * (a[i] - cu + 1) / 2);
      ans += (a[i] - cu) * remain;
      break;
    }
    else
    {
      k -= cnt * (a[i] - a[i + 1]);
      ans += cnt * (a[i] * (a[i] + 1) / 2 - a[i + 1] * (a[i + 1] + 1) / 2);
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128
__builtin_popcount(i)*/
