#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int k, x;
  cin >> k >> x;
  for (int i = x-(k-1); i <= x+(k-1); i++) {
    cout << i;
    if (i < x+(k-1)) cout << " ";
    else cout << endl;
  }
  return 0;
}