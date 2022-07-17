#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n, y;
  cin >> n >> y;

  int a = -1;
  int b = -1;
  int c = -1;

  bool flag = false;

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n - i; j++){
      if(9 * i + 4 * j == y / 1000 - n){
        a = i;
        b = j;
        c = n - a - b;
        flag = true;
        break;
      }
    }
    if(flag) break;
  }

  cout << a << " " << b << " " << c << endl;
}