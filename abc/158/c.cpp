#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  // 1<= a, b <= 100なので、税抜価格xは 10 <= x <= 10000
  // 10-10000まで全探索し、条件を満たす値を出力

  int a, b;
  cin >> a >> b;
  for (int i = 10; i <= 10000; i++) {
    int x = i * 0.08;
    int y = i * 0.1;
    if (x == a && y == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}