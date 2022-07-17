#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// double d = 2.51;
// ll a = d * 100;とするとa = 250と出力される。
// d * 100 = 250.999となるため
// そこで、もっとも近い整数に丸めるために0.5を加える

int main() {
  ll a;
  cin >> a;
  double b;
  cin >> b;
  ll c = b * 100 + 0.5;
  ll ans = a * c / 100;
  cout << ans << endl;
  return 0;
}