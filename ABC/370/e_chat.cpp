#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N + 1), S(N + 1, 0);
  for (int i = 1; i <= N; ++i)
    cin >> A[i], S[i] = S[i - 1] + A[i];

  unordered_map<long long, long long> ban; // ban[x] = Σ dp[j] (S_j = x)
  long long pref = 1;                      // dp[0] のみ
  ban[0] = 1;                              // S0=0 に dp[0]=1 を登録

  long long dpi = 0;
  for (int i = 1; i <= N; ++i)
  {
    long long bad = ban.count(S[i] - K) ? ban[S[i] - K] % MOD : 0;
    dpi = (pref - bad) % MOD;
    if (dpi < 0)
      dpi += MOD;
    pref = (pref + dpi) % MOD;
    ban[S[i]] = ((ban.count(S[i]) ? ban[S[i]] : 0) + dpi) % MOD;
  }
  cout << dpi << '\n';
}
