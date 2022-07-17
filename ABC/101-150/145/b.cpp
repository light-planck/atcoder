#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool ans = true;
  if (n == 1) ans = false;
  string a = s.substr(0, n/2);
  string b = s.substr(n/2);
  if (a != b) ans = false;
  puts(ans ? "Yes" : "No");
  return 0;
}