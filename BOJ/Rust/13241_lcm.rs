use std::io::stdin;

fn get_gcd(mut a: u64, mut b: u64) -> u64{
    loop{
        if b == 0{
            return a;
        }
        (a, b) = (b, a % b);
    }
}

fn get_lcm(a: u64, b: u64) -> u64{
    return a / get_gcd(a, b) * b;
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace().map(
            |s| s.parse::<u64>().unwrap()
        );

    let (a, b) = (input.next().unwrap(), input.next().unwrap());
    print!("{}", get_lcm(a, b));
}