#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int x;
  cin >> x;
  int ans = 0;
  while (x >= 500){
    x -= 500;
    ans += 1000;
  }
  while (x >= 5){
    x -= 5;
    ans += 5;
  }
  cout << ans << endl;
  return 0;
}