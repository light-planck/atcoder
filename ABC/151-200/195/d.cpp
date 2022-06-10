#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;

  vector<pair<int, int>> items(n);
  rep(i, n) cin >> items[i].second >> items[i].first;

  // valueの降順でソート
  sort(items.rbegin(), items.rend());

  vector<int> x(m);
  rep(i, m) cin >> x[i];

  // xの昇順でソートしたいが、ここでするとl, rの位置関係がわからなくなる
  // sort(all(x));

  // クエリ
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l; --r;

    int sum_v = 0;

    // 使える箱の容量
    vector<int> box_cap;
    for (int i = 0; i < m; ++i) {
      if (i < l || i > r) {
        box_cap.push_back(x[i]);
      }
    }
    sort(all(box_cap));

    // 使った箱
    vector<bool> seen(box_cap.size());
    for (int i = 0; i < n; ++i) {
      int w = items[i].second;
      int v = items[i].first;

      for (int j = 0; j < box_cap.size(); ++j) {
        if (seen[j]) continue;

        if (box_cap[j] >= w) {
          sum_v += v;
          seen[j] = true;
          break;
        }
      }
    }

    cout << sum_v << "\n";
  }
  return 0;
}