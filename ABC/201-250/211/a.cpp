#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;

  bool flag = (a - b) % 3 == 0;
  if (flag) cout << (a - b) / 3 + b << endl;
  else cout << (double)(a - b) / 3 + b << endl;
}