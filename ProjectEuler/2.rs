fn main() {
    let mut a1 = 1;
    let mut a2 = 2;
    let mut sum = 2;

    while a2 <= 4_000_000{
        let buf = a1;
        a1 = a2;
        a2 += buf;

        if a2 % 2 == 0{
            sum += a2;
        }
    }
    println!("{}", sum);
}