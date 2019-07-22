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


// 컴포넌트가 렌더링하는 것을 막기
// 



// 리스트와 Key
// map() 함수를 이용해 numbers 배열의 값을 2배로 만든 후 map()에서 반환하는 새 배열을
// doubled 변수에 할당하고 로그를 확인하는 코드.
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map((number) => number * 2);
console.log(doubled);

const numbers = [1, 2, 3, 4, 5];
const listItems = numbers.map((number) => <li>{number}</li>);
ReactDOM.render (
    <ul>{listItem}</ul>,
    document.getElementById('root')
);

// key
const numbers = [1, 2, 3, 4, 5];
const listItems = numbers.map((number) => <li key={number.toString()}>{number}</li>);

// Form
// HTML 폼 엘리먼트는 폼 엘리먼트 자체가 내부 상태를 가지기 때문에, 
// React의 다른 DOM 엘리먼트와 조금 다르게 동작한다.

// React에서 <textarea>는 value 어트리뷰트를 대신 사용한다. 이렇게하면 <textarea>를 사용하는 
// 폼은 한 줄 입력을 사용하는 폼과 비슷하게 작성 가능하다.
class EssayForm extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: 'Please write an essay about your favorite DOM element.'
        }
    }
}

// State 끌어올리기

function BoilingVerdict(props) {
    if (props.celsius >= 100) {
        return <p>The water would boil.</p>
    }
    return <p>The water would not boil.</p>
}

// Composition vs Inheritance
// React는 강력한 합성 모델을 가지고 있으며,
// 상속 대신 합성을 사용하여 컴포넌트간 코드 재사용

function FancyBorder(props) {
    return (
        <div className={'FancyBorder FancyBorder-' + props.color}>
            {props.children}
        </div>
    );
}


// 단일 책임 원칙: 하나의 컴포넌트는 한 가지 일을 하는게 이상적
// 하나의 컴포넌트가 커지게 된다면 이는 보다 작은 하위 컴포넌트로 분리되어야 한다.

// state는 오직 상호작용을 위해, 즉 시간이 지남에 따라 데이터가 바뀌는 것에 사용
// React는 항상 컴포넌트 계층구조를 따라 아래로 내려가는 단방향 데이트 흐름을 따른다.

// React는 전통적인 양방향 데이터 바인딩(two-way data binding)과 비교하면 더 많은 타이핑을 필요로 하지만
// 데이트 흐름을 명시적으로 보이게 만들어서 프로그램이 어떻게 동작하는지 파악할 수 있게 도와준다.

// 애플리케이션의 모든 상태는 하나의 스토어 안에 하나의 객체 트리 구조로 저장된다.
console.log(store.getState());

{
    visibilityFilter: 'SHOW_ALL';
    todos: [{
        text: 'Consider using Redux',
        completed: true,
    }, {
        text: 'keep all state in a single tree',
        completed: false
    }]
}

// 상태는 읽기 전용이다.
// 상태를 변화시키는 유일한 방법은 무슨 일이 벌어지는 지를 묘사하는 액션 객체를 전달하는 방법뿐.

// action type
export const COMPLETE_TODO = 'COMPLETE_TODO'

// action creators(액션 메서드)
export function complete({complete, id}) {
    return {type: COMPLETE_TODO, complete, id};
}

// 비동기 통신이 필요할 때는 redux-thunk라이브러리나 react-sage 라이브러리를 사용한다.

// Component 폴더
// component 폴더는 React 컴포넌트로 구성된 폴더이다.
// 컴포넌트는 컨테이너 컴포넌트와 프레젠테이션 컴포넌트를 구분해서 개발한다.
// 컨테이너 컴포넌트 (Container component): 여러 개의 프레젠테이션 컴포넌트로 구성
//                                          데이터나 공통으로 관리해야 하는 객체, 컴포넌트간의 인터렉션 등을 

class TODOList extends Component {
    render() {
        const { todos, onClick } = this.props;
        return (

        );
    }
}