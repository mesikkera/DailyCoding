// action type
const ADD_TODO = 'ADD_TODO'
const COMPLETED_TODO = 'COMPLETE_TODO'

// action creators
function addTodo(text) {
    return { type: ADD_TODO, text };
}

// const f1 = function() { return 'Hello!'}/
// const f1 => () => "hello!";
// const f2 = function(name) { return 'Hello, ${name}!';}
// const f2 => name => 'Hello, ${name}!';
// const f3 = function(a, b) { return a + b;}
// const f3 => (a, b) => a + b;

// 액션 메서드에서는 리듀서(reducer)로 데이터 생성을 요청
// 비즈니스 로직을 주로 액션 메서드에서 개발하기 때문에 액션 메서드는 
// 컴포넌트의 재활용을 높이고 코드를 관리하는 데 중요한 역할

function addTodo2(text) {
    return (dispatch) => {
        return fetch("api/add.json").then(
            res => res.json().then(data => dispatch(addTodo(data.status)))
        );
    };
}

function complete({complete, id}) {
    return { type: COMPLETED_TODO, complete, id };
}

function complete2 (data2) {
    return (dispatch) => {
        return fetch("api/add.json").then(
            res => res.json().then(data => dispatch(complete(data2)))
        );
    };
}

export {
    ADD_TODO, 
    COMPLETED_TODO, 
    addTodo, 
    addTodo2, 
    complete,
    complete2
}