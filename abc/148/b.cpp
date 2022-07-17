#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string ans = "";
  rep(i, n) {
    ans += s[i];
    ans += t[i];
  }
  cout << ans << endl;
  return 0;
}