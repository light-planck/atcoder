#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> ans;
  for (int i = 1; i <= max(a, b); i++) {
    if (a % i == 0 && b % i == 0) ans.push_back(i);
  }
  int n = ans.size();
  cout << ans[n - k] << endl;
  return 0;
}