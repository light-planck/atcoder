#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  rep(i, n) {
    int h;
    cin >> h;
    if (h >= k) cnt++;
  }
  cout << cnt << endl;
  return 0;
}