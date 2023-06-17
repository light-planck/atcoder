#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int m;
double eps;
int n;


void init() {
  cin >> m >> eps;
  n = 15;
}


template<class T> void print(const T& value) { cout << value << endl; }
void output() {
  print(n);

  rep(i, m) {
    string g = string(i, '1') + string((n*(n-1)/2)-i, '0');
    print(g);
  }

  rep(i, 100) {
    string h;
    cin >> h;
    int cnt = count(h.begin(), h.end(), '1');
    cout << min(cnt, m-1) << '\n';
  }
}


int main() {
  init();
  output();
  return 0;
}