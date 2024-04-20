use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: usize,
        q: [i64; n],
        a: [i64; n],
        b: [i64; n],
    }

    let binary_search = |rem_q: &Vec<i64>| -> i64 {
        let mut ok = 0;
        let mut ng = 1e6 as i64 + 1;

        while (ok - ng).abs() > 1 {
            let mid = (ok + ng) / 2;
            let can_cook = rem_q
                .iter()
                .zip(b.iter())
                .map(|(&rem_q, &b)| rem_q - b * mid)
                .all(|x| x >= 0);

            match can_cook {
                true => ok = mid,
                false => ng = mid,
            }
        }

        ok
    };

    let mut ans = 0;

    for a_cnt in 0..(1e6 as i64 + 1) {
        let rem_q = q
            .iter()
            .zip(a.iter())
            .map(|(&qi, &ai)| qi - ai * a_cnt)
            .collect::<Vec<i64>>();

        if rem_q.iter().any(|&x| x < 0) {
            break;
        }

        let ok = binary_search(&rem_q);
        ans = ans.max(a_cnt + ok);
    }

    println!("{}", ans);
}
