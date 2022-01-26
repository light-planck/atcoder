#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  set<vector<int>> st;
  rep(i, n) {
    int l;
    cin >> l;
    vector<int> v(l);
    rep(j, l) {
      cin >> v[j];
    }
    st.insert(v);
  }
  cout << st.size() << endl;
  return 0;
}