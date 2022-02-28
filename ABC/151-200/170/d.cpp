#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  const int a_max = 1e6 + 10;
  vector<int> cnt(a_max);

  // 同じ倍数を見ていくのは効率が悪い
  // 倍数の確認をした数
  set<int> st;
  for (int i = 0; i < n; ++i) {
    ++cnt[a[i]];

    // すでにa[i]の倍数を確認していたら
    // スキップ
    if (st.count(a[i])) continue;

    // a[i]の倍数をチェック
    st.insert(a[i]);
    for (int j = 2 * a[i]; j < a_max; j += a[i]) {
      ++cnt[j];
    }
  }

  int ans = 0;
  rep(i, n) {
    if (cnt[a[i]] == 1) ++ans;
  }

  cout << ans << "\n";
  return 0;
}