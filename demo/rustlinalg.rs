// rusty_array_utils.rs

use std::os::raw::{c_double, c_int};
use std::slice;

#[no_mangle]
pub unsafe extern "C" fn norm(vector: *const c_double, length: c_int) -> c_double {
    assert!(!vector.is_null(), "provided vector is null");

    let ulen = length as usize;

    let rvec: &[c_double] = slice::from_raw_parts(vector, ulen);
    let mut rtn = 0.0;
    for i in 0..ulen {
        rtn += rvec[i] * rvec[i];
    }
    rtn.sqrt()
}

#[no_mangle]
pub unsafe extern "C" fn subv(
    a: *const c_double,
    b: *const c_double,
    c: *mut c_double,
    length: c_int,
) {
    assert!(!a.is_null(), "provided vector `a` is null");
    assert!(!b.is_null(), "provided vector `b` is null");
    assert!(!c.is_null(), "provided vector `c` is null");

    let ulen = length as usize;

    let rvec_a: &[c_double] = slice::from_raw_parts(a, ulen);
    let rvec_b: &[c_double] = slice::from_raw_parts(b, ulen);
    let mut rslt = vec![0.0; ulen];
    for i in 0..ulen {
        rslt[i] = rvec_a[i] - rvec_b[i];
    }
    // Get a mutuable slice from the provided vector, and copy the result into it.
    slice::from_raw_parts_mut(c, ulen).clone_from_slice(&rslt);
}
