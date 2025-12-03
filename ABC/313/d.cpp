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
  if (k == 1)
  {
    rep(i, n)
    {
      cout << "? " << i + 1 << endl;
      cin >> a[i];
    }
    cout << "! ";
    printArray(a);
    return 0;
  }
  vll tmp(k);
  for (int i = 1; i <= k; i++)
  {
    cout << "? 1 ";
    ll iter = i;
    ll cnt = 1;
    while (cnt < k)
    {
      cout << iter + 1 << " ";
      cnt++;
      if (iter == k)
      {
        iter = 1;
      }
      else
      {
        iter++;
      }
    }
    cout << endl;
    cin >> tmp[i - 1];
  }
  ll aa;
  cout << "? ";
  for (int i = 1; i <= k; i++)
  {
    cout << i + 1 << " ";
  }
  cout << endl;
  cin >> aa;
  ll res = 0;
  rep(i, k)
  {
    res += tmp[i];
  }
  a[0] = res % 2;
  for (int i = 0; i < k; i++)
  {
    ll iter = i + k;
    if (iter > k)
    {
      iter -= k;
    }
    ll tyukan = abs(tmp[i] - a[0]);
    a[iter] = abs(aa - tyukan);
  }

  ll kitei = abs(aa - a[1]);
  for (int i = k + 1; i < n; i++)
  {
    cout << "? " << i + 1 << " ";
    for (int j = 2; j <= k; j++)
    {
      cout << j + 1 << " ";
    }
    cout << endl;
    ll tm;
    cin >> tm;
    a[i] = abs(tm - kitei);
  }
  cout << "! ";
  printArray(a);
  cout << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/

/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
