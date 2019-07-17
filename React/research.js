<button onClick={activateLasers}>
    Activate Lasers
</button>

// React에서는 false를 반환해도 기본 동작을 방지할 수 없다.
// 반드시 preventDefault를 명시적으로 호출
// e: 합성 이벤트
function ActionLink() {
    function handleClick(e) {
        e.preventDefault();
        console.log('The link was clicked.');
    }

    return (
        <a href="#" onClick={handleClick}>
            Click me
        </a>
    );
}

// 엘리먼트가 처음 렌더링될 때 리스너를 제공

// ES6클래스를 사용하여 컴포넌트를 정의할 때, 일반적인 패턴은 이벤트 핸들러를
// 클래스의 메서드로 만드는 것.
class Toggle extends React.Component {
    constructor(props) {
        super(props);
        this.state = {isToggleOn: true};

        // 콜백에서 'this'가 작동하려면 바인딩 해주어야 한다.
        this.handleClick = this.handleClick.bind(this);
    }

    handleClick() {
        this.setState(state => ({
            isToggleOn: !state.isToggleOn
        }));
    }

    render() {
        return (
            <button onClick={this.handleClick}>
                {this.state.isToggleOn ? 'ON' : 'OFF'}
            </button>
        );
    }
}

ReactDOM.render(
    <Toggle />, 
    document.getElementById('root')
);

// 이벤트 핸들러에 인자 전달하기


// 조건부 렌더링
// React에서 조건부 렌더링은 JavaScript에서의 조건 처리와 같이 동작한다.
function Greeting(props) {
    const isLoggedIn = props.isLoggedIn;
    if(isLoggedIn) {
        return <UserGreeting />;
    }
    return <GuestGreeting />;
}

// 엘리먼트 변수
// 엘리먼트를 저장하기 위해 변수를 사용할 수 있다.
// 출력의 다른 부분은 변하지 않은 채로 컴포넌트의 일부를 조건부로 렌더링할 수 있다.

import react, { Component } from 'React';

class LoginControl extends React.Component {
    constructor(props) {
        super(props);
        this.handleLoginClick = this.handleLoginClick.bind(this);
        this.handleLogoutClick = this.handleLogoutClick.bind(this);
    }

    handleLoginClick() {
        this.setState({isLoggedIn: true});
    }

    handleLogoutClick() {
        this.setState({isLoggedIn: false});
    }

    render() {
        const isLoggedIn = this.state.isLoggedIn;
        let button;

        if (isLoggedIn) {
            button = <LogoutButton onClick={this.handleogoutClick} />;
        } else {
            button = <LoginButton onclick={this.handleLoginClick} />;
        }

        return (
            <div>
                <Greeting isLoggedIn={isLoggedIn} />
                {button}
            </div>
        );
    }
}

ReactDOM.render(
    <LoginControl />,
    document.getElementById('root')
);

// && 뒤의 엘리먼트는 조건이 true일 때 출력.
// 조건이 flase라면 React는 무시.

// condition ? true : false
