#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 円なので始点と終点が一致しているから1周するよりも始点を通った方が最短距離となる場合がある。
// 長さkの円周を、二倍にした長さ2kの直線を考える。
// a0からan-1をそれぞれを始点とし、終点までの距離を計算し、最短となるような値を求める。

int main() {
  int k, n;
  cin >> k >> n;

  vector<int> d(2 * n);
  rep(i, n) {
    int a;
    cin >> a;
    d[i] = a;
    d[n + i] = k + a;
  }

  ll mn = 1e9;

  rep(i, n) {
    int len = d[n + i - 1] - d[i];
    if (mn > len) mn = len;
  }

  cout << mn << endl;
  return 0;
}