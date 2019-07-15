import { rootCertificates } from "tls";
import { userInfo } from "os";

// 엘리먼트는 React앱의 가장 작은 단위
const element = <h1>Hello, world</h1>

// React 엘리먼트: 일반 객체 (Plain Object)
// 엘리먼트는 컴포넌트의 "구성

// React로 구현된 애플리케이션은 일반적으로 하나의 루트 DOM 노느가 ㅇㅆ다.
// React 엘리먼트를 루트 DOM 노드에 렌더링하려면 둘 다 ReactDOM.render()로 전달
const element = <h1>Hello World!</h1>;
ReactDOM.render(element, document.getElementById('root'));

// React 엘리먼트는 불볍객체
// 엘리먼트 생성한 이후에는 해당 엘리먼트의 자식이나 속성을 변경할 수 없다.
// UI를 업데이트하는 유일한 방법은 새로운 엘리먼트를 생성하고, 이를 ReactDOM.render()로 전달하는 것.

function tick() {
    const element = (
        <div>
            <h1>FEELWAY APP 2.0</h1>
            <h2>It is {new Date().toLocaleTimeString()}.</h2>
        </div>
    );
    ReactDOM.render(element, document.getElementById('root'));
}

setInterval(tick, 1000);

// Components and Props
// 컴포넌트를 정의하는 가장 간단한 방법 - JavaScript 함수를 작성하는 것.
function Welcome(props) { 
    return <h1>Hello, {props.name}</h1>
}
// 데이터를 가진 하나의 "props"(props는 속성을 나타내는 데이터)
// 객체 인자를 받은 후 React 엘리먼트를 반환하므로 유효한 React컴포넌트이다.

// ES6 class를 사용하여 컴포넌트를 정의할 수 있다.
class Welcome extends React.Component {
    render() {
        return <h1>Hello, {this.props.name}</h1>
    }
}

const element = <div />
const element = <Welcome name="Sara" />;

const element = <div tabIndex="0"></div>
const element = <img src={user.avatarUrl}></img>;

// React 엘리먼트
// 엘리먼트는 React앱의 가장 작은 단위.
// React 엘리먼트는 일반 객체 (Plain Object)
// React DOM은 React 엘리먼트와 일치하도록 DOM을 업데이트
const element = {
    type: 'h1',
    props: { 
        className: 'greeting', 
        children: 'Hello, world!'
    }
};

const element = <h1>Hello, world</h1>
ReactDOM.render(element, document.getElementById('root'));

// REACT 엘리먼트는 불변객체
// 엘리먼트를 생성한 이후에는 해당 엘리먼트의 자식이나 속성을 변경할 수 없다.
// 엘리먼트는 하나의 프레임과 같이 특정 시점의 UI를 보여준다.

function tick() {
    const element = {
        <div>
            <h1>Hello, world!</h1>
            <h2>It is {new Date().toLocaleTimeString()}.</h2>
        </div>
    };
    ReactDOM.render(element, document.getElementById('root'));
}

setInterval(tick, 1000);

// React Dom은 해당 엘리먼트와 그 자식 엘리먼트를 이전의 엘리먼트와 비교하여
// DOM을 원하는 상태로 만드는데 필요한 경우에만 DOM을 업데이트 한다.

// Components와 Props
// 컴포넌트를 정의하는 가장 간단한 방법은 JavaScript함수를 작성하는 것.
function Welcome(props) {
    return <h1>Hello, {props.name}</h1>
}

class Welcome extends React.Component {
    render() {
        return <h1>Hello, {this.props.name}</h1>
    }
}

// React의 관점에서 볼 때 위 두 가지 유형의 컴포넌트는 동일하다.
const element = <div />;

// React 엘리먼트는 사용자 정의 컴포넌트로도 나타낼 수 있다.
const element = <Welcome name="Sara" />;

function Welcome(props) { 
    return <h1>Hello, {props.name}</h1>;
}

const element = <Welcome name="Sara" />;
ReactDOM.render (
    element,
    document.getElementById('root')
);

// 컴포넌트의 이름은 항상 대문자로 시작한다.

// 컴포넌트 합성
// 컴포넌트는 자신의 출력에 다른 컴포넌트를 참조할 수 있다.
function Welcome(props) {
    return <h1>Hello, {props.name}</h1>
}

function App() {
    return (
        <div>
            <Welcome name="Sara" />
            <Welcome name="Cahal" />
            <welcome name="Edite" />
        </div>
    );
}

ReactDOM.render(
    <App />,
    document.getElementById('root')
)