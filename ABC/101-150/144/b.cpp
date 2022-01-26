#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  bool can = false;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (n == i * j) can = true;
    }
  }
  puts(can ? "Yes" : "No");
  return 0;
}