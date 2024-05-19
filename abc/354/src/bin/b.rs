use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        sc: [(String, i64); n]
    }

    let t = sc.iter().map(|(_, c)| c).sum::<i64>();
    let s = sc.iter().map(|(s, _)| s).sorted().collect::<Vec<&String>>();

    let idx = (t as usize) % n;
    println!("{}", s[idx]);
}
