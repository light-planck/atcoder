#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s, t;
  cin >> s >> t;
  bool ans = s == t.substr(0, t.size() - 1);
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}