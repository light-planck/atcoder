#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  int sum = 1;
  while (sum < b) {
    sum--;
    sum += a;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}