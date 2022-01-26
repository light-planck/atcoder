#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  //h[i] = max(ch - d, 0)なのでh[i] = 0のとき
  //ch = h[i] + dという情報が使えない
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];
  int ch = 1;

  for (int cx = 0; cx <= 100; cx++) {
    for (int cy = 0; cy <= 100; cy++) {
      rep(i, n) ch = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
      bool ans = true;
      rep(i, n) {
        if (h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
          ans = false;
        }
      }
      if (ans) cout << cx << " " << cy << " " << ch << endl;
    }
  }
  return 0;
}