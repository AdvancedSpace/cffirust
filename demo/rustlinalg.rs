use std::slice;

#[no_mangle]
pub extern "C" fn norm(vector: *const f64, ulen: usize) -> f64 {
    let rvec: &[f64] = unsafe { slice::from_raw_parts(vector, ulen) };
    let mut rtn = 0.0;
    for i in 0..ulen {
        rtn += rvec[i] * rvec[i];
    }
    rtn.sqrt()
}

#[no_mangle]
pub extern "C" fn subv(a: *const f64, b: *const f64, c: *mut f64, ulen: usize) {
    let rvec_a: &[f64] = unsafe { slice::from_raw_parts(a, ulen) };
    let rvec_b: &[f64] = unsafe { slice::from_raw_parts(b, ulen) };
    let mut rslt = vec![0.0; ulen];
    for i in 0..ulen {
        rslt[i] = rvec_a[i] - rvec_b[i];
    }
    // Get a mutuable slice from the provided vector, and copy the result into it.
    unsafe { slice::from_raw_parts_mut(c, ulen).clone_from_slice(&rslt) };
}
