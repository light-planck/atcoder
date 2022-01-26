#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
	int n, x;
  cin >> n >> x;
  
  vector<int> a(n);
  int sum = 0;

  for (int i = 0; i < n; i++){
    cin >> a.at(i);
  }

  rep(i, n){
    cout << a.at(i) << endl;
  }

  for (int i = 0; i < a.size(); i++){
    if(i % 2 == 1) a.at(i) -= 1;
  }

  for (int i = 0; i < a.size(); i++){
    sum += a.at(i);
  }

  cout << sum << endl;
  if(x >= sum) cout << "Yes" << endl;
  else cout << "No" << endl;
}