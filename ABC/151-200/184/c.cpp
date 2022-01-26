#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 超竜馬が(a, b)にいるとき、

// 1. a + b = x + y
// 2. a - b = x - y
// 3. |a - x| + |b - y| <= 3

// を満たす(x, y)に一手で移動できる。
// これは、

// 1. y = -x + a + b
// 2. y = x - a + b
// 3. |x - a| + |y - b| <= 3

// と変形できる。
// 条件1, 2より、(a, b)とパリティが等しい任意の点(x, y)まで最大2手で移動できる。
// このとき、(a + b = x + y (mod 2))を満たす。
// ゆえに、竜馬を(r1, c1)から(r2, c2)まで移動するのに必要な手数は、最大3手である。

// 0手
// (r1, c1) = (r2, c2)

// 1手
// 条件1-3のいずれかを満たす

// 2手
// 条件の(1, 2), (1, 3), (2, 3), (3, 3)

// (1, 3)の場合
// (r1, c1)から条件1を満たすような点は直線l: y = -x + r1 + c1上に存在する。
// そこから、条件3を満たすような点は直線lをy軸方向に+-3移動させて通過した領域に存在する。
// その領域は
// -x + a + b - 3 <= y <= -x + a + b + 3
// である。これを変形すると、
// -3 <= x + y - (r1 + c1) <= 3
// |x + y - (r1 + c1)| <= 3
// となり、これを満たす(x, y)ならば、条件(1, 3)の移動が可能である。
// 同様に、(2, 3)は
// |x - y - (r1 - c1)| <= 3が条件である。

// 3手
// それ以外

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int ans = 3;

  // 0
  if (r1 == r2 && c1 == c2) ans = 0;

  // 1
  else if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3) {
    ans = 1;
  }

  // 2
  else if ((r1 + c1) % 2 == (r2 + c2) %2) ans = 2;
  else if (abs(r2 + c2 - (r1 + c1)) <= 3) ans = 2;
  else if (abs(r2 - c2 - (r1 - c1)) <= 3) ans = 2;
  else if (abs(r1 - r2) + abs(c1 - c2) <= 6) ans = 2;

  cout << ans << "\n";
  return 0;
}