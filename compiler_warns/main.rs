fn norm(vector: Vec<f64>, vsize: usize) -> f64 {
    let mut norm = 0.0;
    for i in 0..vsize {
        norm += vector[i] * vector[i];
    }
    norm.sqrt()
}

fn subv(a: Vec<f64>, b: Vec<f64>, vsize: usize) -> Vec<f64> {
    let mut out = Vec::with_capacity(vsize);
    for i in 0..vsize {
        out.push(a[i] - b[i]);
    }
    out
}

fn main() {
    // Simple compile-time macro
    let v1 = vec![3.0, 4.0, 5.0];

    // Manual allocation (requires setting this variable to mutable)
    let mut v2 = Vec::with_capacity(2);
    v2.push(6.0);
    v2.push(7.0);
    v2.push(8.0);

    println!("{}", norm(subv(v1, v2, 3), 3));
}
