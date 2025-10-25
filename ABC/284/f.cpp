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
template <class T>
vector<int> z_algorithm_Impl(const std::vector<T> &s)
{
  vector<int> Z(s.size());
  Z[0] = s.size();
  int i = 1, j = 0;
  while (i < s.size())
  {
    while (i + j < s.size() && s[j] == s[i + j])
      j++;
    Z[i] = j;

    if (j == 0)
    {
      i++;
      continue;
    }
    int k = 1;
    while (k < j && k + Z[k] < j)
    {
      Z[i + k] = Z[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return Z;
}

vector<int> z_algorithm(const string &s)
{
  int n = int(s.size());
  vector<int> s2(n);
  for (int i = 0; i < n; i++)
  {
    s2[i] = s[i];
  }
  return z_algorithm_Impl(s2);
}

int main()
{
  ll n;
  string t;
  cin >> n;
  cin >> t;
  string a = t.substr(0, n);
  string b = t.substr(n, 2 * n);
  reverse(all(b));
  a += b;
  vector<int> z = z_algorithm(a);
  a = t.substr(0, n);
  b = t.substr(n, 2 * n);
  reverse(all(a));
  a += b;
  vector<int> z2 = z_algorithm(a);
  for (int i = n; i < 2 * n; i++)
  {
    if (z[i] == 2 * n - i)
    {
      ll remain = n - (2 * n - i);
      if (remain == 0)
      {
        cout << t.substr(0, n) << endl;
        cout << n << endl;
        return 0;
      }
      if (z2[2 * n - remain] == remain)
      {
        string fi = t.substr(0, 2 * n - i);
        string se = t.substr(2 * n - remain, 2 * n);
        string ans = fi + se;
        cout << ans << endl;
        cout << fi.size() << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
