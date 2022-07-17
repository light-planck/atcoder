ll compute_score() {
  ll score = 0;

  for (ll d = 0; d < D; ++d) {
    ll type = t[d];
    score += s[d][type];

    last[type] = d;
    for (ll i = 0; i < TYPE; ++i) {
      score -= c[i] * (d - last[i]);
    }

    cout << score << "\n";
  }

  return score;
}