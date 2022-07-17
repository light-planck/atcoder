#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int sumnum(int x){
  int sum = 0;

  while(x > 0){
    sum += x % 10;
    x /= 10;
  }

  return sum;
}

int main() {
	int n ,a ,b;
  cin >> n >> a >> b;
  int ans = 0;

  for (int i = 1; i <= n; i++){
    if(sumnum(i) >= a && sumnum(i) <= b) ans += i;
  }

  cout << ans << endl;
}