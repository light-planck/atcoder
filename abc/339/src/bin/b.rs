use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
    }

    struct Pos {
        i: usize,
        j: usize,
        dir: usize,
    }

    const DIRECTIONS: [(i64, i64); 4] = [(-1, 0), (0, 1), (1, 0), (0, -1)];

    let mut s = vec![vec!['.'; w]; h];
    let mut pos = Pos { i: 0, j: 0, dir: 0 };

    for _ in 0..n {
        let Pos { i, j, dir } = pos;

        let next_dir = (dir + if s[i][j] == '.' { 1 } else { 3 }) % 4;

        s[i][j] = if s[i][j] == '.' { '#' } else { '.' };

        let (di, dj) = DIRECTIONS[next_dir];
        pos = Pos {
            i: ((i as i64 + di + h as i64) % h as i64) as usize,
            j: ((j as i64 + dj + w as i64) % w as i64) as usize,
            dir: next_dir,
        };
    }

    for row in s {
        println!("{}", row.into_iter().collect::<String>());
    }
}
