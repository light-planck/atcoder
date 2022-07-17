#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = inf;
  for (int i = 0; i < 1000000; i=i+2) {
    int sum = c * i;
    if (x - i / 2 > 0) sum += a * (x - i / 2);
    if (y - i / 2 > 0) sum += b * (y - i / 2);
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}