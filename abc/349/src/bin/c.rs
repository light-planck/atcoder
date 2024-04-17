use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        s: Chars,
        t: Chars,
    }

    let mut ti = 0;
    let max_ti = if t[2] == 'X' { t.len() - 1 } else { t.len() };

    for c in s {
        if c.to_uppercase().to_string() == t[ti].to_string() {
            ti += 1;

            if ti == max_ti {
                println!("Yes");
                return;
            }
        }
    }

    println!("No");
}
