use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: usize,
        k: usize,
        s: Chars,
    }

    let mut ans = 0;
    let mut i = 0;

    while i < n {
        let mut j = i;

        while j < n && s[j] != 'X' {
            j += 1;
        }

        if j - i >= k {
            ans += (j - i) / k;
        }

        i = j + 1;
    }

    println!("{}", ans);
}
