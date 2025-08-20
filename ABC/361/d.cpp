#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0; i--)
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
template <class UInt = unsigned long long>
struct NBaseMask
{
  using uint_type = UInt;

  // --- 構築 ---
  // base: 基数(>=2)
  // digits: 使いたい桁数（0 なら入るだけ確保）
  // init: 初期値（N進で詰めた整数）
  NBaseMask(unsigned base, unsigned digits = 0, UInt init = 0)
      : base_(base), val_(init)
  {
    assert(base_ >= 2);
    pow_.reserve(64);
    pow_.push_back(UInt(1));
    // digits==0 のときは、オーバーフローしない最大桁数まで拡張
    const unsigned want = (digits == 0 ? std::numeric_limits<unsigned>::max() : digits);
    while (pow_.size() <= (size_t)want)
    {
      if (pow_.back() > std::numeric_limits<UInt>::max() / UInt(base_))
        break;
      pow_.push_back(pow_.back() * UInt(base_));
    }
    if (digits != 0)
    {
      // 望んだ桁数に足りないときは assert（必要なら __int128 に切替を）
      assert(digits <= max_digits());
    }
    digits_ = (digits == 0 ? max_digits() : digits);
    // init が桁数の範囲を超えない前提（超えるなら桁数を増やすか init を小さく）
    assert(val_ < pow_[digits_] * UInt(base_));
  }

  // --- 基本情報 ---
  unsigned base() const { return base_; }
  unsigned digits() const { return digits_; } // 管理する桁数
  unsigned max_digits() const { return (unsigned)pow_.size() - 1; }
  UInt value() const { return val_; }
  void set_value(UInt v) { val_ = v; }

  // states() = base^digits（この桁数での全状態数）
  UInt states() const { return pow_[digits_]; }

  // --- 桁操作（0-index, 下位桁から） ---
  // 取得：0..base-1
  unsigned get(unsigned i) const
  {
    assert(i < digits_);
    return (unsigned)((val_ / pow_[i]) % UInt(base_));
  }
  // 設定：0..base-1（mod base）
  void set(unsigned i, unsigned d)
  {
    assert(i < digits_);
    d %= base_;
    UInt cur = (UInt)get(i);
    // val += (d - cur) * base^i
    if (d >= cur)
      val_ += (UInt)(d - cur) * pow_[i];
    else
      val_ -= (UInt)(cur - d) * pow_[i];
  }
  // 加算（mod base）
  void add(unsigned i, int delta)
  {
    int d = (int)get(i) + delta;
    d %= (int)base_;
    if (d < 0)
      d += (int)base_;
    set(i, (unsigned)d);
  }
  void inc(unsigned i) { add(i, 1); }
  void dec(unsigned i) { add(i, -1); }

  // 便利：k 桁だけ 1 を立てる（= base^k を返す）
  UInt one(unsigned k) const
  {
    assert(k < pow_.size());
    return pow_[k];
  }

  // --- まとめ操作 ---
  // 全桁を 0 に
  void clear() { val_ = 0; }

  // ベクトル <桁配列(長さ=digits_)> へ展開（各要素 0..base-1）
  std::vector<unsigned> to_digits() const
  {
    std::vector<unsigned> d(digits_);
    for (unsigned i = 0; i < digits_; ++i)
      d[i] = get(i);
    return d;
  }

  // ベクトルから詰める（サイズは digits_ に合わせる／超過は無視）
  void from_digits(const std::vector<unsigned> &d)
  {
    unsigned m = std::min(digits_, (unsigned)d.size());
    val_ = 0;
    for (unsigned i = 0; i < m; ++i)
    {
      unsigned di = d[i] % base_;
      if (di)
        val_ += (UInt)di * pow_[i];
    }
  }

  // 列挙補助：次の状態へ（0..states()-1 の整数そのものを ++ する感覚）
  // 戻り値: 進められたら true、最終状態（繰り上がって桁溢れ）で false
  bool next()
  {
    if (val_ + 1 == pow_[digits_])
      return false;
    ++val_;
    return true;
  }

  // --- 要素ごとの OR/AND 的な合成（定義は用途に応じて） ---
  // ここでは max/min を「OR/AND 的」な合成として提供
  static NBaseMask elem_max(const NBaseMask &A, const NBaseMask &B)
  {
    assert(A.base_ == B.base_);
    unsigned d = std::min(A.digits_, B.digits_);
    NBaseMask C(A.base_, d, 0);
    for (unsigned i = 0; i < d; ++i)
      C.set(i, std::max(A.get(i), B.get(i)));
    return C;
  }
  static NBaseMask elem_min(const NBaseMask &A, const NBaseMask &B)
  {
    assert(A.base_ == B.base_);
    unsigned d = std::min(A.digits_, B.digits_);
    NBaseMask C(A.base_, d, 0);
    for (unsigned i = 0; i < d; ++i)
      C.set(i, std::min(A.get(i), B.get(i)));
    return C;
  }

private:
  unsigned base_;
  unsigned digits_;
  UInt val_;
  std::vector<UInt> pow_; // pow_[k] = base^k
};

constexpr long long ipow(long long a, int e)
{
  long long r = 1;
  while (e)
  {
    if (e & 1)
      r *= a;
    a *= a;
    e >>= 1;
  }
  return r;
}

// base進の下位からk桁目を返す（kは0-index）
inline int digit_baseN(long long n, int base, int k)
{
  return int((n / ipow(base, k)) % base);
}

int main()
{
  ll n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  s += "..";
  t += "..";
  n += 2;
  map<string, ll> dist;
  dist[s] = 0;
  queue<string> que;
  que.push(s);
  while (que.size())
  {
    string now = que.front();
    que.pop();
    ll kara = 0;
    rep(i, n)
    {
      if (now[i] == '.')
      {
        kara = i;
        break;
      }
    }
    rep(i, n - 1)
    {
      if (now[i] == '.' || now[i+1] == '.')
        continue;
      string x = now;
      x[kara] = now[i];
      x[kara + 1] = now[i + 1];
      x[i] = '.';
      x[i + 1] = '.';
      if (!dist.count(x))
      {
        dist[x] = dist[now] + 1;
        que.push(x);
      }
    }
  }
  if (dist.count(t))
  {
    cout << dist[t] << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
