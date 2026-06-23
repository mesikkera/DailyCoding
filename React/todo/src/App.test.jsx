import React from 'react';
import { act } from 'react';
import { createRoot } from 'react-dom/client';
import { Provider } from 'react-redux';
import App from './component/App';
import reducer from './reducer';
import configureStore from './store';

it('renders without crashing', () => {
  const div = document.createElement('div');
  const root = createRoot(div);
  const store = configureStore(reducer, {
    todos: [
      { id: 1, todo: '빨래하기', complete: false },
    ],
  });

  act(() => {
    root.render(
      <Provider store={store}>
        <App />
      </Provider>
    );
  });

  act(() => {
    root.unmount();
  });
});
