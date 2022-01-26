#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  vector<string> d = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  string s;
  cin >> s;
  int j = 0;
  rep(i, 7) if (s == d[i]) j = i;
  cout << 7 - j << endl;
  return 0;
}