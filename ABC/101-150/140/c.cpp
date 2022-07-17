#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> b(n-1);
  rep(i, n - 1) cin >> b[i];
  int ans = 0;
  ans += b[0] + b[n-2];
  rep(i, n - 2) {
    ans += min(b[i], b[i+1]);
  }
  cout << ans << endl;
  return 0;
}