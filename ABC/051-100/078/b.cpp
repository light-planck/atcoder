#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
	int a, b, c, x;
  cin >> a >> b >> c >> x;
  int cnt = 0;

  for (int i = 0; i < a + 1; i++){
    for (int j = 0; j < b + 1; j++){
      for (int k = 0; k < c + 1; k++){
        if(x == 500 * i + 100 * j + 50 * k) cnt++;
      }
    }
  }

  cout << cnt << endl;
}