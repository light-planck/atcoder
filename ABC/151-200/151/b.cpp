#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int sum = 0;
  rep(i, n-1) {
    int a;
    cin >> a;
    sum += a;
  }
  int ans = m * n - sum;
  if (ans <= k) cout << max(0, ans) << endl;
  else cout << -1 << endl;
  return 0;
}