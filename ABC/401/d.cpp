#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
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
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  rep(i, n)
  {
    if (s[i] == 'o')
      k--;
    if (s[i] == '?')
    {
      if (i - 1 >= 0 && s[i - 1] == 'o')
      {
        s[i] = '.';
      }
      if (i + 1 < n && s[i + 1] == 'o')
      {
        s[i] = '.';
      }
    }
  }
  if (k <= 0)
  {
    rep(i, n)
    {
      if (s[i] == '?')
      {
        cout << '.';
      }
      else
      {
        cout << s[i];
      }
    }
    cout << endl;
    return 0;
  }

  vector<ll> block(0);
  ll tmp = 0;
  rep(i, n)
  {
    if (s[i] == '?')
      tmp++;
    if (i + 1 == n && tmp != 0)
    {
      block.pb(tmp);
      tmp = 0;
    }
    if (s[i] != '?' && tmp != 0)
    {
      block.pb(tmp);
      tmp = 0;
    }
  }
  ll max_count = 0;
  rep(i, block.size())
  {
    max_count += (block[i] + 1) / 2;
  }
  if (max_count == k)
  {
    ll iter = 0;
    ll block_iter = 0;
    while (iter < n)
    {
      if (s[iter] == '?')
      {
        ll v = block[block_iter];
        if (v % 2 == 0)
        {
          rep(i, v)
          {
            cout << '?';
          }
        }
        else
        {
          rep(i, v)
          {
            if (i % 2)
            {
              cout << '.';
            }
            else
            {
              cout << 'o';
            }
          }
        }
        iter += v;
        block_iter++;
      }
      else
      {
        cout << s[iter];
        iter++;
      }
    }
    cout << endl;
  }
  else
  {
    cout << s << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
