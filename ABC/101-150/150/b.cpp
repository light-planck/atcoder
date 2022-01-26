#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, n - 2) {
    if(s.substr(i, 3) == "ABC") cnt++;
  }
  cout << cnt << endl;
  return 0;
}