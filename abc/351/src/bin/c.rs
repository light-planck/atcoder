use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i64; n],
    }

    let mut b: Vec<i64> = Vec::new();

    for a in &a {
        b.push(*a);

        while b.len() > 1 && b[b.len() - 1] == b[b.len() - 2] {
            let c = b.pop().unwrap();
            let d = b.pop().unwrap();

            if c != d {
                b.push(c);
                b.push(d);
                break;
            }

            b.push(c + 1);
        }
    }

    println!("{}", b.len());
}
