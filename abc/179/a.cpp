#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  if (s[s.size() - 1] == 's') s += "es";
  else s += "s";
  cout << s << endl;
}