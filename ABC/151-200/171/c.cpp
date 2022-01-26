#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  ll n;
  cin >> n;
  string ans;
  while (n > 0) {
    n--;
    char r = n % 26;
    ans = (char)('a' + r) + ans;
    n /= 26;
  }
  cout << ans << endl;
  return 0;
}