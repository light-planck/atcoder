#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  for (auto& c : s) {
    if (c == 'o') {
      if (k <= 0) c = 'x';
      else --k;
    }
  }

  cout << s << '\n';
  return 0;
}