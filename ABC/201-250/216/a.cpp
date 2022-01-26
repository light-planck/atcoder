#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int y = s[n-1] - '0';
  s = s.substr(0, n-2);
  if (y <= 2) s += "-";
  else if (y >= 7) s += "+";
  cout << s << endl;
  return 0;
}