#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  string s;
  rep(i, max(a, b)) {
    s += to_string(min(a, b));
  }
  cout << s << endl;
  return 0;
}