#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  while (n % 10 == 0){
    n /= 10;
  }

  string s = to_string(n);
  string res = to_string(n);
  reverse(res.begin(), res.end());

  if(s == res) cout << "Yes" << endl;
  else cout << "No" << endl;
}