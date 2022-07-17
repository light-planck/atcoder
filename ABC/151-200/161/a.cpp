#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  swap(x, y);
  swap(x, z);
  cout << x << " " << y << " " << z << endl;
  return 0;
}