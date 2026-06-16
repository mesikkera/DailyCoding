import {
  GRID_SIZE,
  cellKey,
  createInitialState,
  createSeededRandom,
  setDirection,
  step,
} from './game.mjs';

const TICK_MS = 120;
const random = createSeededRandom(Date.now());
const board = document.querySelector('#board');
const score = document.querySelector('#score');
const status = document.querySelector('#status');
const startButton = document.querySelector('#start-button');
const pauseButton = document.querySelector('#pause-button');
const restartButton = document.querySelector('#restart-button');
const directionButtons = document.querySelectorAll('[data-direction]');

let state = createInitialState({ size: GRID_SIZE, random });
let timerId = null;
let cells = [];

const keyDirections = {
  ArrowUp: 'up',
  KeyW: 'up',
  ArrowRight: 'right',
  KeyD: 'right',
  ArrowDown: 'down',
  KeyS: 'down',
  ArrowLeft: 'left',
  KeyA: 'left',
};

function buildBoard() {
  board.style.setProperty('--grid-size', String(state.size));
  board.innerHTML = '';
  cells = [];

  for (let y = 0; y < state.size; y += 1) {
    for (let x = 0; x < state.size; x += 1) {
      const cell = document.createElement('div');
      cell.className = 'cell';
      cell.setAttribute('role', 'gridcell');
      cell.dataset.key = cellKey({ x, y });
      cells.push(cell);
      board.append(cell);
    }
  }
}

function render() {
  const snakeCells = new Set(state.snake.map(cellKey));
  const headKey = cellKey(state.snake[0]);
  const foodKey = state.food ? cellKey(state.food) : '';

  for (const cell of cells) {
    const key = cell.dataset.key;
    cell.className = 'cell';
    if (snakeCells.has(key)) {
      cell.classList.add(key === headKey ? 'snake-head' : 'snake');
    }
    if (key === foodKey) {
      cell.classList.add('food');
    }
  }

  score.textContent = String(state.score);
  status.textContent = statusText();
  startButton.disabled = state.status === 'running';
  pauseButton.disabled = state.status === 'ready' || state.status === 'gameOver';
  pauseButton.textContent = state.status === 'paused' ? 'Resume' : 'Pause';
}

function statusText() {
  if (state.status === 'gameOver') {
    return 'Game over. Press Restart to play again.';
  }

  if (state.status === 'ready') {
    return 'Press Start or any direction key.';
  }

  if (state.status === 'paused') {
    return 'Paused';
  }

  return 'Running';
}

function startGame() {
  if (state.status === 'gameOver') {
    restartGame();
    return;
  }

  state = { ...state, status: 'running' };
  ensureTimer();
  render();
}

function restartGame() {
  state = createInitialState({ size: GRID_SIZE, random });
  ensureTimer();
  render();
}

function togglePause() {
  if (state.status === 'running') {
    state = { ...state, status: 'paused' };
    render();
    return;
  }

  if (state.status === 'paused') {
    state = { ...state, status: 'running' };
    ensureTimer();
    render();
  }
}

function ensureTimer() {
  if (timerId !== null) {
    return;
  }

  timerId = window.setInterval(() => {
    if (state.status !== 'running') {
      return;
    }

    state = step(state, random);
    render();

    if (state.status === 'gameOver') {
      stopTimer();
    }
  }, TICK_MS);
}

function stopTimer() {
  window.clearInterval(timerId);
  timerId = null;
}

function move(direction) {
  state = setDirection(state, direction);
  ensureTimer();
  render();
}

document.addEventListener('keydown', (event) => {
  if (event.code === 'Space' || event.code === 'KeyP') {
    event.preventDefault();
    togglePause();
    return;
  }

  const direction = keyDirections[event.code];
  if (!direction) {
    return;
  }

  event.preventDefault();
  move(direction);
});

startButton.addEventListener('click', startGame);
pauseButton.addEventListener('click', togglePause);
restartButton.addEventListener('click', restartGame);

for (const button of directionButtons) {
  button.addEventListener('click', () => move(button.dataset.direction));
}

buildBoard();
render();
