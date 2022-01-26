#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  rep(i, 2) {
    if (a > b) {
    ans += a;
    a--;
    }
  else {
    ans += b;
    b--;
    }
  }
  cout << ans << endl;
  return 0;
}