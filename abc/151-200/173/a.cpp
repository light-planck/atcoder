#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  if (n % 1000 == 0) cout << 0 << endl;
  else cout << 1000 - n % 1000 << endl;
}