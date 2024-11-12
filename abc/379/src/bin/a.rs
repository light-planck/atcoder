use proconio::{input, marker::Chars};

fn main() {
    input! {
        s: Chars,
    }

    let a = s[0];
    let b = s[1];
    let c = s[2];

    println!(
        "{} {}",
        [b, c, a].iter().collect::<String>(),
        [c, a, b].iter().collect::<String>()
    );
}
