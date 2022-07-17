#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a;
  
  rep(i, n){
    int b;
    cin >> b;
    if (b != x) a.push_back(b);
  }

  rep(i, a.size()){
    cout << a[i];
    if (i < a.size() - 1) cout << " ";
    else cout << endl;
  }
}