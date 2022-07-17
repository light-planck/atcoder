#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, l;
  cin >> n >> l;
  int sum = n * (2 * l + n - 1) / 2;
  if (l > 0) sum -= l;
  else if (l + n -1 < 0) sum -= l + n - 1;
  cout << sum << endl;
  return 0;
}