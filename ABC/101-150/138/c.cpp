#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  rep(i, n) cin >> v[i];
  sort(all(v));
  double tmp = 0;
  for (int i = 0; i < n; i++) {
    if (tmp == 0) {
      tmp = v[0];
      continue;
    }
    tmp = (tmp + v[i]) / 2;
  }
  printf("%.6f\n", tmp);
  return 0;
}