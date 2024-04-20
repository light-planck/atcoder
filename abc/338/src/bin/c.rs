use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: usize,
        q: [i64; n],
        a: [i64; n],
        b: [i64; n],
    }

    let binary_search = |a_cnt: i64| -> i64 {
        let mut ok = 0;
        let mut ng = 1e6 as i64 + 1;

        while (ok - ng).abs() > 1 {
            let mid = (ok + ng) / 2;
            let can_cook = (0..n)
                .map(|i| q[i] - a[i] * a_cnt - b[i] * mid)
                .all(|x| x >= 0);

            if can_cook {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        ok
    };

    let mut ans = 0;

    for a_cnt in 0..(1e6 as i64 + 1) {
        let rem_q = (0..n).map(|i| q[i] - a[i] * a_cnt).collect::<Vec<i64>>();
        if rem_q.iter().any(|&x| x < 0) {
            break;
        }

        let ok = binary_search(a_cnt);
        ans = ans.max(a_cnt + ok);
    }

    println!("{}", ans);
}
