#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  ll n;
  cin >> n;
  int k = 0;
  ll sum = 1;
  while (sum <= n) {
    sum *= 2;
    k++;
  }
  cout << k-1 << endl;
  return 0;
}