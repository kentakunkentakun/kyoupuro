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
  vector<string> s(n);
  map<string, ll> m;
  rep(i, n)
  {
    cin >> s[i];
  }
  auto comp = [&](string a, string b) -> bool
  {
    if (a.size() < b.size())
    {
      return true;
    }
    if (b.size() < a.size())
    {
      return false;
    }
    rep(i, a.size())
    {
      if (a[i] < b[i])
      {
        return true;
      }
      else if (a[i] > b[i])
      {
        return false;
      }
    }
    return false;
  };
  sort(all(s), comp);
  rep(i, n)
  {
    reverse(all(s[i]));
    m[s[i]]++;
  }
  vector<tuple<string, ll, ll>> p(0);
  auto add = [&](string s, string f) -> string
  {
    ll tmp = 0;
    if (s.size() > f.size())
    {
      swap(s, f);
    }
    string ans = "";
    rep(i, f.size())
    {
      if (i < s.size())
      {
        tmp += (f[i] - '0') + (s[i] - '0');
      }
      else
      {
        tmp += (f[i] - '0');
      }
      ans += (char)('0' + tmp % 10);
      tmp /= 10;
    }
    while (tmp)
    {
      ans += (char)('0' + tmp % 10);
      tmp /= 10;
    }
    return ans;
  };
  auto multi = [&](string s, string f) -> string
  {
    if (s.size() > f.size())
    {
      swap(s, f);
    }
    string res = "0";
    string ini = "";
    rep(i, s.size())
    {
      string res = ini;
      ll tmp = 0;
      rep(j, f.size())
      {
        tmp += (s[i] - '0') * (f[i] - '0');
        res += (char)('0' + tmp % 10);
        tmp /= 10;
      }
      ini += "0";
    }
  };

  // s > f;
  auto sub = [&](string s, string f) -> string {

  };
  rep(i, n)
  {
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
