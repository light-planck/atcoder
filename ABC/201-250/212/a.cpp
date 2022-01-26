#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;

  if (a > 0 && b == 0) cout << "Gold" << endl;
  else if (a == 0 && b > 0) cout << "Silver" << endl;
  else if (a > 0 && b > 0) cout << "Alloy" << endl;
}