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
  vector<ld> x(2 * n), y(2 * n);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }
  rep(i, n)
  {
    x[i + n] = x[i];
    y[i + n] = y[i];
  }
  Mo mo = Mo(2 * n);
  rep(i, q)
  {
    ll l, r;
    cin >> l >> r;
    l--;
    if (l > r)
    {
      r += n;
    }
    mo.add_query(l, r);
  }
  ld sum_x = 0, sum_y = 0;
  ld sum = 0;
  deque<pair<ld, ld>> que;
  vector<pair<ld, ld>> ans(q);
  auto addl = [&](ll i)
  {
    if (que.size() > 0)
    {
      auto t = que.front();
      sum += x[i] * t.S - t.F * y[i];
      sum_x += (x[i] + t.F) * (x[i] * t.S - t.F * y[i]);
      sum_y += (y[i] + t.S) * (x[i] * t.S - t.F * y[i]);
    }
    que.push_front({x[i], y[i]});
  };
  auto addr = [&](ll i)
  {
    if (que.size() > 0)
    {
      auto t = que.back();
      sum += t.F * y[i] - x[i] * t.S;
      sum_x += (x[i] + t.F) * (t.F * y[i] - x[i] * t.S);
      sum_y += (y[i] + t.S) * (t.F * y[i] - x[i] * t.S);
    }
    que.push_back({x[i], y[i]});
  };
  auto dell = [&](ll i)
  {
    que.pop_front();
    if (que.size() > 0)
    {
      auto t = que.front();
      sum -= x[i] * t.S - t.F * y[i];
      sum_x -= (x[i] + t.F) * (x[i] * t.S - t.F * y[i]);
      sum_y -= (y[i] + t.S) * (x[i] * t.S - t.F * y[i]);
    }
  };
  auto delr = [&](ll i)
  {
    que.pop_back();
    if (que.size() > 0)
    {
      auto t = que.back();
      sum -= t.F * y[i] - x[i] * t.S;
      sum_x -= (x[i] + t.F) * (t.F * y[i] - x[i] * t.S);
      sum_y -= (y[i] + t.S) * (t.F * y[i] - x[i] * t.S);
    }
  };
  auto out = [&](ll i)
  {
    auto tl = que.front();
    auto tr = que.back();
    ld c = tr.F * tl.S - tl.F * tr.S;
    ld sum_xt = sum_x + (tr.F + tl.F) * c;
    ld sum_yt = sum_y + (tr.S + tl.S) * c;
    ld sum_t = c + sum;
    ans[i].F = sum_xt / (sum_t * 3);
    ans[i].S = sum_yt / (sum_t * 3);
  };
  mo.run(addl, addr, dell, delr, out);
  cout << fixed << setprecision(10);

  rep(i, q)
  {
    cout << ans[i].F << " " << ans[i].S << endl;
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
