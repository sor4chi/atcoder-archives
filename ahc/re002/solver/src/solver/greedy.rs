use std::{collections::HashSet, time::Instant};

use crate::io::{Direction, Input, Output, BOARD_SIZE};

use super::Solver;

pub struct GreedySolver {
    input: Input,
}

impl GreedySolver {
    pub fn new(input: Input) -> Self {
        GreedySolver { input }
    }
}

const DIRECTIONS: [(Direction, (isize, isize)); 4] = [
    (Direction::Up, (-1, 0)),
    (Direction::Down, (1, 0)),
    (Direction::Left, (0, -1)),
    (Direction::Right, (0, 1)),
];

impl Solver for GreedySolver {
    fn solve(&mut self) -> Output {
        // DFSする
        let mut best_ans = vec![];
        let mut stack = vec![];
        let mut first_node = (self.input.si, self.input.sj, vec![], HashSet::new());
        first_node.3.insert(self.input.t[first_node.0][first_node.1]);
        stack.push(first_node);
        let timer = Instant::now();
        while let Some((i, j, op, visited)) = stack.pop() {
            if timer.elapsed().as_millis() > 1950 {
                break;
            }
            if best_ans.len() < op.len() {
                best_ans.clone_from(&op);
            }

            for (dir, (di, dj)) in &DIRECTIONS {
                let (ni, nj) = (i as isize + di, j as isize + dj);
                if ni < 0 || nj < 0 || ni >= BOARD_SIZE as isize || nj >= BOARD_SIZE as isize {
                    continue;
                }
                let (ni, nj) = (ni as usize, nj as usize);
                if !visited.contains(&self.input.t[ni][nj]) {
                    let mut new_op = op.clone();
                    new_op.push(*dir);
                    let mut visited = visited.clone();
                    visited.insert(self.input.t[ni][nj]);
                    stack.push((ni, nj, new_op, visited));
                }
            }
        }

        Output {
            directions: best_ans,
        }
    }
}
