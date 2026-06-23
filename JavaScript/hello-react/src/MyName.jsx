import React, { Component } from 'react';

// class MyName extends Component {
//     // Default Props
//     static defaultProps = {
//         name: 'Default Props'
//     }
//     render() {
//         return (
//             <div>
//                 나의 이름은 <b>{this.props.name}</b> 이다.
//             </div>
//         );
//     }
// }

// MyName.defaultProps = {
//     name: "Devault Props 2"
// }

const MyName = ({ name }) => {
    return (
        <div>
            안녕하세요! 제 이름은 {name} 입니다.
        </div>
    )
}

export default MyName;