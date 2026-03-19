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
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x, vector<x>, greater<x>>
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
// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
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
template <class T = ll>
struct Mo
{
  ll n;
  vector<pair<ll, ll>> qs; // [l, r)

  Mo(ll n) : n(n) {}

  void add_query(ll l, ll r)
  {
    qs.emplace_back(l, r);
  }

  template <class AddLeft, class AddRight, class DelLeft, class DelRight, class Out>
  void run(AddLeft add_left, AddRight add_right,
           DelLeft del_left, DelRight del_right,
           Out out)
  {
    ll q = (ll)qs.size();
    ll bs = max(1LL, (ll)(n / max(1.0, sqrt((double)q))));

    vector<ll> ord(q);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](ll a, ll b)
         {
            auto [l1, r1] = qs[a];
            auto [l2, r2] = qs[b];
            ll b1 = l1 / bs, b2 = l2 / bs;
            if (b1 != b2) return b1 < b2;
            if (b1 & 1) return r1 > r2;
            return r1 < r2; });

    ll l = 0, r = 0; // [l, r)

    for (ll idx : ord)
    {
      auto [nl, nr] = qs[idx];

      while (l > nl)
        add_left(--l);
      while (r < nr)
        add_right(r++);
      while (l < nl)
        del_left(l++);
      while (r > nr)
        del_right(--r);

      out(idx);
    }
  }
};

int main()
{
  ll n, q;
  cin >> n >> q;
  vll a(n);
  rep(i, n) cin >> a[i];
  vll l(q), r(q);
  Mo mo = Mo(n);
  rep(i, q)
  {
    cin >> l[i] >> r[i];
    l[i]--;
    mo.add_query(l[i], r[i]);
  }
  ll res = 0;
  vll ans(q);
  vll cnt(2 * 100000 + 5);
  auto add = [&](ll i)
  {
    if (cnt[a[i]] >= 2)
    {
      res += cnt[a[i]] * (cnt[a[i]] - 1) / 2;
    }
    cnt[a[i]]++;
  };
  auto del = [&](ll i)
  {
    cnt[a[i]]--;
    if (cnt[a[i]] >= 2)
    {
      res -= cnt[a[i]] * (cnt[a[i]] - 1) / 2;
    }
  };
  auto out = [&](ll i)
  {
    ans[i] = res;
  };
  mo.run(add, add, del, del, out);
  rep(i, q)
  {
    cout << ans[i] << endl;
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
