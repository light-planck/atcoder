#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int h, a;
  cin >> h >> a;
  int cnt = 0;
  while (h > 0) {
    h -= a;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}