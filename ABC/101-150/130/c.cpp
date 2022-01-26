#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// (x, y)と長方形の中心を通る直線を引けば、最大値はh * w / 2となる。
// (x, y)が中心であれば、半分に引ける線は無数に引ける。

int main() {
  double w, h, x, y;
  cin >> w >> h >> x >> y;
  double cx = w / 2;
  double cy = h / 2;
  bool yes = false;
  if (cx == x && cy == y) yes = true;
  double ans = w * h / 2;
  printf("%.10f ", ans);
  if (yes) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}