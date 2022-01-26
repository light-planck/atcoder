#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

bool issq(double x) {
  for (int i = 1; i * i <= x; i++) {
    if (i * i == x) return true;
  }
  return false;
}

int main() {
  int n, d;
  cin >> n >> d;
  int x[n][d];
  rep(i, n)rep(j, d) cin >> x[i][j];
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      double dis = 0;
      rep(k ,d) {
        dis += abs((x[i][k] - x[j][k]) * (x[i][k] - x[j][k]));
      }
      if (issq(dis)) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}