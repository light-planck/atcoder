use im_rc::HashSet;
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        mut w: usize,
        mut b: usize,
    }

    const S: &str = "wbwbwwbwbwbw";
    const W: usize = 7;
    const B: usize = 5;

    let s = S.repeat(2);
    let n = s.len();
    let mut memo: HashSet<(usize, usize)> = HashSet::new();

    for i in 0..n {
        for j in i + 1..n + 1 {
            let str = &s[i..j];
            let w = str.matches('w').count();
            let b = str.matches('b').count();
            memo.insert((w, b));
        }
    }

    while w > W && b > B {
        w -= W;
        b -= B;
    }

    if memo.contains(&(w, b)) {
        println!("Yes");
    } else {
        println!("No");
    }
}
