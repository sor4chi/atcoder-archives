//! Bundle mybin.rs and the crate libraries into singlefile.rs

use std::path::Path;
extern crate rustsourcebundler;
use rustsourcebundler::Bundler;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut bundler: Bundler =
        Bundler::new(Path::new("src/bin/solve.rs"), Path::new("src/bin/out.rs"));
    bundler.crate_name("solver");
    bundler.run();
    Ok(())
}
