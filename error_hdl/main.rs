enum TMError {
    // No need for NoError because this is inherent in the structure
    HasErrored,
}

fn read_tm1() -> Result<f64, TMError> {
    Err(TMError::HasErrored)
}

fn read_tm2() -> Result<f64, TMError> {
    Ok(753.12)
}

fn main() {
    // NOTE: All variables are read-only unless specified otherwise.
    let num_tms = 2;
    // All variables MUST be initialized -- in this case we set it to zero.
    let mut read_tm_storage = vec![0.0; num_tms];

    match read_tm1() {
        Ok(tm_value) => {
            read_tm_storage[0] = tm_value;
            println!("TM #1: no error -- value = {}", tm_value);
        }
        Err(_) => {
            println!("TM #1: errored -- no value to report");
        }
    }

    match read_tm2() {
        Ok(tm_value) => {
            read_tm_storage[1] = tm_value;
            println!("TM #2: no error -- value = {}", tm_value);
        }
        Err(_) => {
            println!("TM #2: errored -- no value to report");
        }
    }

    println!("\nTo recap, all telemetry to be downlinked includes:");
    for (pos, val) in read_tm_storage.iter().enumerate() {
        println!("TM #{} = {}", pos, val);
    }
}
