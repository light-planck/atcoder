#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  string t;
  cin >> t;

  auto is_similiar = [&](char c, char d) {
    if (c == d)
      return true;
    if (c == '1' and d == 'l')
      return true;
    if (c == 'l' and d == '1')
      return true;
    if (c == '0' and d == 'o')
      return true;
    if (c == 'o' and d == '0')
      return true;
    return false;
  };

  rep(i, n) {
    if (not is_similiar(s[i], t[i])) {
      cout << "No" << '\n';
      exit(0);
    }
  }

  cout << "Yes" << '\n';
  return 0;
}
