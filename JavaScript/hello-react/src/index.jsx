import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import * as serviceWorker from './serviceWorker';

// 브라우저상의 리액트 컴포넌트를 보여주기 위해서는 ReactDOM.render함수 사용
// 렌더링할 결과물
ReactDOM.render(<App />, document.getElementById('root'));

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
// 컴포넌트를 어떤 DOM에 그릴지 정해준다.
serviceWorker.unregister();
