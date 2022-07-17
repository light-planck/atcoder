#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int s, w;
  cin >> s >> w;
  if (w >= s) cout << "unsafe" << endl;
  else cout << "safe" << endl;
  return 0;
}