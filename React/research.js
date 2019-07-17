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
<button onClick={(e) => this.deleteRow(id, e)}>Delete Row</button>
<button onClick={this.deleteRow.bind(this, id)}>Delete Row</button>