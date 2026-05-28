#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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
struct S
{
  ll it, v;
};
S op(S a, S b)
{
  if (a.v < b.v)
  {
    return a;
  }
  return b;
}
S e()
{
  return {-1, INF};
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vll l(m), r(m);
  ll ma = 2 * 100000 + 5;
  vvll L(ma, vll(0));
  vvll R(ma, vll(0));
  vvll t(ma, vll(0));
  segtree<S, op, e> seg(ma);
  set<pll> S;
  rep(i, m)
  {
    cin >> l[i] >> r[i];
    L[l[i]].pb(r[i]);
    R[r[i]].pb(l[i]);
    ll now = seg.get(l[i]).v;
    if (now > r[i])
    {
      seg.set(l[i], {i, r[i]});
    }
    S.insert({l[i], r[i]});
  }
  rep(i, ma)
  {
    sort(all(L[i]));
    sort(all(R[i]));
  }
  ll q;
  cin >> q;
  rep(i, q)
  {
    ll s, t;
    cin >> s >> t;
    if (S.count({s, t}))
    {
      if (L[s][0] == t)
      {
        if (L[s].size() > 1)
        {
          seg.set(s, {-1, L[s][1]});
        }
        else
        {
          seg.set(s, {-1, INF});
        }
      }
      auto tmp = seg.prod(s, t + 1);
      ll res = seg.prod(s, t + 1).v;
      if (res <= t)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
      if (L[s][0] == t)
      {
        seg.set(s, {-1, L[s][0]});
      }
      continue;
    }

    auto lit = upper_bound(all(L[s]), t);
    auto rit = lower_bound(all(R[t]), s);

    if (lit == L[s].begin() || rit == R[t].end())
    {
      cout << "No" << endl;
    }
    else
    {
      lit--;
      if (*lit + 1 >= *rit)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }
  }
}
