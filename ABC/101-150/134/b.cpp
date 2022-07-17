#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, d;
  cin >> n >> d;
  int num = 1;
  while ((d * 2 + 1) * num < n) {
    num++;
  }
  cout << num << endl;
  return 0;
}