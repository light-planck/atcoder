#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  string con[] = {"ABC", "ARC", "AGC", "AHC"};
  string s, t, u;
  cin >> s >> t >> u;
  int idx = 0;
  rep(i, 4) {
    if (con[i] == s or con[i] == t or con[i] == u) {
      continue;
    }
    else idx = i;
  }
  cout << con[idx] << endl;
  return 0;
}