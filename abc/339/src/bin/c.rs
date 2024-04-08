use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        a: [i64; n],
    }

    let mut initial_value = 0 as i64;
    let mut now = 0;
    for a in &a {
        if now + a < 0 {
            initial_value = initial_value.max(-(now + a));
            now = 0;
        } else {
            now += a;
        }
    }

    let ans = a.into_iter().sum::<i64>() + initial_value;
    println!("{}", ans);
}
