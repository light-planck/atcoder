use proconio::input;

fn main() {
    input! {
        (n, m): (usize, usize),
        l: [i64; n],
    }

    let check = |w: i64| -> bool {
        let mut x = 0;
        let mut row = 1;

        for l in &l {
            if x == 0 {
                if *l <= w {
                    x = *l;
                } else {
                    return false;
                }
            } else {
                if x + l + 1 <= w {
                    x += l + 1;
                } else {
                    row += 1;
                    x = *l;
                }
            }
        }

        row <= m
    };

    let mut ok = 1e15 as i64;
    let mut ng = 0;

    while (ok - ng).abs() > 1 {
        let mid = (ok + ng) / 2;

        if check(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    println!("{}", ok);
}
