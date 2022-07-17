#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  vector<int> t(5);
  vector<int> dt(5);

  // 10の倍数の時刻になるのに最も時間がかかる調理時間
  int mx = 0;
  rep(i, 5) {
    cin >> t[i];
    if (t[i] % 10 == 0) dt[i] = 0;
    else {
      dt[i] = 10 - t[i] % 10;
      if (mx < dt[i]) mx = dt[i];
    }
  }

  // mxの値は1つ
  bool flag = true;

  int sum = 0;
  rep(i, 5) {
    if (dt[i] == 0) sum += t[i];
    else if (dt[i] == mx && flag) {
      sum += t[i];
      flag = false;
    }
    else sum += t[i] + dt[i];
  }

  cout << sum << endl;
  return 0;
}