#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<string> S(N);
  for (auto& s : S) cin >> s;

  vector<string> left_up = {"###.", "###.", "###.", "...."};
  vector<string> right_down = {"....", ".###", ".###", ".###"};

  auto is_TAK = [&](ll i, ll j) {
    if (i + 8 >= N or j + 8 >= M) return false;

    bool ok = true;

    // 左上
    rep(di, 4) {
      if (S[i + di].substr(j, 4) != left_up[di]) {
        ok = false;
      }
    }

    // 右下
    rep(di, 4) {
      if (S[i + 5 + di].substr(j + 5, 4) != right_down[di]) {
        ok = false;
      }
    }

    return ok;
  };

  rep(i, N) {
    rep(j, M) {
      if (is_TAK(i, j)) {
        cout << i + 1 << " " << j + 1 << '\n';
      }
    }
  }
}
