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
  int cnt = 0;
  // ab + c = n
  // c >= 1 より c = n - ab >= 1
  // ab <= n-1
  // 1 <= a <= n-1, b = (int)(n-1)/a
  for (int a = 1; a <= n - 1; a++) {
    cnt += (n-1)/a;
  }
  cout << cnt << endl;
  return 0;
}