#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  bool ans = s[0] == s[1] && s[0] == s[2] && s[1] == s[2];
  if (ans) cout << "Won" << endl;
  else cout << "Lost" << endl;
}