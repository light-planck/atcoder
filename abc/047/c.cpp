#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll cnt = 0;
  string t = "";
  char prev = '.';

  for (auto c : s) {
    if (c == prev) ++cnt;
    else {
      if (prev != '.') t += prev;
      prev = c;
      cnt = 0;
    }
  }
  t += prev;

  cout << t.size()-1 << '\n';
  return 0;
}