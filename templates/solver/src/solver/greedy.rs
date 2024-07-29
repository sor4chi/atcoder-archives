use crate::io::{Input, Output, IO};

use super::Solver;

pub struct GreedySolver {
    io: IO,
    input: Input,
}

impl GreedySolver {
    pub fn new(io: IO, input: Input) -> Self {
        GreedySolver { io, input }
    }
}

impl Solver for GreedySolver {
    fn solve(&mut self) -> Output {
        unimplemented!()
    }
}
