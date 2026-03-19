#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
int solve(ll T)
{
  ll n;
  cin >> n;
  vll a(n);
  vll d(n);
  set<ll> s;
  // 絶対値ごとの個数
  map<ll, ll> cnt;
  rep(i, n)
  {
    cin >> a[i];
    s.insert(a[i]);
    d[i] = abs(a[i]);
    cnt[d[i]]++;
  }
  if (n == 2)
  {
    cout << 0 << endl;
    return 0;
  }
  sort(all(d));
  set<ll> tmp;
  rep(i, n)
  {
    tmp.insert(d[i]);
  }
  // 全部絶対値が同じ
  if (tmp.size() == 1)
  {
    ll plus = 0, minus = 0;
    rep(i, n)
    {
      if (a[i] < 0)
        minus++;
      else if (a[i] > 0)
        plus++;
    }
    cout << min(minus, plus) << endl;
    return 0;
  }
  // 値は異なるものがある
  // 3つ以上おなじのがあったら死
  for (auto p : cnt)
  {
    if (p.S >= 3)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  // 0が2個以上あったら死
  if (d[0] == 0 && d[1] == 0)
  {
    cout << -1 << endl;
    return 0;
  }

  // 0が一個だけあったら
  if (s.count(0))
  {
    // 個数が222221111になっているか確認
    bool ok = true;
    // 今1か2
    bool istwo = true;
    cnt.erase(0);
    for (auto p : cnt)
    {
      auto [_, c] = p;
      if (istwo && c == 1)
      {
        istwo = false;
      }
      else if (!istwo && c == 2)
      {
        ok = false;
        break;
      }
    }
    if (!ok)
    {
      cout << -1 << endl;
      return 0;
    }
    ll sa = d[1];
    // dを見て等差数列になるか確認
    ll ans = 0;
    ll now = 0;
    ll plus_cost = 0;
    ll minus_cost = 0;
    for (auto p : cnt)
    {
      auto [num, c] = p;
      if (now + sa == num)
      {
        now += sa;
        if (c == 2)
        {
          if (s.count(num) && s.count(-1 * num))
          {
          }
          else
          {
            ans++;
          }
        }
        else
        {
          if (s.count(num))
          {
            minus_cost++;
          }
          else
          {
            plus_cost++;
          }
        }
      }
      else
      {
        // 等差数列じゃない
        cout << -1 << endl;
        return 0;
      }
    }
    cout << ans + min(plus_cost, minus_cost) << endl;
    return 0;
  }

  // 最初の二個同じだったら
  else if (d[0] == d[1])
  {
    bool ok = true;
    // 今1か2
    bool istwo = true;
    for (auto p : cnt)
    {
      auto [_, c] = p;
      if (istwo && c == 1)
      {
        istwo = false;
      }
      else if (!istwo && c == 2)
      {
        ok = false;
        break;
      }
    }
    if (!ok)
    {
      cout << -1 << endl;
      return 0;
    }
    ll sa = d[0] * 2;
    // dを見て等差数列になるか確認
    ll ans = 0;
    if (!(s.count(d[0]) && s.count(-1 * d[0])))
      ans++;
    ll now = d[0];
    ll plus_cost = 0;
    ll minus_cost = 0;
    for (auto p : cnt)
    {
      auto [num, c] = p;
      if (num == now)
        continue;
      if (now + sa == num)
      {
        now += sa;
        if (c == 2)
        {
          if (s.count(num) && s.count(-1 * num))
          {
          }
          else
          {
            ans++;
          }
        }
        else
        {
          if (s.count(num))
          {
            minus_cost++;
          }
          else
          {
            plus_cost++;
          }
        }
      }
      else
      {
        // 等差数列じゃない
        cout << -1 << endl;
        return 0;
      }
    }
    cout << ans + min(plus_cost, minus_cost) << endl;
    return 0;
  }
  // 0がないし最初の2個も同じじゃない
  // ミラーじゃない
  else
  {
    bool ok = true;
    for (auto p : cnt)
    {
      auto [_, c] = p;
      if (c != 1)
        ok = false;
    }
    if (!ok)
    {
      cout << -1 << endl;
      return 0;
    }
    // 全部cntが1でした。
    ll ans = INF;
    for (int i = -1; i < 2; i += 2)
    {
      for (int j = -1; j < 2; j += 2)
      {
        // 最小値
        ll res = 0;

        ll left = i * d[0];
        ll right = j * d[1];
        if (left > right)
        {
          swap(left, right);
        }
        ll sa = right - left;
        // 等差数列に参加した数
        ll count = 2;
        if (!s.count(i * d[0]))
          res++;
        if (!s.count(j * d[1]))
          res++;

        bool tmp_ok = true;
        while (count < n)
        {
          if ((abs(left - sa) != d[0] && abs(left - sa) != d[1]) && s.count(left - sa))
          {
            count++;
            left -= sa;
          }
          else if ((abs(left - sa) != d[0] && abs(left - sa) != d[1]) && s.count(-1 * (left - sa)))
          {
            count++;
            res++;
            left -= sa;
          }
          else if ((abs(right + sa) != d[0] && abs(right + sa) != d[1]) && s.count(right + sa))
          {
            count++;
            right += sa;
          }
          else if ((abs(right + sa) != d[0] && abs(right + sa) != d[1]) && s.count(-1 * (right + sa)))
          {
            count++;
            right += sa;
            res++;
          }
          else
          {
            tmp_ok = false;
            break;
          }
        }

        if (tmp_ok)
        {
          chmin(ans, res);
        }
      }
    }
    if (ans == INF)
      ans = -1;
    cout << ans << endl;
    return 0;
  }
}
int main()
{
  ll t;
  cin >> t;
  rep(T, t)
  {
    solve(T);
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
