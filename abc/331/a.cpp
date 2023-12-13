#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll M, D;
  cin >> M >> D;

  ll y, m, d;
  cin >> y >> m >> d;

  if (d + 1 > D) {
    if (m + 1 > M) {
      cout << y + 1 << " " << 1 << " " << 1 << endl;
    } else {
      cout << y << " " << m + 1 << " " << 1 << endl;
    }
  } else {
    cout << y << " " << m << " " << d + 1 << endl;
  }
}
