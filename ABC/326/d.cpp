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
  ll n;
  cin >> n;
  string r;
  string c;
  cin >> r >> c;
  vll tmp(n);
  vll tmp2(n, -1);
  auto dfs = [&](auto dfs, int i) -> bool
  {
    if (i == n)
    {
      tmp2 = vll(n, -1);
      ll cnt = 0;
      rep(j, n)
      {
        rep(z, n)
        {
          if (j > tmp[z])
          {
            tmp2[j] = z;
            cnt++;
            break;
          }
          else if (j == tmp[z])
          {
            if (r[z] == c[j])
            {
              tmp2[j] = z;
              cnt++;
              break;
            }
            else
            {
              break;
            }
          }
        }
      }
      if (cnt != n)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    rep(j, n)
    {
      tmp[i] = j;
      if (dfs(dfs, i + 1))
      {
        return true;
      }
    }
    return false;
  };
  if (dfs(dfs, 0))
  {
    cout << "Yes" << endl;
    vector<vector<char>> t(n, vector<char>(n, '.'));
    rep(i, n)
    {
      t[i][tmp[i]] = r[i];
    }
    rep(i, n)
    {
      t[tmp2[i]][i] = c[i];
    }
    rep(i, n)
    {
      rep(j, n)
      {
        cout << t[i][j];
      }
      cout << endl;
    }
  }
  else
  {
    cout << "No" << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
