fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();


    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();

    let n : usize = buf.trim().parse().unwrap();
    let result : char = s.chars().nth(n - 1).unwrap();

    println!("{result}");
}