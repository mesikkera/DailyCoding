// 전화번호부 입력 폼
// file: src/components/PhoneForm.js

import React, { Component } from 'react';

class PhoneForm extends Component {
    state = {
        name: '' 
    }
    handleChange = (e) => {
        this.setState({
            name: e.target.value
        })
    }
    render() {
        return(
            <form>
                <input
                    placeholder="이름"
                    value={this.state.name}
                    onChange={this.handleChange}
                />
                <div>{this.state.name}</div>
            </form>
        );
    }
}

export default PhoneForm;