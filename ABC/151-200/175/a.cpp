#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  bool a = s[0] == 'R';
  bool b = s[1] == 'R';
  bool c = s[2] == 'R';
  if (a and b and c) cout << 3 << endl;
  else if (a and b or b and c) cout << 2 << endl;
  else if (a or b or c) cout << 1 << endl;
  else cout << 0 << endl;
}