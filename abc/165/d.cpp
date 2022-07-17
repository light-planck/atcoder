#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// ex1について
// x=0から順に答えを出力すると、
// 0 0 1 2 2 3 4, 0 0 1 2 2 3 4, 0 0 ...
// と周期がb = 7となっている。
// 最大値は周期の最後、x = b - 1で最大値を取るがnがb - 1より
// 小さいときはnで取る。

int main() {
  ll a, b, n;
  cin >> a >> b >> n;
  ll x = min(b - 1, n);
  ll ans = a * x / b - a * (x / b);
  cout << ans << endl;
  return 0;
}