#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  map<char, ll> cnt;
  for (auto c : s) ++cnt[c];

  for (auto [c, x] : cnt) {
    if (x%2 == 1) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}