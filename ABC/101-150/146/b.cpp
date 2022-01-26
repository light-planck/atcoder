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
  rep(i, s.size()) {
    int x = (s[i] - 'A' + n) % 26;
    s[i] = 'A' + x;
  }
  cout << s << endl;
  return 0;
}