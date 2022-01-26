#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

ll comb(int n, int r) {
  ll ans = 1;
  for (int i = 0; i < r; i++) {
    ans *= n - i;
    ans /= i + 1;
  }
  return ans;
}

int main() {
  int l;
  cin >> l;
  // l-1_C_11
  cout << comb(l-1, 11) << endl;
  return 0;
}