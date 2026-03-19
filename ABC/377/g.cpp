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
struct Trie
{
  struct Node
  {
    map<char, ll> to;
    ll len;
    Node(ll l = 0)
    {
      len = l;
    }
  };
  vector<Node> d;
  Trie() : d(1)
  {
    d[0].len = 0;
  };

  void add(const string &s)
  {
    ll v = 0;
    rep(i, s.size())
    {
      char c = s[i];
      if (!d[v].to.count(c))
      {
        d[v].to[c] = d.size();
        d.push_back(Node((ll)s.size() - i - 1));
      }
      v = d[v].to[c];
      chmin(d[v].len, (ll)s.size() - i - 1);
    }
  }
  ll solve(const string &s)
  {
    ll ans = INF;
    ll v = 0;
    chmin(ans, d[v].len + (ll)s.size());
    rep(i, s.size())
    {
      char c = s[i];
      if (!d[v].to.count(c))
      {
        break;
      }
      v = d[v].to[c];
      chmin(ans, (ll)s.size() - i - 1 + d[v].len);
    }
    return ans;
  }
};
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
int main()
{
  ll n;
  cin >> n;
  Trie t;
  rep(i, n)
  {
    string s;
    cin >> s;
    cout << t.solve(s) << endl;
    t.add(s);
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
