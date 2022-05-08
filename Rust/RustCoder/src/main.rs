use proconio::input;


fn main() {
    input! {
        x: i32,
    }

    if x < 10 {
        println!("10 未満");
    }

    println!("終了");
}