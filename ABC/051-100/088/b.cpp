#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n){
    cin >> a.at(i);
  }

  sort(a.rbegin(), a.rend());

  vector<int> al;
  vector<int> bo;

  for (int i = 0; i < n; i++){
    if(i % 2 == 0){
      al.push_back(a.at(i));
    }
    else bo.push_back(a.at(i));
  }

  int sumal = 0;
  int sumbo = 0;

  rep(i, al.size()){
    sumal += al.at(i);
  }

  rep(i, bo.size()){
    sumbo += bo.at(i);
  }

  cout << sumal - sumbo << endl;
}