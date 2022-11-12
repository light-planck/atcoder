#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  for (ll step = 1; step <= 10; ++step) {
    for (ll n = 4; n <= 100; ++n) {
      if (n*(n-1) >= 2*step*99) {
        cout << "step: " << step << " n: " << n << '\n';
        break;
      }
    }
  }
  return 0;
}