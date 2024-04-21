use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        (n, q): (usize, usize),
        t: [i64; q],
    }

    let mut teeth = vec![true; n];

    for i in t {
        teeth[(i - 1) as usize] = !teeth[(i - 1) as usize];
    }

    let ans = teeth.into_iter().filter(|&i| i).count();
    println!("{}", ans);
}
