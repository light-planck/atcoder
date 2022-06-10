#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int a, b;
  cin >> a >> b;
  int pow = a - b;
  int ans = 1;
  rep(i, pow) {
    ans *= 32;
  }
  cout << ans << endl;
  return 0;
}