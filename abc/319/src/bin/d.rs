use proconio::input;

fn main() {
    input! {
        (n, m): (usize, usize),
        l: [i64; n],
    }

    let is_ok = |width: i64| -> bool {
        let mut x = 0;
        let mut row = 1;

        for (i, &l) in l.iter().enumerate() {
            if l > width {
                return false;
            }

            let padding = if i == 0 { 0 } else { 1 };

            if x + l + padding <= width {
                x += l + padding;
            } else {
                row += 1;
                x = l;
            }
        }

        row <= m
    };

    let mut ok = l.iter().sum::<i64>() + n as i64;
    let mut ng = 0;

    while (ok - ng).abs() > 1 {
        let mid = (ok + ng) / 2;

        if is_ok(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    println!("{}", ok);
}
