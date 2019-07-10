$(document).ready(function() {
    'use strict';
    console.log('main.js loaded');
})

// 객체: object
// 객체 정의1
var person = {}
person.name = 'mesikkera';      // variable: property
person.introduce = function() { // function: method
    return 'My name is ' + this.name; // this: function이 속해있는 객체를 가리킨다.
}
document.write(person.introduce());

// 객체 정의2
var person = {
    'name': 'mesikkera', 
    'introduce': function () {
        return 'My name is ' + this.name;
    }
}
document.write(person.introduce());

var p = new person();
// >p
// person {} :  비어있는 객체
// 함수에 new 를 붙이면 그 리턴값은 객체가 된다.

function Person (name) { 
    this.name = name;
    this.introduce = function () { 
        return 'My Name is ' + this.name;
    }
}

var p1 = new Person('mesikkera');
document.write(p1.introduce() + <br />);

var p2 = new Person('mskr');
document.write(p2.introduce());

// 일반적인 객체 지향 언어에서 생성자는 클래스의 소속이다. 하지만 자바스크립트에서는 객체를 만드는 주체는 함수다.
// 함수에 new를 붙이는 것을 통해서 객체를 만들 수 있다는 점은 자바스크립트에서 함수의 위상을 암시하는 단서이면서
// 또 자바스크립트가 추구하는 자유로움을 보여주는 사례라고 할 수 있다.

// 전역객체(Global object)는 특수한 객체. 모든 객체는 이 전역객체의 프로퍼티
function func() { 
    alert('Hello?');
}
func();             //  실행
window.func();      //  실행: func()는 window라는 전역객체의 메소드.

// 모든 전역 변수와 함수는  window객체의 프로퍼티다. 객체를 명시하지 않으면 암묵적으로 window의 프로퍼티로 간주된다.

var o = {'func': function() {
    alert('Hello?');
}}
o.func();
window.o.func();
