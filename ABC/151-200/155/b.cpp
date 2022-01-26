#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  bool can = true;
  rep(i, n){
    int a;
    cin >> a;
    if (a % 2 == 0) {
      if (a % 3 != 0 and a % 5 != 0) can = false;
    }
  }
  puts(can ? "APPROVED" : "DENIED");
  return 0;
}