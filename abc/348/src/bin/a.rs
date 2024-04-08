use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: usize,
    }

    let mut s = vec!['o'; n];
    for i in 0..n {
        if (i+1) % 3 == 0 {
            s[i] = 'x';
        }
    }

    println!("{}", s.into_iter().collect::<String>());
}
