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
int main()
{
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vll r(n + 1);
  double ac = 0, wa = 1;
  auto judge = [&](double wj) -> bool
  {
    vector<double> r(n + 1, -INF);
    vector<double> d(n + 1);
    rep(i, n)
    {
      d[i + 1] += d[i];
      if (s[i] == 'o')
      {
        d[i + 1] += 1 - wj;
      }
      else
      {
        d[i + 1] -= wj;
      }
    }
    repR(i, n)
    {
      chmax(r[i + 1], d[i + 1]);
      if (i < n - 1)
      {
        chmax(r[i + 1], r[i + 2]);
      }
    }
    ll rt = 0;
    ll cnt = 0;
    rep(i, n)
    {
      while (cnt < k && rt < n)
      {
        if (s[rt] == 'o')
        {
          cnt++;
        }
        rt++;
      }
      if (cnt < k)
      {
        break;
      }
      if (r[rt] >= d[i])
      {
        return true;
      }
      if (s[i] == 'o')
      {
        cnt--;
      }
    }
    return false;
  };

  rep(w, 70)
  {
    double wj = (wa + ac) / 2.0;
    if (judge(wj))
    {
      ac = wj;
    }
    else
    {
      wa = wj;
    }
  }
  cout << fixed << setprecision(10);
  cout << ac << endl;
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
