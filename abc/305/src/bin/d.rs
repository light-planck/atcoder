use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i64; n],
        q: usize,
        lr: [(i64, i64); q],
    }

    let mut cu_sum_a = vec![0; n];
    for i in 1..n {
        if i % 2 == 0 {
            cu_sum_a[i] = cu_sum_a[i - 1] + (a[i] - a[i - 1]);
        } else {
            cu_sum_a[i] = cu_sum_a[i - 1];
        }
    }

    let f = |x: i64| -> i64 {
        let idx = a.partition_point(|&a| x >= a) - 1;

        let res = if idx % 2 == 0 {
            cu_sum_a[idx]
        } else {
            cu_sum_a[idx] + (x - a[idx])
        };

        res
    };

    for (l, r) in lr {
        let ans = f(r) - f(l);
        println!("{}", ans);
    }
}
