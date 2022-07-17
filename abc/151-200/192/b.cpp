#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  bool ans = true;

  for (int i = 0; i < s.size(); i++){
    //奇数のとき小文字
    if (i % 2 == 0 && isupper(s[i])){
      ans = false;
      break;
    }

    //偶数のとき大文字
    else if (i % 2 == 1 && islower(s[i])){
      ans = false;
      break;
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}