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
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h)
  {
    cin >> s[i];
  }
  ll ans = 1;

  if (h > w)
  {
    string tmp = "";
    rep(i, h)
    {
      tmp += 'a';
    }
    vector<string> S(w, tmp);

    rep(i, h)
    {
      rep(j, w)
      {
        S[j][i] = s[i][j];
      }
    }
    s = S;
    swap(h, w);
  }
  vvll r(h + 1, vll(w));
  rep(i, w)
  {
    rep(j, h)
    {
      r[j + 1][i] += r[j][i];
      if (s[j][i] == '.')
      {
        r[j + 1][i]++;
      }
    }
  }
  rep(i, h)
  {
    for (int j = i + 1; j <= h; j++)
    {
      // [i,j)
      vll u(w + 1);
      vll d(w + 1);
      vll t(0);
      t.pb(0);
      rep(k, w)
      {
        if (r[j][k] - r[i][k])
          t.pb(k + 1);
        // u
        u[k + 1] += u[k];
        u[k + 1] += (s[i][k] == '.') ? 1 : 0;
        // d
        d[k + 1] += d[k];
        d[k + 1] += (s[j - 1][k] == '.') ? 1 : 0;
      }
      ll it = 0;
      ll res = (t.size() - 1) * t.size() / 2;
      rep(now, t.size())
      {
        chmax(it, now);
        while (it + 1 < t.size() && (u[t[it + 1]] == u[t[now]] || d[t[it + 1]] == d[t[now]]))
        {
          it++;
        }
        res -= (it - now);
      }
      ans += res;
    }
  }
  cout << ans << endl;
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
