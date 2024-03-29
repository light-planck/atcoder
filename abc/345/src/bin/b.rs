use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        x: i64,
    }

    let ans = if x >= 0 { (x + 10 - 1) / 10 } else { x / 10 };
    println!("{}", ans);
}
