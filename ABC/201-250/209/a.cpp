#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
	int a, b;
  cin >> a >> b;
  int cnt = 0;

  for (int i = a; i < b + 1; i++){
    cnt++;
  }

  cout << cnt << endl;
}