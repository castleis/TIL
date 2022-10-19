console.log('hello, javascript');

// ===== 함수 선언 =====
// 1. 선언식
function add(num1,num2) {
    return num1 + num2
}
console.log(add(2,7))

// 2. 표현식
const sub = function (num1,num2) {
    return num1 - num2
}
console.log(sub(2,7))

// 3.
const greeting = function (name = 'Anonymous') {
    return `Hi ${name}`
}
console.log(greeting())
    /*
    // 화살표 함수
    // 1 단계 : function 키워드 삭제
    const greeting = (name) => {
        return `Hi ${name}`
    }
    // 2 단계 : 소괄호 생략 (인자가 1개일 경우에만 생략 가능)
    const greeting = name => {
        return `Hi ${name}`
    }
    // 3 단계 : 중괄호 및 return 생략 (함수 바디가 return을 포함한 표현식 1개일 경우)
    // 하지만 명확성과 일관성을 위해 인자 주위에는 소괄호를 사용해주는 것을 권장 ( name -> (name) )
    const greeting = name => `Hi ${name}`
    */
// 1. 인자가 없다면? () or _ 로 표시 가능
let noArgs = () => 'No args'
noArgs = _ => 'No args'

// object를 return 한다면
let returnObject = () => { return { key: 'value'} } // return을 명시적으로 적어주기
// return 을 적지 않으려면 괄호를 붙이기
returnObject = () => 

// 즉시 실행 함수 (화살표 함수로 만들기!)
function (num) {
    return num ** 3
}
// 1. function (num) {return num ** 3}
// 2. (num) => { return num ** 3 }
// 3. ((num) => num ** 3)(2)


// ===== 배열 =====
const numbers = [1,2,3,4,5]
console.log(numbers[0])         // 1
console.log(numbers[-1])        // undefined (음의 정수 인덱스로 접근하면 undefined 반환)
console.log(numbers.length)     // 5
console.log(numbers[numbers.length - 1])  // 5

// 메서드
// reverse
numbers.reverse()
console.log(numbers)            // [5, 4, 3, 2, 1]
// push & pop
numbers.push(100)
console.log(numbers)            // [5, 4, 3, 2, 1, 100]

numbers.pop()
console.log(numbers)            // [5, 4, 3, 2, 1]

// .includes(value) : 있으면 true, 없으면 false
console.log(numbers.includes(1))     // true
console.log(numbers.includes(100))   // false

// .indexOf(value) : 배열에 특정 값이 존재하는지 확인 후 가장 첫번째로 찾은 요소의 인덱스 반환, 없으면 -1 반환
console.log(numbers.indexOf(3))     // 2
console.log(numbers.indexOf(100))    // -1

// .join([separator])
console.log(numbers.join())         // 5,4,3,2,1
console.log(numbers.join(''))       // 54321
console.log(numbers.join(' '))      // 5 4 3 2 1
console.log(numbers.join('-'))      // 5-4-3-2-1