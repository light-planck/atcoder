#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

bool eight(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) cnt++;
  }
  if (cnt == 8) return true;
  else return false;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i = i + 2) {
    if (eight(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}