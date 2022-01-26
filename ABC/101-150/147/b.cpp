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
  int cnt = 0;
  rep(i, n / 2) {
    if (s[i] != s[n - 1 - i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}