export const GRID_SIZE = 20;
export const START_SNAKE = [
  { x: 9, y: 10 },
  { x: 8, y: 10 },
  { x: 7, y: 10 },
];

export const DIRECTIONS = {
  up: { x: 0, y: -1 },
  right: { x: 1, y: 0 },
  down: { x: 0, y: 1 },
  left: { x: -1, y: 0 },
};

const OPPOSITE = {
  up: 'down',
  right: 'left',
  down: 'up',
  left: 'right',
};

export function createSeededRandom(seed = 1) {
  let value = seed >>> 0;

  return function random() {
    value = (value * 1664525 + 1013904223) >>> 0;
    return value / 4294967296;
  };
}

export function sameCell(a, b) {
  return a.x === b.x && a.y === b.y;
}

export function cellKey(cell) {
  return `${cell.x},${cell.y}`;
}

export function createInitialState({ size = GRID_SIZE, random = createSeededRandom() } = {}) {
  const snake = START_SNAKE.map((cell) => ({ ...cell }));

  return {
    size,
    snake,
    direction: 'right',
    nextDirection: 'right',
    food: placeFood(size, snake, random),
    score: 0,
    ticks: 0,
    status: 'ready',
  };
}

export function setDirection(state, direction) {
  if (!DIRECTIONS[direction]) {
    return state;
  }

  const currentDirection = state.nextDirection || state.direction;
  if (state.snake.length > 1 && OPPOSITE[currentDirection] === direction) {
    return state;
  }

  return {
    ...state,
    nextDirection: direction,
    status: state.status === 'ready' ? 'running' : state.status,
  };
}

export function step(state, random = Math.random) {
  if (state.status === 'gameOver') {
    return state;
  }

  const direction = state.nextDirection || state.direction;
  const delta = DIRECTIONS[direction];
  const head = state.snake[0];
  const nextHead = { x: head.x + delta.x, y: head.y + delta.y };
  const eatsFood = state.food !== null && sameCell(nextHead, state.food);
  const collisionBody = eatsFood ? state.snake : state.snake.slice(0, -1);

  if (isOutOfBounds(nextHead, state.size) || containsCell(collisionBody, nextHead)) {
    return {
      ...state,
      direction,
      nextDirection: direction,
      ticks: state.ticks + 1,
      status: 'gameOver',
    };
  }

  const snake = [nextHead, ...state.snake];
  if (!eatsFood) {
    snake.pop();
  }

  return {
    ...state,
    snake,
    direction,
    nextDirection: direction,
    food: eatsFood ? placeFood(state.size, snake, random) : state.food,
    score: eatsFood ? state.score + 1 : state.score,
    ticks: state.ticks + 1,
    status: 'running',
  };
}

export function placeFood(size, snake, random = Math.random) {
  const occupied = new Set(snake.map(cellKey));
  const openCells = [];

  for (let y = 0; y < size; y += 1) {
    for (let x = 0; x < size; x += 1) {
      const cell = { x, y };
      if (!occupied.has(cellKey(cell))) {
        openCells.push(cell);
      }
    }
  }

  if (openCells.length === 0) {
    return null;
  }

  const index = Math.floor(random() * openCells.length) % openCells.length;
  return openCells[index];
}

export function isOutOfBounds(cell, size) {
  return cell.x < 0 || cell.y < 0 || cell.x >= size || cell.y >= size;
}

export function containsCell(cells, target) {
  return cells.some((cell) => sameCell(cell, target));
}
