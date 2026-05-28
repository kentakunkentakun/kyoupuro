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
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    stack<pll> st;
    ll ans = 0;
    rep(i, n - 1)
    {
      if (a[i] >= a[i + 1])
      {
        ll l = (a[i] + a[i + 1]) / 2;
        ll r = (a[i] + a[i + 1] + 1) / 2;
        if (l == r)
        {
          l--;
          r++;
        }
        ans += a[i] - l;
        a[i] = l;
        a[i + 1] = r;
        if (i > 0)
        {
          while (a[i - 1] >= a[i])
          {
            if (st.size())
            {
              auto [cnt, it] = st.top();
              st.pop();
              ll r_cost = a[i - 1] + 2 - a[i + 1];
              ll l_cost = a[i - 1] + 1 - a[i];
              if (cnt >= r_cost)
              {
                ans += a[i - 1] + 2 - a[i + 1] * (i + 1 - it);
                cnt -= a[i - 1] + 2 - a[i + 1];
                a[it] -= a[i - 1] + 2 - a[i + 1];
                a[i + 1] = a[i - 1] + 2;
              }
              else
              {
                ans += cnt * (i + 1 - it);
                a[it] -= cnt;
                a[i + 1] += cnt;
                cnt = 0;
              }
              if (cnt >= l_cost)
              {
                ans += l_cost * (i - it);
                cnt -= l_cost;
                a[it] -= a[i - 1] + 1 - a[i];
                a[i] = a[i - 1] + 1;
              }
              else
              {
                ans += cnt * (i - it);
                a[it] -= cnt;
                a[i] += cnt;
                cnt = 0;
              }
              if (cnt > 0)
              {
                st.push({cnt, it});
              }
            }
            else
            {
              ll need = 2 * a[i - 1] + 3 - a[i] - a[i + 1];
              ll all = (i + 1) * i / 2;
              ans += need / i * all;
              need %= i;
              ll no = i - need;
              ans += all - (no + 1) * no / 2;
            }
          }
        }
      }
      if (i > 0 && a[i - 1] - a[i] > 1)
      {
        st.push({a[i] - a[i - 1] - 1, i});
      }
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
