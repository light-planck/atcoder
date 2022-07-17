#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
 int k;
 ll n;
 cin >> n >> k;

  for (int i = 0; i < k; i++){
    if(n % 200 == 0) n /= 200;
    else{
      n = n * 1000 + 200;
    }
  }

  cout << n << endl;
}