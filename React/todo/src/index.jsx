import React from 'react';
import configureStore from './store/index';
import { Provider } from 'react-redux';
import { createRoot } from 'react-dom/client';
import reducer from './reducer/index';
import App from './component/App'
import './index.css';

const store = configureStore(reducer,{
	"todos" : [
		{"id":1, "todo":"빨래하기", "complete":false},
		{"id":2, "todo":"청소하기", "complete":false},
		{"id":3, "todo":"공부하기", "complete":false}
	]
});

const root = createRoot(document.getElementById('root'));

const render = () => {
  root.render(
    <Provider store={store}>
      <App />
    </Provider>
  );
};

store.subscribe(render);
render();