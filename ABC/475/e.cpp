#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
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
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T>
using PQ = priority_queue<T>;

template <class T>
using PQR = priority_queue<T, vector<T>, greater<T>>;

// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 62;
const double INF_D = numeric_limits<double>::infinity();

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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct Trie
{
  struct Node
  {
    unordered_map<char, ll> to;
    ll cnt;
    Node() : cnt(0) {}
  };
  vector<Node> d;
  Trie() : d(1) {};

  void add(const string &s)
  {
    ll v = 0;
    for (char c : s)
    {
      if (!d[v].to.count(c))
      {
        d[v].to[c] = d.size();
        d.push_back(Node());
      }
      v = d[v].to[c];
      d[v].cnt++;
    }
  }
  void erase(const string &s)
  {
    ll v = 0;
    for (char c : s)
    {
      v = d[v].to[c];
      d[v].cnt--;
    }
  }

  ll ans;
  ll dfs(string &k)
  {
    ll v = 0;
    ll cnt = 0;
    for (char c : k)
    {
      if (c == '1')
      {
        if (d[v].to.count('0'))
        {
          cnt += d[d[v].to['0']].cnt;
        }
      }
      v = d[v].to[c];
    }
    cnt += d[v].cnt;
    return cnt;
  }
};

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  string t;
  cin >> t;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  Trie trie;
  vector<string> S(n);
  rep(i, n)
  {
    string tmp = "";
    rep(j, k)
    {
      if (t[j] == s[i][j])
      {
        tmp += '0';
      }
      else
      {
        tmp += '1';
      }
    }
    trie.add(tmp);
    S[i] = tmp;
  }
  ll q;
  cin >> q;
  rep(i, q)
  {
    ll it, u;
    cin >> it >> u;
    it--;
    u--;
    trie.erase(S[it]);
    if (S[it][u] == '0')
    {
      S[it][u] = '1';
    }
    else
    {
      S[it][u] = '0';
    }
    trie.add(S[it]);
    ll res = trie.dfs(S[it]);
    if (res <= m && S[it].find('0') != string::npos)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
