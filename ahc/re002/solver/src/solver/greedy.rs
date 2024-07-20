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

// 現在位置からの移動方向を決定する（移動する方向を順序づける）
fn order_direction(i: usize, j: usize) -> Vec<Direction> {
    // 壁に近いほど優先度を高くする
    let mut order = vec![];
    order.push((Direction::Up, i));
    order.push((Direction::Down, BOARD_SIZE - i - 1));
    order.push((Direction::Left, j));
    order.push((Direction::Right, BOARD_SIZE - j - 1));
    order.sort_by_key(|x| x.1);
    order.reverse();
    order.into_iter().map(|x| x.0).collect()
}

fn order_direction_rev(i: usize, j: usize) -> Vec<Direction> {
    // 壁に近いほど優先度を高くする
    let mut order = vec![];
    order.push((Direction::Up, i));
    order.push((Direction::Down, BOARD_SIZE - i - 1));
    order.push((Direction::Left, j));
    order.push((Direction::Right, BOARD_SIZE - j - 1));
    order.sort_by_key(|x| x.1);
    order.into_iter().map(|x| x.0).collect()
}

impl Solver for GreedySolver {
    fn solve(&mut self) -> Output {
        // DFSする
        let mut best_ans = vec![];
        let mut stack = vec![];
        let mut first_node = (self.input.si, self.input.sj, vec![], HashSet::new());
        first_node
            .3
            .insert(self.input.t[first_node.0][first_node.1]);
        stack.push(first_node.clone());
        let timer = Instant::now();

        while let Some((i, j, op, visited)) = stack.pop() {
            if timer.elapsed().as_millis() > 950 {
                break;
            }
            if best_ans.len() < op.len() {
                best_ans.clone_from(&op);
            }

            for dir in order_direction(i, j) {
                let (di, dj) = DIRECTIONS.iter().find(|(d, _)| *d == dir).unwrap().1;
                let (ni, nj) = (i as isize + di, j as isize + dj);
                if ni < 0 || nj < 0 || ni >= BOARD_SIZE as isize || nj >= BOARD_SIZE as isize {
                    continue;
                }
                let (ni, nj) = (ni as usize, nj as usize);
                if !visited.contains(&self.input.t[ni][nj]) {
                    let mut new_op = op.clone();
                    new_op.push(dir);
                    let mut visited = visited.clone();
                    visited.insert(self.input.t[ni][nj]);
                    stack.push((ni, nj, new_op, visited));
                }
            }
        }

        stack.push(first_node);
        let timer = Instant::now();

        while let Some((i, j, op, visited)) = stack.pop() {
            if timer.elapsed().as_millis() > 950 {
                break;
            }
            if best_ans.len() < op.len() {
                best_ans.clone_from(&op);
            }

            for dir in order_direction_rev(i, j) {
                let (di, dj) = DIRECTIONS.iter().find(|(d, _)| *d == dir).unwrap().1;
                let (ni, nj) = (i as isize + di, j as isize + dj);
                if ni < 0 || nj < 0 || ni >= BOARD_SIZE as isize || nj >= BOARD_SIZE as isize {
                    continue;
                }
                let (ni, nj) = (ni as usize, nj as usize);
                if !visited.contains(&self.input.t[ni][nj]) {
                    let mut new_op = op.clone();
                    new_op.push(dir);
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
