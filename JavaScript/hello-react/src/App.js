// JSX를 사용하기 위해서는 react를 임포트 해주어야 한다.
// import React from 'react';
import React, { Component } from 'react';
// import logo from './logo.svg';
import './App.css';
// import MyName from './MyName';
import Counter from './Counter';

// var는 scopr가 함수 단위
// const, let은 scopr가 블록 단위
// ES6에서는 var을 쓸 일이 없고,, 값을 선언 후 바꾸여야 할 때는 let, 바꾸지 않을 땐 const

// 리액트 컴포넌트에서 다루는 데이터는 Props와 state로 나뉜다. 
// props는 부모 컴포넌트가 자식 컴포넌트에게 주는 값.
// 자식 컴포넌트에서는 props를 받아오기만 하고, 받아온 props를 직접 수정할 수 없다.
// state는 컴포넌트 내부에서 선언하며, 내부에서 값을 변경할 수 있다. 




class App extends Component {
  render() {
    return (
      <Counter />
    )
  }
}

// function App() {
//   return (
//     <div className="App">
//       <header className="App-header">
//         <img src={logo} className="App-logo" alt="logo" />
//         <p>
//           Edit <code>src/App.js</code> and save to reload.
//         </p>
//         <a
//           className="App-link"
//           href="https://reactjs.org"
//           target="_blank"
//           rel="noopener noreferrer"
//         >
//           Learn React
//         </a>
//       </header>
//     </div>
//   );
// }

export default App;
