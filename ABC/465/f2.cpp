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
using vvvvll = vector<vvvll>;
using vvvvvll = vector<vvvvll>;
using vvvvvvll = vector<vvvvvll>;
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
ll m = 12;
ll d[12][12][12][12][12][12];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<string> s(n);
  vll v(n);
  rep(i, n)
  {
    cin >> s[i];
    cin >> v[i];
    d[(s[i][0] - '0') + 1][s[i][1] - '0' + 1][s[i][2] - '0' + 1][s[i][3] - '0' + 1][s[i][4] - '0' + 1][s[i][5] - '0' + 1] += v[i];
  }
  rep(i, m - 1)
  {
    rep(j, m)
    {
      rep(z, m)
      {
        rep(a, m)
        {
          rep(b, m)
          {
            rep(c, m)
            {
              d[i + 1][j][z][a][b][c] += d[i][j][z][a][b][c];
            }
          }
        }
      }
    }
  }
  rep(i, m - 1)
  {
    rep(j, m)
    {
      rep(z, m)
      {
        rep(a, m)
        {
          rep(b, m)
          {
            rep(c, m)
            {
              d[j][i + 1][z][a][b][c] += d[j][i][z][a][b][c];
            }
          }
        }
      }
    }
  }
  rep(i, m - 1)
  {
    rep(j, m)
    {
      rep(z, m)
      {
        rep(a, m)
        {
          rep(b, m)
          {
            rep(c, m)
            {
              d[j][z][i + 1][a][b][c] += d[j][z][i][a][b][c];
            }
          }
        }
      }
    }
  }
  rep(i, m - 1)
  {
    rep(j, m)
    {
      rep(z, m)
      {
        rep(a, m)
        {
          rep(b, m)
          {
            rep(c, m)
            {
              d[j][z][a][i + 1][b][c] += d[j][z][a][i][b][c];
            }
          }
        }
      }
    }
  }
  rep(i, m - 1)
  {
    rep(j, m)
    {
      rep(z, m)
      {
        rep(a, m)
        {
          rep(b, m)
          {
            rep(c, m)
            {
              d[j][z][a][b][i + 1][c] += d[j][z][a][b][i][c];
            }
          }
        }
      }
    }
  }
  rep(i, m - 1)
  {
    rep(j, m)
    {
      rep(z, m)
      {
        rep(a, m)
        {
          rep(b, m)
          {
            rep(c, m)
            {
              d[j][z][a][b][c][i + 1] += d[j][z][a][b][c][i];
            }
          }
        }
      }
    }
  }
  ll q;
  cin >> q;
  auto f = [&](vll &Y, vll &X) -> ll
  {
    ll cnt = 0;
    for (int bit = 0; bit < (1 << 6); bit++)
    {
      vll k(6);
      ll now = bit;
      rep(j, 6)
      {
        if (now & 1)
        {
          k[j] = Y[j];
        }
        else
        {
          k[j] = X[j];
        }
        now /= 2;
      }
      if (__builtin_popcountll(bit) % 2)
      {
        cnt -= d[k[0]][k[1]][k[2]][k[3]][k[4]][k[5]];
      }
      else
      {
        cnt += d[k[0]][k[1]][k[2]][k[3]][k[4]][k[5]];
      }
    }
    return cnt;
  };
  rep(i, q)
  {
    string x, y;
    cin >> x >> y;
    vll X, Y;
    bool ok = true;
    rep(j, 6)
    {
      if (x[j] > y[j])
      {
        ok = false;
        continue;
      }
      X.pb(x[j] - '0');
      Y.pb(y[j] - '0' + 1);
    }
    if (ok)
      cout << max(0LL, f(Y, X)) << endl;
    else
    {
      cout << 0 << endl;
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
