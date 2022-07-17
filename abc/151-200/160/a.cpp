#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  if (s[2] == s[3] and s[4] == s[5]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}