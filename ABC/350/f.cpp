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
int main()
{
  string s;
  cin >> s;
  ll n = s.size();
  vll t(n, -1);
  stack<ll> st;
  rep(i, n)
  {
    if (s[i] == '(')
    {
      st.push(i);
    }
    else if (s[i] == ')')
    {
      ll s = st.top();
      st.pop();
      t[s] = i;
    }
  }
  int rev = 0;
  vector<char> ans(n);
  st.push(0);
  rep(i, n)
  {
    if (s[i] == '(')
    {
      ll now = st.top();
      st.pop();
      ll nx = t[i];
      if (rev)
      {
        st.push(now - (nx - i + 1));
        st.push(now - (nx - i));
      }
      else
      {
        st.push(now + nx - i + 1);
        st.push(now + nx - i);
      }
      rev = 1 - rev;
    }
    if (rev)
    {
      ll now = st.top();
      st.pop();
      if (s[i] == '(' || s[i] == ')')
      {
        ans[now] = '$';
      }
      else if (isupper(s[i]))
      {
        ans[now] = (char)('a' + (s[i] - 'A'));
      }
      else
      {
        ans[now] = (char)('A' + (s[i] - 'a'));
      }
      st.push(now - 1);
    }
    else
    {

      ll now = st.top();
      st.pop();
      if (s[i] == '(' || s[i] == ')')
      {
        ans[now] = '$';
      }
      else
      {
        ans[now] = s[i];
      }
      st.push(now + 1);
    }

    if (s[i] == ')')
    {
      rev = 1 - rev;
      st.pop();
    }
  }
  rep(i, n)
  {
    if (ans[i] != '$')
      cout << ans[i];
  }
  cout << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
