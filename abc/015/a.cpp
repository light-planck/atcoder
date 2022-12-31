#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  vector<string> s(2);
  rep(i, 2) cin >> s[i];

  if (s[0].size() > s[1].size()) {
    cout << s[0] << '\n';
  }
  else cout << s[1] << '\n';
  return 0;
}