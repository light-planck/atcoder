#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  ll prev = 10;
  for (auto c : s) {
    if (c - '0' >= prev) {
      cout << "No" << '\n';
      exit(0);
    }

    prev = c - '0';
  }

  cout << "Yes" << '\n';
}
