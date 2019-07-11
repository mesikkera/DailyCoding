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
window.o.func();ㅇ

// 함수와 this
// this는 함수 내에서 함수 호출 맥락(context)를 의미.
// 맥락이라는 것은 상황에 따라서 달라진다는 의미인데 즉 함수를 어떻게 호출하느냐에 따라서 this가 가리키는 대상이 달라진다.
// 함수와 객체의 관계가 느슨한 자바 스크립트에서 this는 이 둘을 연결시켜주는 실질적인 연결점의 역할을 한다.
function func() {
    if(window === this) { 
        document.write("window === this");
    }
}
func();

// 메소드의 호출
var o = {
    func : function () {
        if(o === this) {
            document.write("o === this");
        }
    }
}

// 생성자와 this
// 생성자는 빈 객체를 만든다. 그리고 이 객체 내애서 this는 만들어진 객체를 가리킨다.
// 생성자가 실행되기 전까지는 객체는 변수에도 할당될 수 없기 때문에 this가 아니면
// 객체에 대한 어떠한 작업도 할 수 없다.

var funcThis = null;

function Func() {
    funcThis = this;
}
var o1 = Func();
if(funcThis === window) {
    document.write('window <br/>');
}
var o2 = new Func();
if(funcThis === o2) {
    document.write('o2 <br />');
}

// undefined
function Func() {
    document.write(o);
}
var o = new Func();

// 함수 메소드인 apply, call을 이용하면 this의 값을 제어할 수 있다.
var o = {}
var p = {}
function func() {
    switch(this) {
        case o:
            document.write('o<br />');
            break;
        case p:
            document.write('p<br />');
            break;
        case window:
            document.write('window<br />');
            break;
    }
}

// inheritance
function Person(name) {
    this.name = name;
    this.introduce = function() {
        return 'My Name is ' + this.name;
    }
}

var p1 = new Person('mesikkera');
document.write(p1.introduce());

function Person(name) { 
    this.name = name;
}

Person.prototype.name = null;
Person.prototype.introduce = function () {
    return 'My name is ' + this.name;
}
var p1 = new Person('mesikkera');
document.write(p1.introduce());

function Programmer(name) { 
    this.name = name;
}

// prototype이라는 특수한 property
Programmer.prototype = new Person();

var p1 = new Programmer('mesikkera');
document.write(p1.introduce());


// 상속받은 객체의 기능 추가
function Person(name) { 
    this.name = name;
}
Person.prototype.name = null;
Person.prototype.introduce = function() {
    return 'My name is ' + this.name;
}

function Programmer(name) { 
    this.name = name;
}

Programmer.prototype = new Person();
Programmer.prototype.coding = function() {
    return 'hello coding';
}

Designer.prototype = new Person();
Designer.prototype.design = function () {
    return 'hello design';
}

var p1 = new Programmer('mesikkera');
document.write(p1.introduce());
document.write(p1.coding);

// prototype
// 객체의 원형
function Ultra() {}
Ultra.prototype.ultraProp = true;

function Super() {}
Super.prototype = new Ultra();

function Sub() {}
Sub.prototype = new Super();

var o = new Sub();
console.log(o.ultraProp);

// 표준 내장 객체(Standard Built-in Object)
// 자바가 기본적으로 가지고 있는 객체
// Object
// Function
// Array
// String
// Boolean
// Number
// Math
// Date
// RegExp

// 배열의 확장
var arr = new Array('seoul', 'new york', 'ladarkh', 'pusan', 'Tsukuba');
function getRandomValueFromArray(haystack){
    var index = Math.floor(haystack.length * Math.random());
    return haystack[index];
}


// DataType
// Primitive Type: Number, String, Boolean, null, undefined
// ETC: Object Data Type, Reference Data Type
var str = 'coding';
console.log(str.length);
console.log(str.charAt(0));
// 문자열: 프로퍼티, 메소드 ==> 객체
// . : Object Access Operator
// wrapper object



