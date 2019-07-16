import React, { Component } from 'react';

class Counter extends Component {
    state = {
        number: 0
    }

    constructor(props) {
        super(props);
        console.log('constructor');
    }

    componentWillMount() {
        console.log("componentWillMount(deprecated)");
    }
  
    componentDidMount() {
        console.log("componentDidMount");
    }

    shouldComponentUpdate(nextProps, nextState) {
        //  5의 배수라면 리렌더링 하지 않음
        console.log('shouldComponentUPdate');
        if(nextState.number % 5 === 0 ) return false;
        return true;
    }

    ComponentWillUpdate(nextProps, nextState) {
        
    }
};