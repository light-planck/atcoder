#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  int cnt = 0;
  rep(i, 3) {
    if (t[i] == s[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}