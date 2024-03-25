use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: usize,
        a: [i32; n],
    }

    let ans = (0..n - 1)
        .map(|i| (a[i] * a[i + 1]).to_string())
        .collect::<Vec<String>>()
        .join(" ");
    println!("{}", ans);
}
