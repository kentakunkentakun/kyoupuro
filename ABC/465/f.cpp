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
template <class T>
struct PrefixSumND
{
  int dim;
  vector<ll> n;
  vector<ll> len; // sz から変更
  vector<ll> stride;
  vector<T> s;
  bool built = false;

  PrefixSumND(const vector<ll> &dims)
      : dim((int)dims.size()), n(dims), len(dim), stride(dim)
  {
    ll total = 1;

    for (int i = dim - 1; i >= 0; i--)
    {
      assert(n[i] >= 0);
      len[i] = n[i] + 1;
      stride[i] = total;
      total *= len[i];
    }

    s.assign((size_t)total, T{});
  }

  ll id(const vector<ll> &p) const
  {
    assert((int)p.size() == dim);

    ll res = 0;
    for (int i = 0; i < dim; i++)
    {
      assert(0 <= p[i] && p[i] <= n[i]);
      res += p[i] * stride[i];
    }
    return res;
  }

  void add(const vector<ll> &pos, T val)
  {
    assert(!built);
    assert((int)pos.size() == dim);

    vector<ll> p(dim);
    for (int i = 0; i < dim; i++)
    {
      assert(0 <= pos[i] && pos[i] < n[i]);
      p[i] = pos[i] + 1;
    }

    s[id(p)] += val;
  }

  void build()
  {
    assert(!built);

    ll total = (ll)s.size();

    for (int axis = 0; axis < dim; axis++)
    {
      ll step = stride[axis];
      ll axis_len = len[axis];
      ll period = step * axis_len;

      for (ll base = 0; base < total; base += period)
      {
        for (ll off = 0; off < step; off++)
        {
          for (ll k = 1; k < axis_len; k++)
          {
            ll cur = base + off + k * step;
            s[cur] += s[cur - step];
          }
        }
      }
    }

    built = true;
  }

  T prefix(const vector<ll> &upper) const
  {
    assert(built);
    assert((int)upper.size() == dim);
    return s[id(upper)];
  }

  T sum(const vector<ll> &l, const vector<ll> &r) const
  {
    assert(built);
    assert((int)l.size() == dim);
    assert((int)r.size() == dim);
    assert(dim <= 20);

    for (int i = 0; i < dim; i++)
    {
      assert(0 <= l[i] && l[i] <= r[i] && r[i] <= n[i]);
    }

    T res = T{};
    vector<ll> p(dim);

    for (ll mask = 0; mask < (1LL << dim); mask++)
    {
      int bits = 0;

      for (int i = 0; i < dim; i++)
      {
        if ((mask >> i) & 1)
        {
          p[i] = l[i];
          bits++;
        }
        else
        {
          p[i] = r[i];
        }
      }

      if (bits & 1)
        res -= s[id(p)];
      else
        res += s[id(p)];
    }

    return res;
  }
};
int main()
{
  ll n;
  cin >> n;
  PrefixSumND<ll> ps({10, 10, 10, 10, 10, 10});
  rep(i, n)
  {
    string s;
    cin >> s;
    ll v;
    cin >> v;
    vll tmp(0);
    rep(j, 6)
    {
      tmp.pb(s[j] - '0');
    }
    ps.add(tmp, v);
  }
  ps.build();
  ll q;
  cin >> q;
  rep(i, q)
  {
    string l, r;
    cin >> l >> r;
    bool ok = true;
    rep(j, 6)
    {
      if (l[j] > r[j])
      {
        ok = false;
      }
    }
    if (!ok)
    {
      cout << 0 << endl;
      continue;
    }
    vll lk(6);
    vll rk(6);
    rep(j, 6)
    {
      lk[j] = l[j] - '0';
      rk[j] = (r[j] - '0') + 1;
    }
    cout << ps.sum(lk, rk) << endl;
    // ll ans = 0;
    // for (int bit = 1; bit < (1 << 6); bit++)
    // {
    //   vll lk(6);
    //   vll rk(6);
    //   rep(j, 6)
    //   {
    //     if (bit >> j & 1)
    //     {
    //       lk[j] = l[j] - '0';
    //       rk[j] = (r[j] - '0') + 1;
    //     }
    //     else
    //     {
    //       lk[j] = 0;
    //       rk[j] = 10;
    //     }
    //   }
    //   if (__builtin_popcountll(bit) % 2)
    //   {
    //     ans += ps.sum(lk, rk);
    //   }
    //   else
    //   {
    //     ans -= ps.sum(lk, rk);
    //   }
    // }
    // cout << ans << endl;
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
