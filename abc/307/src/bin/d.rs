use proconio::{input, marker::Chars};

fn main() {
    input! {
        _: usize,
        s: Chars,
    }

    let mut stack = Vec::new();
    let mut left_count = 0;

    for c in s {
        if c == '(' {
            stack.push(c);
            left_count += 1;
        } else if c == ')' {
            if left_count > 0 {
                while let Some(d) = stack.pop() {
                    if d == '(' {
                        left_count -= 1;
                        break;
                    }
                }
            } else {
                stack.push(c);
            }
        } else {
            stack.push(c);
        }
    }

    if !stack.is_empty() {
        println!("{}", stack.into_iter().collect::<String>());
    }
}
