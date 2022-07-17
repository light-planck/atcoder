#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

double calp(int n, int cnt) {
  double p = 1;
  rep(i, cnt) p *= 1 / n;
  return p;
}

int main() {
  double n, k;
  cin >> n >> k;
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = i;
    double p = 1 / n;
    while (x < k) {
      x *= 2;
      p /= 2;
    }
    ans += p;
  }
  printf("%.10f\n", ans);
  return 0;
}