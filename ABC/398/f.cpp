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
  string s;
  cin >> s;
  ll n = s.size();
  string t = s;
  reverse(all(t));
  t += s;
  vector<int> z = z_algorithm(t);
  for (int i = n; i < 2 * n; i++)
  {
    if (z[i] == 2 * n - i)
    {
      string ans = "";
      string tmp = "";
      for (int j = n; j < i; j++)
      {
        tmp += t[j];
      }
      ans += tmp;
      for (int j = i; j < 2 * n; j++)
      {
        ans += t[j];
      }
      reverse(all(tmp));
      ans += tmp;
      cout << ans << endl;
      return 0;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
