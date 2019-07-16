import React, { Component } from 'react';

// 클래스형 컴포넌트
// State: 동적인 데이터
class Counter extends Component {
    // State 정의
    // ... : 자바스크립트의 전개연산자: 기존의 객체 안에 있는 내용을 해당 위치에다가 풀어준다.

    state = {
        number: 0,
    }

    // setState는 객체로 전달되는 값만 업데이트
    handleIncrease = () => {
        // this.setState({
        //     number: this.state.number + 1
        // });
        this.setState(
            (state) => ({
                number: state.number
            })
        )
    }

    handleIncrease = () => {
        const { number } = this.state;
        this.setState({
           number: number + 1 
        });
    }

    handleDecrease = () => {
        this.setState({
            number: this.state.number - 1
        })
    }

// 리액트에서 이벤트 함수를 설정할 때
// 01. 이벤트 이름은 camelCase ==> onclick: onClick, onmousedown: onMouseDown, onchange: onChange
// 02. 이벤트에 전달해주는 값은 함수

    render() {
        return (
            <div>
                <h1>카운터</h1>
                <div>값: {this.state.number}</div>
                <button onClick={this.handleIncrease}>+</button>
                <button onClick={this.handleDecrease}>-</button>
            </div>
        );
    }
}

export default Counter;