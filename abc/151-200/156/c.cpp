#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  ll min = 1e9;
  for (int i = 1; i <= 100; i++) {
    ll sum = 0;
    rep(j, n) {
      sum += (x[j] - i) * (x[j] - i);
    }
    if (sum < min) min = sum;
  }
  cout << min << endl;
  return 0;
}