#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  char tmp;
  rep(i, n) {
    char c;
    cin >> c;
    if (c != tmp) {
      ans++;
      tmp = c;
    }
  }
  cout << ans << endl;
  return 0;
}