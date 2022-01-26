#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if(a * a + b * b < c * c) cout << "Yes" << endl;
  else cout << "No" << endl;
}