#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double ans = (x1 * y2 + x2 * y1) / (y1 + y2);
  printf("%.6f\n", ans);
}