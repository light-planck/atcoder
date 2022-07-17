#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int h, n;
  cin >> h >> n;
  rep(i, n) {
    int a;
    cin >> a;
    h -=a;
  }
  if (h <= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}