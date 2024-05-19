use proconio::input;

fn main() {
    input! {
        h: i64,
    }

    let mut now: i64 = 0;
    for day in 0.. {
        if now > h {
            println!("{}", day);
            break;
        }

        now += 1 << day;
    }
}
