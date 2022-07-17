#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n; cin >> n;
  vector<double> a(n); rep(i, n) cin >> a[i];
  double ans = 0;
  double sum = 0;
  rep(i, n) sum += 1/a[i];
  ans = 1/sum;
  printf("%.6f\n", ans);
  return 0;
}