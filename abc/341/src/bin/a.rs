use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: i32,
    }

    let ans = (0..2 * n + 1)
        .map(|i| if i % 2 == 0 { "1" } else { "0" })
        .collect::<String>();
    println!("{}", ans);
}
