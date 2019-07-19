var myOtherVar = 10;

function a() {
    console.log('myVar: ', myVar)
    b()
}

function b() {
    console.log('myOtherVar: ', myOtherVar)
    c()
}

function c() {
    console.log('test')
}

a()

var myVar = 5