#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  while (N % 2 == 0) {
    N /= 2;
  }
  while (N % 3 == 0) {
    N /= 3;
  }

  if (N == 1)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
}
