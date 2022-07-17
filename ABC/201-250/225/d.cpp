#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const int nil = -1;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<int> front(n, nil);
  vector<int> back(n, nil);

  rep(i, q) {
    int t;
    cin >> t;

    if (t != 3) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      
      if (t == 1) {
        back[x] = y;
        front[y] = x;
      }

      else if (t == 2) {
        back[x] = nil;
        front[y] = nil;
      }
    }

    else {
      int x;
      cin >> x;
      x--;
      
      while (front[x] != nil) {
        x = front[x];
      }

      vector<int> ans;
      while (x != nil) {
        ans.push_back(x + 1);
        x = back[x];
      }

      cout << ans.size() << " ";
      for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
      }
      cout << "\n";
    }
  }
  return 0;
}