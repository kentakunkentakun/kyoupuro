#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<vector<int>> g(N);

  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // dist[s][v] = s から v までの距離
  vector<vector<int>> dist(N, vector<int>(N, -1));

  for (int s = 0; s < N; s++)
  {
    queue<int> q;
    dist[s][s] = 0;
    q.push(s);

    while (!q.empty())
    {
      int v = q.front();
      q.pop();

      for (int to : g[v])
      {
        if (dist[s][to] != -1)
          continue;
        dist[s][to] = dist[s][v] + 1;
        q.push(to);
      }
    }
  }

  long long ans = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        int dij = dist[i][j];
        int dik = dist[i][k];
        int djk = dist[j][k];

        // 3点が1本の単純パス上にあるか？
        bool on_one_path = false;

        // j が i-k パス上にある
        if (dij + djk == dik)
          on_one_path = true;

        // i が j-k パス上にある
        if (dij + dik == djk)
          on_one_path = true;

        // k が i-j パス上にある
        if (dik + djk == dij)
          on_one_path = true;

        // 問題は「3点すべてを含む単純パスが存在しない」ものを数える
        if (!on_one_path)
          ans++;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
