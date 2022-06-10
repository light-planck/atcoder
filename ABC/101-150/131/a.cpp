#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  bool ans = true;
  rep(i, 3) {
    if (s[i] == s[i+1]) ans = false;
  }
  puts(ans ? "Good" : "Bad");
  return 0;
}