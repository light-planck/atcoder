#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<double> x(n);
  vector<double> y(n);
  rep(i, n) cin >> x[i] >> y[i];

  double max_len = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double len = (x[i] - x[j]) * (x[i] - x[j]) + ((y[i] - y[j])) * ((y[i] - y[j]));
      len = sqrt(len);
      max_len = max(max_len, len);
    }
  }

  printf("%.7f\n", max_len);
  return 0;
}