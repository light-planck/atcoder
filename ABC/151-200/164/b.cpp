#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool win = true;
  while (a > 0 and c > 0){
    c -= b;
    if (c <= 0){
      win = true;
      break;
    }
    a -= d;
    if (a <= 0){
      win = false;
      break;
    }
  }
  if (win) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}