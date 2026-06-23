// 전화번호부 입력 폼
// file: src/components/PhoneForm.js

import React, { Component } from 'react';

class PhoneForm extends Component {
    state = {
        name: '',
        phone: ''
    }
    
    handleChange = (e) => {
        this.setState({
          [e.target.name]: e.target.value
        })
    }

    handleSubmit = (e) => {
        //  페이지 리로딩 방지
        e.preventDefault();
        //  상태값을 onCreate를 통해서 부모에게 전달
        this.props.onCreate(this.state);
        //  상태 초기화
        this.setState({
            name: '',
            phone: ''
        })
    }


    render() {
        return(
            <form onSubmit={this.handleSubmit}>
                <input
                    placeholder="이름"
                    value={this.state.name}
                    onChange={this.handleChange}
                    name="name"
                />
                <br></br>
                <input 
                    placeholder="전화번호"
                    value={this.state.phone} 
                    onChange={this.handleChange}
                    name="phone"
                />
                <div>{this.state.name} {this.state.phone}</div>
                <button type="submit">등록</button>
            </form>
        );
    }
}

export default PhoneForm;