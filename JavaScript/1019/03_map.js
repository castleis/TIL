const numbers = [1,2,3,4,5]

// 1 단계
const doubleEle = function (number) {
    return number * 2
}       // callback 함수
const newArray1 = numbers.map(doubleEle)     // 반환 받아주기
console.log(newArray1)   // [2,4,6,8,10]

// 2 단계
const newArray2 = numbers.map(function (number) {
    return number * 2
})

// 3 단계
const newArray3 = numbers.map((number) => {
    return number * 2
})

// 4 단계
const newArray4 = numbers.map((number) => number * 2)