use proconio::input;

fn main() {
    input! {
        n: usize,
        sc: [(String, i64); n]
    }

    let t = sc.iter().map(|(_, c)| c).sum::<i64>();
    let mut s = sc.iter().map(|(s, _)| s).collect::<Vec<&String>>();
    s.sort_unstable();

    let idx = (t as usize) % n;
    println!("{}", s[idx]);
}
