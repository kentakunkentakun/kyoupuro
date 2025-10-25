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
  ll n, m, k;
  cin >> n >> m >> k;
  if (n == m)
  {
    for (int i = 0; i < n; ++i)
      cout << 0 << " \n"[i == n - 1];
    return 0;
  }
  vll a(n);
  vll s(n);

  rep(i, n)
  {
    cin >> a[i];
    s[i] = a[i];
  }
  sort(all(s));
  // rep(i, n)
  // {
  //   cout << s[i] << " ";
  // }
  // cout << endl;
  map<ll, ll> tmp;
  rep(i, n)
  {
    if (!tmp.count(s[i]))
    {
      tmp[s[i]] = i;
    }
  }
  vll mm(n);
  rep(i, n)
  {
    mm[i] = tmp[a[i]];
  }
  vll t(n + 1);
  for (int i = 0; i < n; i++)
  {
    t[i + 1] += t[i] + s[i];
  }
  ll no = k - t[n];
  rep(i, n)
  {
    ll left = -1;
    ll right = no + 1;

    while (left + 1 < right)
    {
      ll mid = (left + right) / 2;
      ll now = mid + a[i];
      auto iter = upper_bound(all(s), now);
      if (s.end() - iter < m)
      {
        ll y = m - (s.end() - iter);

        ll now_i = iter - s.begin();

        ll start = now_i - y;
        ll end = now_i - 1;
        ll sum = t[end + 1] - t[start];

        if (start <= mm[i] && mm[i] <= end)
        {
          sum -= a[i];
          sum += s[start - 1];
        }
        if (y * (now + 1) - sum > no - mid)
        {
          right = mid;
        }
        else
        {
          left = mid;
        }
      }
      else
      {
        left = mid;
      }
    }
    // auto iter = upper_bound(all(s), a[i] + right);
    if (left == no /*s.end() - iter > m - 1*/)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << right << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
