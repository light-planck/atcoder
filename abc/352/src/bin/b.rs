use itertools::Itertools;
use proconio::{input, marker::Chars};

fn main() {
    input! {
        s: Chars,
        t: Chars,
    }

    let mut si = 0;
    let mut ans = vec![];
    for (i, c) in t.into_iter().enumerate() {
        if s[si] == c {
            si += 1;
            ans.push(i + 1);
        }
    }

    println!("{}", ans.into_iter().join(" "));
}
