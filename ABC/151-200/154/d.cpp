#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

double ev(int x) {
  double res;
  res = x * (x + 1) / 2;
  res /= x;
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  double sum = 0;
  rep(i, k) sum += ev(p[i]);
  double ans = sum;
  for (int i = 1; i <= n - k; i++) {
    sum -= ev(p[i - 1]);
    sum += ev(p[i + k - 1]);
    ans = max(ans, sum);
  }
  printf("%.7f\n", ans);
  return 0;
}