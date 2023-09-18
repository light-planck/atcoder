#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  rep(i, N + 1) {
    bool found = false;

    for (ll j = 1; j <= 9; ++j) {
      if (N % j == 0 and i % (N / j) == 0) {
        cout << j;
        found = true;
        break;
      }
    }

    if (not found) cout << '-';
  }
  cout << '\n';
}
