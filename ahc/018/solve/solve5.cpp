// 掘削を終えるごとに、家から水源までの距離を求め、小さいものから掘削
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct Pos {
  ll y, x;
  Pos(ll y=0, ll x=0) : y(y), x(x) {}
};


ll n, w, k, c;
vector<Pos> water;
vector<Pos> house;


ll power = 100;
ll total_cost = 0;
vector<vector<bool>> broken;


void init_c() {
  if (c <= 8) power = 50;
  else if (c <= 64) power = 100;
  else power = 200;
}


void init() {
  cin >> n >> w >> k >> c;
  broken = vector(n, vector<bool>(n, false));
  init_c();
  rep(_, w) {
    ll a, b;
    cin >> a >> b;
    water.emplace_back(a, b);
  }
  rep(_, k) {
    ll a, b;
    cin >> a >> b;
    house.emplace_back(a, b);
  }
}


void respond(ll y, ll x) {
  total_cost += power + c;
  cout << y << " " << x << " " << power << endl;
  ll r;
  cin >> r;
  if (r == -1) {
    cerr << "invalid: y=" << y << " x=" << x << endl;
    exit(1);
  }
  if (r == 2) {
    broken[y][x] = true;
    // cerr << "C = " << c << endl;
    // cerr << c << endl;
    exit(0);
  }
  if (r == 1) {
    broken[y][x] = true;
  }
}


void destruct(ll y, ll x) {
  while (not broken[y][x]) {
    respond(y, x);
  }
}


void move(Pos start, Pos goal) {
  cout << "# move from (" << start.y << "," << start.x << ") to (" << goal.y << "," << goal.x << ")" << endl;

  // down/up
  if (start.y < goal.y) {
    for (int y = start.y; y < goal.y; y++) {
      destruct(y, start.x);
    }
  } else {
    for (int y = start.y; y > goal.y; y--) {
      destruct(y, start.x);
    }
  }

  // right/left
  if (start.x < goal.x) {
    for (int x = start.x; x <= goal.x; x++) {
      destruct(goal.y, x);
    }
  } else {
    for (int x = start.x; x >= goal.x; x--) {
      destruct(goal.y, x);
    }
  }
}


bool check_yx(ll y, ll x) {
  if (y<0 or y>=n) return false;
  if (x<0 or x>=n) return false;
  return true;
}


void solve() {
  vector<ll> near_water(k);  // 家とのマンハッタン距離が最小をとる水源のidx
  vector<ll> dist_to_water(k);  // 家から水源までのマンハッタン距離の最小値

  // 各家から各水源までの最小のマンハッタン距離を求める
  rep(i, k) {
    ll dist = 1ll << 60;
    ll water_idx = 0;
    rep(j, w) {
      ll d = abs(house[i].y - water[j].y) + abs(house[i].x - water[j].x);
      if (d < dist) {
        dist = d;
        water_idx = j;
      }
    }
    near_water[i] = water_idx;
    dist_to_water[i] = dist;
  }

  // 家i(y, x)からマンハッタン距離がdist以下で最短の水源・水路(ny, nx)を探索
  auto search_water = [&](ll i) -> pair<Pos, ll> {
    Pos to = {water[near_water[i]].y, water[near_water[i]].x};
    ll dist = dist_to_water[i];
    // (y, x)からd以下のマンハッタン距離の点(ny, nx)に水路があるか確認
    for (ll dy = -dist; dy <= dist; ++dy) {
      for (ll dx = -dist; dx <= dist; ++dx) {
        auto [y, x] = house[i];
        ll ny = y+dy; ll nx = x+dx;

        if (abs(dy)+abs(dx) > dist) continue;
        if (not check_yx(ny, nx)) continue;
        if (not broken[ny][nx]) continue;

        if (abs(dy)+abs(dx) < dist) {
          dist = abs(dy) + abs(dx);
          to = {ny, nx};
        }
      }
    }
    return {to, dist};
  };

  set<ll> rem_house;
  rep(i, k) rem_house.emplace(i);

  auto get_house_to_water = [&]() -> pair<ll, Pos> {
    vector<pair<ll, ll>> dist_from;
    vector<Pos> from_to(k);
    rep(i, k) {
      if (not rem_house.count(i)) continue;
      auto [to, dist] = search_water(i);
      dist_from.emplace_back(dist, i);
      from_to[i] = to;
    }
    sort(dist_from.begin(), dist_from.end());
    auto [_, i] = dist_from[0];
    Pos to = from_to[i];
    return {i, to};
  };

  while (not rem_house.empty()) {
    auto [i, to] = get_house_to_water();
    move(house[i], to);
    rem_house.erase(i);
  }
}


int main() {
  init();
  solve();
  return 0;
}