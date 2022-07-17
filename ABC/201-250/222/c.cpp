#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int janken(char x, char y) {
  
  // あいこ
  if (x == y) return 0;

  // 前者勝ち
  if (x == 'G' && y == 'C') return -1;
  if (x == 'C' && y == 'P') return -1;
  if (x == 'P' && y == 'G') return -1;

  // 負け
  return 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(2 * n);
  rep(i, 2 * n) cin >> a[i];

  // -勝利数、番号で順位を管理
  // 番号は0 indexed
  vector<pair<int, int>> rank(2 * n);
  rep(i, 2 * n) rank[i].second = i;

  // mラウンド
  for (int i = 0; i < m; i++) {

    // n試合
    for (int k = 1; k <= n; k++) {

      // じゃんけんする2人の番号
      int num1 = rank[2 * k - 2].second;
      int num2 = rank[2 * k - 1].second;

      // 出す手
      char hand1 = a[num1][i];
      char hand2 = a[num2][i];

      // 結果
      int res = janken(hand1, hand2);

      // 勝利数の更新
      if (res == -1) {
        rank[2 * k - 2].first += res;
      }
      if (res == 1) {
        rank[2 * k - 1].first -= res;
      }
    }

    // 順位並び替え
    sort(all(rank));
  }

  for (auto x : rank) cout << x.second + 1 << endl;
  return 0;
}

/*
1ラウンドごとに試合の結果を出し、順位を決定する。mラウンドあり、
各ラウンドごとにn試合あるので、計算量はO(NM)となる。
順位をrank[i] = (勝利数、番号)で管理し、ソートすればよいのだが、
勝利数が多く、番号が小さい順にソートするのはこのままではできない。
そこで、i位の人のデータをrank[i] = (-勝利数、番号)として、昇順にソートすれば題意
を満たせる。
*/