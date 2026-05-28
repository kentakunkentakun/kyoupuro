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
struct Aho
{
  using MP = unordered_map<char, ll>;
  vector<MP> to;
  vector<ll> fail, termi, order;
  Aho() : to(1), order(0) {}
  ll add(const string &s, ll i)
  {
    ll v = 0;
    for (char c : s)
    {
      if (!to[v].count(c))
      {
        to[v][c] = to.size();
        to.push_back(MP());
      }
      v = to[v][c];
    }
    termi.pb(v);
    return v;
  }
  void init()
  {
    fail = vector<ll>(to.size(), -1);
    queue<ll> q;
    q.push(0);
    while (!q.empty())
    {
      ll v = q.front();
      q.pop();
      order.pb(v);
      for (auto [c, u] : to[v])
      {
        fail[u] = (*this)(fail[v], c);
        q.push(u);
      }
    }
    reverse(all(order));
  }
  ll operator()(ll v, char c) const
  {
    while (v != -1)
    {
      auto it = to[v].find(c);
      if (it != to[v].end())
        return it->second;
      v = fail[v];
    }
    return 0;
  }
};

int main()
{
  Aho aho;
  string s;
  cin >> s;
  ll q;
  cin >> q;
  rep(i, q)
  {
    string t;
    cin >> t;
    aho.add(t, i);
  }
  aho.init();
  ll v = 0;
  vll ans(q);
  vll V(aho.to.size());
  rep(i, s.size())
  {
    v = aho(v, s[i]);
    V[v]++;
  }
  vll cnt(aho.to.size());

  for (int i = 0; i < aho.to.size() - 1; i++)
  {
    V[aho.fail[aho.order[i]]] += V[aho.order[i]];
  }
  rep(i, q)
  {
    cout << V[aho.termi[i]] << endl;
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
