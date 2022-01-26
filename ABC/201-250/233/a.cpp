#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;
  int ans = y - x;
  ans = (ans + 10 - 1) / 10;
  cout << max(ans, 0) << "\n";
  return 0;
}