import React, { Component } from 'react';
import Todo from './TODO';
import { complete, complete2 } from '../../action/todo';
import { connect } from 'react-redux';

class TODOList extends Component {
    render() {
        const { todos, onClick } = this.props;
        return (
            <ul>
                {todos.map(todo =>
                    <Todo
                        key={todo.id}
                        onClick={onClick}
                        {...todo}
                    />
                )}
            </ul>
        );
    }
}

const todolistStateToProps = (state) => {
    return {
        todos: state.todos
    }
}

const todolistDispatchToProps = (dispatch) => {
    return {
        onClick(data) {
            // dispatch(complete2(data))
            dispatch(complete(data))
        }
    }
}

export default connect(todolistStateToProps, todolistDispatchToProps)(TODOList);