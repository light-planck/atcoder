use im_rc::HashMap;
use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        n: usize,
        s: [Chars; n],
    }

    let row_cnt: HashMap<usize, i64> = s
        .iter()
        .enumerate()
        .map(|(i, row)| (i, row.iter().filter(|&c| *c == 'o').count() as i64))
        .collect();
    let col_cnt: HashMap<usize, i64> = (0..n)
        .map(|j| (j, (0..n).filter(|&i| s[i][j] == 'o').count() as i64))
        .collect();

    let mut ans = 0;
    for i in 0..n {
        for j in 0..n {
            if s[i][j] == 'x' {
                continue;
            }

            ans += (row_cnt[&i] - 1) * (col_cnt[&j] - 1);
        }
    }

    println!("{}", ans);
}
