#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using ll = long long;

// ---- モノイド：交代和 + 既知数 ----
struct Node
{
  ll s;    // 区間の交代和
  int len; // 区間内の既知な V の本数
};
Node op(Node L, Node R)
{
  // 左の既知本数が奇数なら右の符号を反転して連結
  ll rs = L.s + ((L.len & 1) ? -R.s : R.s);
  return {rs, L.len + R.len};
}
Node e() { return {0LL, 0}; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  int Q;
  cin >> Q;

  // V は N-1 本（V_i = A_i + A_{i+1}）
  atcoder::segtree<Node, op, e> seg(max(0, N - 1));

  while (Q--)
  {
    int T;
    int X, Y;
    long long V;
    cin >> T >> X >> Y >> V;

    if (T == 0)
    {
      // 情報: A_X + A_{Y} = V, ただし Y = X+1 が保証される
      // → V_X が判明
      int idx = X - 1; // V_X は 0-indexed で idx
      if (0 <= idx && idx < N - 1)
      {
        seg.set(idx, Node{V, 1}); // 既知化（上書きOK）
      }
    }
    else
    {
      // 質問: A_X = V と仮定したとき A_Y は？
      if (X == Y)
      {
        cout << V << '\n';
        continue;
      }
      int L = min(X, Y), R = max(X, Y); // 使う V は [L, R)
      if (!(1 <= L && R <= N))
      { // 念のため防御
        cout << "Ambiguous\n";
        continue;
      }
      Node got = seg.prod(L - 1, R - 1); // V_{L..R-1}
      int dist = R - L;                  // V の本数＝距離

      if (got.len != dist)
      {
        cout << "Ambiguous\n";
        continue;
      }
      ll alt = got.s;
      ll ans;
      if (dist & 1)
      {
        // 距離奇数：向きに依らず A_far = alt - A_near
        ans = alt - V;
      }
      else
      {
        // 距離偶数：向きで符号が変わる
        if (X < Y)
          ans = V - alt; // 順方向
        else
          ans = V + alt; // 逆方向
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
