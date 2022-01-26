#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a == b){
    if (c == 0) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
  }
  else if (a > b) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}