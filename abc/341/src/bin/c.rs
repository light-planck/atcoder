use proconio::{fastout, input, marker::Chars};

#[fastout]
fn main() {
    input! {
        (h, w, _): (i64, i64, i64),
        t: Chars,
        s: [Chars; h],
    }

    let get_dij = |c: char| -> (i64, i64) {
        match c {
            'U' => (-1, 0),
            'D' => (1, 0),
            'L' => (0, -1),
            'R' => (0, 1),
            _ => unreachable!(),
        }
    };

    let is_valid_land = |i: i64, j: i64| -> bool {
        if (i < 0 || i >= h) || (j < 0 || j >= w) {
            return false;
        }

        s[i as usize][j as usize] == '.'
    };

    let mut ans = 0;

    for (i, row) in s.iter().enumerate() {
        for (j, cell) in row.iter().enumerate() {
            if *cell == '#' {
                continue;
            }

            let mut ok = true;
            let (mut now_i, mut now_j) = (i as i64, j as i64);

            for c in &t {
                let (di, dj) = get_dij(*c);
                let (next_i, next_j) = (now_i + di, now_j + dj);

                if !is_valid_land(next_i, next_j) {
                    ok = false;
                    break;
                }

                now_i = next_i;
                now_j = next_j;
            }

            if ok {
                ans += 1;
            }
        }
    }

    println!("{}", ans);
}
