use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        (a, b): (Usize1, Usize1),
    }

    let n = 3;
    let mut seen = vec![false; n];
    seen[a] = true;
    seen[b] = true;

    let mut ans: Vec<i32> = vec![];
    for i in 0..n {
        if !seen[i] {
            ans.push(i as i32 + 1);
        }
    }

    println!("{}", if ans.len() == 1 { ans[0] } else { -1 });
}
