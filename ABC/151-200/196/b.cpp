#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;

  cout << s.substr(0, s.find('.')) << endl;
}