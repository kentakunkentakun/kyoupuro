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
  ll n, m;
  cin >> n >> m;
  vll used(n, -1);
  used[0] = 1;
  vvll t(n, vll(0));
  vll tansaku(0);
  tansaku.pb(0);
  while (1)
  {
    ll now = tansaku[tansaku.size() - 1];
    string s;
    cin >> s;
    if (s == "OK")
    {
      break;
    }
    ll k = stoi(s);
    if (k == -1)
    {
      break;
    }
    ll nv;
    vll v(k);
    rep(i, k)
    {
      cin >> v[i];
      v[i]--;
    }
    if (t[now].size() != v.size())
    {
      t[now] = v;
    }
    bool move = false;
    rep(i, k)
    {
      if (used[v[i]] == -1)
      {
        tansaku.pb(v[i]);
        used[v[i]] = 1;
        move = true;
        cout << tansaku[tansaku.size() - 1] + 1 << endl;
        break;
      }
    }
    if (!move)
    {
      tansaku.pop_back();
      cout << tansaku[tansaku.size() - 1] + 1 << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
