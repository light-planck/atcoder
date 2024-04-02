use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i64,
        k: i64,
        a: [i64; n],
    }

    for a in &a {
        if a % k == 0 {
            println!("{}", a / k);
        }
    }
}
