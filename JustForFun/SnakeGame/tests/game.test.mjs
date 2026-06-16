import assert from 'node:assert/strict';
import test from 'node:test';
import {
  createInitialState,
  createSeededRandom,
  placeFood,
  setDirection,
  step,
} from '../src/game.mjs';

test('moves the snake one cell in the current direction', () => {
  const state = {
    size: 20,
    snake: [
      { x: 9, y: 10 },
      { x: 8, y: 10 },
      { x: 7, y: 10 },
    ],
    direction: 'right',
    nextDirection: 'right',
    food: { x: 15, y: 10 },
    score: 0,
    ticks: 0,
    status: 'running',
  };

  const next = step(state, () => 0);

  assert.deepEqual(next.snake, [
    { x: 10, y: 10 },
    { x: 9, y: 10 },
    { x: 8, y: 10 },
  ]);
  assert.equal(next.score, 0);
});

test('grows and increments score when eating food', () => {
  const state = {
    size: 20,
    snake: [
      { x: 9, y: 10 },
      { x: 8, y: 10 },
      { x: 7, y: 10 },
    ],
    direction: 'right',
    nextDirection: 'right',
    food: { x: 10, y: 10 },
    score: 0,
    ticks: 0,
    status: 'running',
  };

  const next = step(state, () => 0);

  assert.equal(next.snake.length, 4);
  assert.deepEqual(next.snake[0], { x: 10, y: 10 });
  assert.equal(next.score, 1);
});

test('places food outside the snake body', () => {
  const snake = [
    { x: 0, y: 0 },
    { x: 1, y: 0 },
    { x: 2, y: 0 },
  ];

  const food = placeFood(3, snake, () => 0);

  assert.deepEqual(food, { x: 0, y: 1 });
});

test('returns null when no food cell is available', () => {
  const snake = [
    { x: 0, y: 0 },
    { x: 1, y: 0 },
    { x: 0, y: 1 },
    { x: 1, y: 1 },
  ];

  assert.equal(placeFood(2, snake, () => 0), null);
});

test('ends the game when hitting a wall', () => {
  const state = {
    size: 20,
    snake: [{ x: 19, y: 10 }],
    direction: 'right',
    nextDirection: 'right',
    food: { x: 5, y: 5 },
    score: 0,
    ticks: 0,
    status: 'running',
  };

  const next = step(state, () => 0);

  assert.equal(next.status, 'gameOver');
});

test('ends the game when hitting itself', () => {
  const state = {
    size: 20,
    snake: [
      { x: 5, y: 5 },
      { x: 5, y: 6 },
      { x: 4, y: 6 },
      { x: 4, y: 5 },
      { x: 3, y: 5 },
    ],
    direction: 'up',
    nextDirection: 'left',
    food: { x: 10, y: 10 },
    score: 0,
    ticks: 0,
    status: 'running',
  };

  const next = step(state, () => 0);

  assert.equal(next.status, 'gameOver');
});

test('prevents reversing into the snake body', () => {
  const state = createInitialState({ random: createSeededRandom(1) });
  const next = setDirection(state, 'left');

  assert.equal(next.nextDirection, 'right');
});

test('handles a missing food cell without crashing', () => {
  const state = {
    size: 2,
    snake: [{ x: 0, y: 0 }],
    direction: 'right',
    nextDirection: 'right',
    food: null,
    score: 0,
    ticks: 0,
    status: 'running',
  };

  const next = step(state, () => 0);

  assert.deepEqual(next.snake[0], { x: 1, y: 0 });
  assert.equal(next.score, 0);
});
