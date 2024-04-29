use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i64; n],
    }

    let mut stack: Vec<i64> = Vec::new();

    for a in a {
        stack.push(a);

        while stack.len() > 1 && stack[stack.len() - 1] == stack[stack.len() - 2] {
            let last = stack.pop().unwrap();
            let second_last = stack.pop().unwrap();

            if second_last != last {
                stack.push(second_last);
                stack.push(last);
                break;
            }

            stack.push(last + 1);
        }
    }

    println!("{}", stack.len());
}
