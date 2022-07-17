#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  ll n2 = 2 * n;

  vector<vector<ll>> a(n2, vector<ll>(n2));
  for (ll i = 0; i < n2 - 1; ++i) {
    for (ll j = i + 1; j < n2; ++j) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }

  ll max_xor = 0;

  auto dfs = [&](auto dfs, vector<bool> seen, ll curr_xor) -> void {
    // 二人組のうちの一人をまだ選んでいない人で、番号が最小の人を選ぶ
    // pair: (min_idx, i)
    ll min_idx = -1;

    for (ll i = 0; i < n2; ++i) {
      // 既に選んでいる場合スキップ
      if (seen[i]) continue;

      min_idx = i;
      seen[min_idx] = 1;
      break;
    }

    // すべての人を選んだ場合、答えを更新
    if (min_idx == -1) {
      chmax(max_xor, curr_xor);
      return;
    }

    // min_idxとペアになる人を全探索
    for (ll i = 0; i < n2; ++i) {
      // 既に選んでいる場合スキップ
      if (seen[i]) continue;

      seen[i] = true;
      dfs(dfs, seen, curr_xor ^ a[min_idx][i]);

      // next_iに対してseenの情報を渡すためseen[prev_i] = false
      seen[i] = false;
    }
  };

  vector<bool> s(n2);
  dfs(dfs, s, 0);

  cout << max_xor << "\n";
  return 0;
}