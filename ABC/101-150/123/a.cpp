#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  vector<int> a(5);
  rep(i, 5) cin >> a[i];
  int k;
  cin >> k;
  bool can = true;
  for (int i = 0; i < 4; i++) {
    for (int j = i+1; j < 5; j++) {
      if (abs(a[i] - a[j]) > k) can = false;
    }
  }
  puts(can ? "Yay!" : ":(");
  return 0;
}