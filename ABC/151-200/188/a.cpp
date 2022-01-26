#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int x, y;
  cin >> x >> y;
  bool can = min(x, y) + 3 > max(x, y);
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}