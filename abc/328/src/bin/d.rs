use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        s: Chars,
    }

    let mut stk: Vec<char> = vec![];
    for c in s {
        stk.push(c);

        if stk.len() >= 3 && c == 'C' {
            let last = &stk[stk.len() - 3..];
            if last == ['A', 'B', 'C'] {
                for _ in 0..3 {
                    stk.pop();
                }
            }
        }
    }

    if !stk.is_empty() {
        println!("{}", stk.into_iter().collect::<String>());
    }
}
