#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  int k = (a+b)/2;
  if (abs(a-k) == abs(b-k)) cout << k << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}