#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool takalose = false;

  for (int i = 0; i < n; i++){
    if (s.at(i) == '1'){
      if (i % 2 == 0) takalose = true;
      break;
    }
  }  

  if (takalose) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}