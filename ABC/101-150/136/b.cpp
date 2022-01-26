#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    if (s.size() % 2 == 1) cnt++;
  }
  cout << cnt << endl;
  return 0;
}