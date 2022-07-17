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
  vector<double> l(n), r(n);
  int cnt = 0;
  rep(i, n) {
    int t;
    cin >> t;
    double a, b;
    cin >> a >> b;
    if (t == 1) {
      l[i] = a;
      r[i] = b;
    }
    if (t == 2) {
      l[i] = a;
      r[i] = b - 0.5;
    }
    if (t == 3) {
      l[i] = a + 0.5;
      r[i] = b;
    }
    if (t == 4) {
      l[i] = a + 0.5;
      r[i] = b - 0.5;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (max(l[i], l[j]) <= min(r[i], r[j])) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}