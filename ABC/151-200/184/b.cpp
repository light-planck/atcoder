#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;

  rep(i, n){
    if (s[i] == 'o') x++;
    else if (x > 0)x--;
  }

  cout << x << endl;
}