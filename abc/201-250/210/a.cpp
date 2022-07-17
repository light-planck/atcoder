#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  int n, a, x, y;
  cin >> n >> a >> x >> y;
  int ans = 0;

  if (n <= a){
    cout << n * x << endl;
    return 0;
  }

  for (int i = 1; i <= a; i++){
    ans += x;
  }
  for (int i = a+1; i <= n; i++){
    ans += y;
  }

  cout << ans << endl;
}