#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  rep(i, ssize(S)) {
    if (i % 2 != 1) continue;

    if (S[i] != '0') {
      cout << "No" << '\n';
      exit(0);
    }
  }

  cout << "Yes" << '\n';
}
