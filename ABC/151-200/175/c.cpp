#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// xが負であっても正であるとしても一般性を失わない。
// 原点をまたぐような移動をするときとその前に移動回数がk回に達する場合がある。
// またぐ場合はまたぐ直前の座標まで移動し、残りの移動回数分+d, -dの移動をする。
// kが偶数のとき、-d, +dとなるので、答えはまたぐ直前の座標x'で、奇数のときはabs(x' - d)となる。

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);
  ll ans;
  if (x / d >= k) ans = x - k * d;
  else {
    ll step = x / d;
    k -= step;
    x -= step * d;
    if (k % 2 == 0) ans = x;
    else ans = abs(x - d);
  }
  cout << ans << endl;
  return 0;
}