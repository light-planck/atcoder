#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// [l, r]において調べたいのはmod2019なので[l, min(r, l + 2019)]とすれば
// 区間は約2000の長さに縮小できる。よってi,j全探索できる。
// [1, 2030]においてr = 5と2024はmod2019では本質的に変わらない

int main() {
  int l, r;
  cin >> l >> r;
  r = min(r, l + 2019);
  int ans = 1e9;
  for (int i = l; i < r; i++) {
    for (int j = i + 1; j <= r; j++) {
      int x = i % 2019;
      int y = j % 2019;
      ans = min(ans, x * y % 2019);
    }
  }
  cout << ans << endl;
  return 0;
}