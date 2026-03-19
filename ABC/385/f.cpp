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
const ll MOD = 1000000007LL;
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
// Geometry
const long double eps = 1e-9;
bool equal(long double a, long double b) { return abs(a - b) < eps; }

// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V
{
  long double x, y;
  V(long double x = 0, long double y = 0) : x(x), y(y) {}
  V &operator+=(const V &v)
  {
    x += v.x;
    y += v.y;
    return *this;
  }
  V operator+(const V &v) const { return V(*this) += v; }
  V &operator-=(const V &v)
  {
    x -= v.x;
    y -= v.y;
    return *this;
  }
  V operator-(const V &v) const { return V(*this) -= v; }
  V &operator*=(long double s)
  {
    x *= s;
    y *= s;
    return *this;
  }
  V operator*(long double s) const { return V(*this) *= s; }
  V &operator/=(long double s)
  {
    x /= s;
    y /= s;
    return *this;
  }
  V operator/(long double s) const { return V(*this) /= s; }
  long double dot(const V &v) const { return x * v.x + y * v.y; }
  long double cross(const V &v) const { return x * v.y - v.x * y; }
  long double norm2() const { return x * x + y * y; }
  long double norm() const { return sqrt(norm2()); }
  V normalize() const { return *this / norm(); }
  V rotate90() const { return V(y, -x); }
  int ort() const
  { // orthant
    if (abs(x) < eps && abs(y) < eps)
      return 0;
    if (y > 0)
      return x > 0 ? 1 : 2;
    else
      return x > 0 ? 4 : 3;
  }
  bool operator<(const V &v) const
  {
    int o = ort(), vo = v.ort();
    if (o != vo)
      return o < vo;
    return cross(v) > 0;
  }
};
istream &operator>>(istream &is, V &v)
{
  is >> v.x >> v.y;
  return is;
}
ostream &operator<<(ostream &os, const V &v)
{
  os << "(" << v.x << "," << v.y << ")";
  return os;
}
struct Line
{
  V s, t;
  Line(V s = V(0, 0), V t = V(0, 0)) : s(s), t(t) {}
  V dir() const { return t - s; }
  V normalize() const { return dir().normalize(); }
  long double norm() const { return dir().norm(); }
  /* +1: s-t,s-p : ccw
   * -1: s-t,s-p : cw
   * +2: t-s-p
   * -2: s-t-p
   *  0: s-p-t */
  int ccw(const V &p) const
  {
    if (dir().cross(p - s) > eps)
      return +1;
    if (dir().cross(p - s) < -eps)
      return -1;
    if (dir().dot(p - s) < -eps)
      return +2;
    if (dir().dot(t - p) < -eps)
      return -2;
    return 0;
  }
  bool touch(const Line &l) const
  {
    int a = ccw(l.s) * ccw(l.t), b = l.ccw(s) * l.ccw(t);
    return !a || !b || (a == -1 && b == -1);
  }

  V divpoint(long double p) const
  {
    return s * (1 - p) + t * p;
  }
  long double distSP(V p) const
  {
    if ((p - s).dot(t - s) < eps)
      return (s - p).norm();
    if ((p - t).dot(s - t) < eps)
      return (t - p).norm();
    return abs((s - p).cross(t - p)) / (t - s).norm();
  }
};

int main()
{
  ll n;
  cin >> n;
  vector<pair<ld, ld>> p(n);
  rep(i, n)
  {
    cin >> p[i].F >> p[i].S;
  }

  sort(all(p));
  // 　全て？
  V k = {p[0].F, p[0].S};
  bool all = true;
  rep(i, n)
  {
    if (i == 0)
      continue;
    ld c = k.cross({p[i].F, p[i].S});
    if (c <= 0)
    {
      all = false;
      break;
    }

    k = {p[i].F, p[i].S};
  }
  if (all)
  {
    cout << -1 << endl;
    return 0;
  }

  ld wa = 0, ac = INF;
  auto judge = [&](ld wj) -> bool
  {
    V k = {p[0].F, p[0].S - wj};
    rep(i, n)
    {
      if (i == 0)
        continue;
      ld c = k.cross({p[i].F, p[i].S - wj});
      if (c <= 0)
      {
        return false;
      }
      k = {p[i].F, p[i].S - wj};
    }
    return true;
  };
  rep(i, 300)
  {
    ld mid = (wa + ac) / 2;
    if (judge(mid))
    {
      ac = mid;
    }
    else
    {
      wa = mid;
    }
  }
  cout << fixed << setprecision(18);
  cout << wa << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
