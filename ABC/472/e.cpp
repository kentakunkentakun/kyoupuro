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
  ll t;
  cin >> t;
  rep(T, t)
  {
    ll n, m;
    cin >> n >> m;
    vvll t(n, vll(0));
    rep(i, m)
    {
      ll a, b;
      cin >> a >> b;
      a--;
      b--;
      t[a].pb(b);
      t[b].pb(a);
    }
    vll tmp(0);
    vll used(n, 0);
    vll dist(n, -1);
    vb kk(n, false);
    auto dfs = [&](auto dfs, ll now, ll par) -> bool
    {
      // cout << "now :" << now << " " << dist[now] << " " << par << endl;
      tmp.pb(now);
      kk[now] = true;
      for (auto nx : t[now])
      {
        if (nx != par)
        {
          if (dist[nx] != -1)
          {
            // cout << "now :kkkk" << dist[now] << " " << dist[nx] << " " << nx << endl;
            if ((dist[now] - dist[nx]) % 2 == 0)
            {
              cout << dist[now] - dist[nx] + 1 << endl;
              ll cnt = dist[now] - dist[nx] + 1;
              repR(i, tmp.size())
              {
                cout << tmp[i] + 1 << " ";
                cnt--;
                if (cnt == 0)
                  break;
              }
              cout << endl;
              return true;
            }
          }
          if (!kk[nx])
          {
            dist[nx] = dist[now] + 1;
            // cout << now << " to :" << nx << endl;

            if (dfs(dfs, nx, now))
            {
              return true;
            }
          }
        }
      }
      used[now] = 0;
      tmp.pop_back();
      return false;
    };
    bool ok = false;
    rep(i, n)
    {
      if (!kk[i])
      {
        kk[i] = 1;
        dist[i] = 0;
        if (dfs(dfs, i, -1))
        {
          ok = true;
          break;
        }
      }
    }
    if (!ok)
      cout << -1 << endl;
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
