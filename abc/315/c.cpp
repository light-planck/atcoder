#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector satisfactions(N, vector<ll>());
  rep(i, N) {
    ll f, s;
    cin >> f >> s;
    --f;
    satisfactions[f].emplace_back(s);
  }

  // フレーバーごとに満足度をソート
  for (auto& s : satisfactions) {
    sort(s.rbegin(), s.rend());
  }

  ll ans = 0;

  // 異なるフレーバーで満足感が大きいものを2つ求める
  vector<ll> candidates;
  for (auto s : satisfactions) {
    if (s.empty()) continue;
    candidates.emplace_back(s[0]);
  }
  sort(candidates.rbegin(), candidates.rend());
  if (candidates.size() >= 2) ans = max(ans, candidates[0] + candidates[1]);

  // 同じフレーバーの組み合わせで満足感の最大値を計算
  for (auto s : satisfactions) {
    if (s.size() < 2) continue;
    ans = max(ans, s[0] + s[1] / 2);
  }

  cout << ans << '\n';
}
