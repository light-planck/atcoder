#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  bool ans = true;
  int prev_t = 0, prev_x = 0, prev_y = 0;

  rep(i, n) {
    int t, x, y;
    cin >> t >> x >> y;

    // パリティチェック
    // pt - t % 2 = 0 (px + py + x + y) % 2 = 0
    if ((t - prev_t) % 2 != (prev_x + prev_y + x + y) % 2) {
      ans = false;
    }

    // 移動距離チェック
    int d = abs(x - prev_x) + abs(y - prev_y);
    if (d > t - prev_t) ans = false;

    // prevとして記憶
    prev_t = t; prev_x = x; prev_y = y;
  }
  
  if (ans) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}