#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> tp(n);
  
  rep(i, n) {
    string s;
    int v;
    cin >> s >> v;
    v *= -1;
    tp[i] = make_tuple(s, v, i + 1);
  }

  sort(all(tp));

  for (auto x : tp) {
    cout << get<2>(x) << endl;
  }
  return 0;
}