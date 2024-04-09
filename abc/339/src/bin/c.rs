use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        a: [i64; n],
    }

    let mut now = 0;
    for a in &a {
        if now + a < 0 {
            now = 0;
        } else {
            now += a;
        }
    }

    println!("{}", now);
}
