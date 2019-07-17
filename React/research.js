function Avatar(props) {
    return (
        <img className="Avatar"
            src={props.user.avatarUrl}
            alt={props.user.name}
        />
    );
}

// props는 읽기 전용이다.
// 함수 컴포넌트나 클래스 컴포넌트 모두 컴포넌트의 자체 props를 수정해서는 안된다.

// 순수함수
function sum(a, b) {
    return a + b;
}

// 순수함수 아님: 자신의 입력값을 변경
function withdraw(account, amount) {
    account.total -= amount;
}

// 모든 React 컴포넌트는 자신의 props를 다룰 때 반드시 순수 함수처럼 동작해야 한다.

// State and LifeCycle

function tick() {
    const element = (
        <div>
            <h1>Hello, world!</h1>
            <h2>It is {new Date().toLocaleTimeString()}.</h2>
        </div>
    );
    ReactDOM.render(
        <Clock date={new Date()} />,        
        document.getElementById('root')
    );
}

setInterval(tick, 1000);


// State는 props와 유사하지만, 비공개이며 컴포넌트에 의해 완전히 제어된다.

class Clock extends React.Component {
    render() {
        return (
            <div>
                <h1>Hello, world!</h1>
                <h2>It is {this.props.date.toLocaleTimeString()}.</h2>
            </div>
        )
    }
}

class Clock extends React.Component {
    constructor(props) {
        // super()는 슈퍼클래스의 생성자를 호출하는 특별한 함수
        // React.Component의 생성자 호출
        super(props);
        this.state = {date: new Date()};
    }

    // 컴포넌트 출력물이 DOM에 렌더링 된 후에 실행
    componentDidMount() {
        this.timerID = setInterval(
            () => this.tick(),
            1000
        );
    }

    componentWillUnmount() {
        clearInterval(this.timerID);
    }

    tick() {
        this.setState({
            date: new Date()
        });
    }

    render() {
        return (
            <div>
                <h1>Hello, world!</h1>
                <h2>It is {this.state.date.toLocaleTimeString()}.</h2>
            </div>
        );
    }
}

ReactDOM.render(
    <Clock />,
    document.getElementById('root')
);

// 직접 State를 수정하지 마라.
// Wrong
this.state.comment = 'Hello';
// Correct
this.setState({comment: 'Hello'});

// State 업데이트는 비동기적일 수도 있다.
// React는 성능을 위해 여러 setState() 호출을 단일 업데이트로 한꺼번에 처리할 수 있다.
// this.props와 this.state가 비동기적으로 업데이트될 수 있기 때문에 다음 state를 계산할 때 
// 해당 값에 의존해서는 안된다.

// Wrong
this.setState({
    counter: this.state.counter + this.props.increment, 
})

// Correct
this.setState((state, props) => ({
        counter: state.counter + props.increment
}));

// Correct
this.setState(function(state, props) {
    return {
        counter: state.counter + props.increment
    };
});

// State업데이트는 병합된다.
// setState()를 호출할 때 React는 제공한 객체를 현재 state로 병합한다.

// state는 다양한 독립적인 변수를 포함할 수 있다.
constructor(props) {
    super(props);
    this.state = {
        posts: [],
        comments: []
    };
}

// 별도의 setState() 호출로 변수를 독립적으로 업데이트 할 수 있다.
componentDidMount() {
    fetchPosts().then(response => {
        this.setState({
            posts: response.posts
        });
    });

    fetchComments().then(response => {
        this.setState({
            comments: response.comments
        });
    });
}

// 컴포넌트는 자신의 state를 자식 컴포넌트에 props로 전달할 수 있다.
<h2>It is {this.state.date.toLocaleTimeString()}.</h2>

// FormattedDate 컴포넌트는 date를 자신의 props로 받을 것이고 이것이 Clock의 state로부터 왔는지,
// Clock의 Props에서 왔는지, 수동으로 입력한 것인지 알지 못한다.
<FormattedDate date={this.state.date} />

// 모든 State는 항상 특정한 컴포넌트가 소유하고 있으며 그 State로부터 파생된 UI 또는 
// 데이터는 오직 트리구조에서 자신의 "아래"에 있는 컴포넌트에만 영향을 미친다.



// 이벤트 처리하기
// React의 이벤트는 소문자 대신 캐멀케이스(camelCase)를 사용
// JSX를 사용하여 문자열이 아닌 함수로 이벤트 핸들러 전달

