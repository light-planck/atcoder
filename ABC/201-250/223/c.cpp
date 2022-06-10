#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  double l = 0;
  vector<pair<double, double>> p(n);
  
  rep(i, n) {
    double a, b;
    cin >> a >> b;
    p[i].first = a; p[i].second = b;
    l += a / b;
  }

  double t = l / 2;
  double ans = 0;

  rep(i, n) {
    double a = p[i].first;
    double b = p[i].second;
    double dt = a / b;

    if (t - dt > 0) {
      ans += dt * b;
      t -= dt;
    }
    else {
      ans += t * b;
      break;
    }
  }

  printf("%.6f\n", ans);
  return 0;
}