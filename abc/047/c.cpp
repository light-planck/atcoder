#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string t = "";
  char prev = '\0';

  for (auto c : s) {
    if (c != prev) {
      if (prev != '\0') t += prev;
      prev = c;
    }
  }
  t += prev;

  cout << t.size()-1 << '\n';
  return 0;
}