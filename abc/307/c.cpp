#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

void print() { cout << '\n'; }
template <class T> void print(const T &value) { cout << value << '\n'; }
template <class T, class... A> void print(const T &first, const A &...tail) {
  cout << first << " ";
  print(tail...);
}
template <class... A> void print(const A &...tail) { print(tail...); }
template <class T> void print(vector<T> &vec) {
  for (const auto &a : vec) {
    cout << a << " ";
  }
  print();
}
template <class T> void print(vector<vector<T>> &vec2d) {
  for (auto &vec : vec2d) {
    print(vec);
  }
}
void print(vector<string> &grid) {
  for (const auto &row : grid)
    print(row);
}
template <class T, class U> void print(const map<T, U> &mp) {
  for (const auto &[x, y] : mp) {
    print(x, y);
  }
}
template <class T> void print(set<T> &st) {
  for (const auto &a : st) {
    cout << a << " ";
  }
  print();
}
void print(vector<pair<ll, ll>> &vp) {
  for (auto [x, y] : vp)
    print(x, y);
}

int main() {
  ll ha, wa;
  cin >> ha >> wa;

  vector<string> a(ha);
  rep(i, ha) cin >> a[i];

  ll hb, wb;
  cin >> hb >> wb;

  vector<string> b(hb);
  rep(i, hb) cin >> b[i];

  ll hx, wx;
  cin >> hx >> wx;

  vector<string> x(hx);
  rep(i, hx) cin >> x[i];

  ll hx2 = hx + 20;
  ll wx2 = wx + 20;
  vector<string> y(hx2, string(wx2, '.'));
  rep(ai0, hx2) {
    rep(aj0, wx2) {
      auto prev_a = y;

      for (ll ai = 0; ai < ha; ++ai) {
        for (ll aj = 0; aj < wa; ++aj) {
          if (ai0 + ai >= hx2 or aj0 + aj >= wx2)
            continue;
          if (a[ai][aj] == '#')
            y[ai0 + ai][aj0 + aj] = '#';
        }
      }

      rep(bi0, hx2) {
        rep(bj0, wx2) {
          auto prev_b = y;

          for (ll bi = 0; bi < hb; ++bi) {
            for (ll bj = 0; bj < wb; ++bj) {
              if (bi0 + bi >= hx2 or bj0 + bj >= wx2) {
                continue;
              }
              if (b[bi][bj] == '#') {
                y[bi0 + bi][bj0 + bj] = '#';
              }
            }
          }

          rep(yi0, hx2) {
            rep(yj0, wx2) {
              if (yi0+hx >= hx2 or yj0+wx >= wx2) continue;

              bool ok = true;
              for (ll yi = 0; yi < hx; ++yi) {
                for (ll yj = 0; yj < wx; ++yj) {
                  if (x[yi][yj]!=y[yi0+yi][yj0+yj]) ok = false;
                }
              }

              if (ok) {
                cout << "Yes" << '\n';
                exit(0);
              }
            }
          }

          y = prev_b;
        }
      }

      y = prev_a;
    }
  }

  cout << "No" << '\n';
  return 0;
}
