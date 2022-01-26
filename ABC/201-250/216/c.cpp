#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  ll n;
  cin >> n;
  string ans;
  while (n > 0) {
    if (n % 2 == 0) {
      n /= 2;
      ans += "B";
    }
    else {
      n--;
      ans += "A";
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}