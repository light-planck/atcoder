use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        k: usize,
    }

    let n = 10;
    let mut ans: Vec<i64> = vec![];

    for bit in 0..1 << n {
        let mut number: i64 = 0;

        for i in (0..n as usize).rev() {
            if bit & (1 << i) > 0 {
                number = number * 10 + i as i64;
            }
        }

        if number > 0 {
            ans.push(number);
        }
    }

    ans.sort_unstable();
    println!("{}", ans[k - 1]);
}
