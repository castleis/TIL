// find
const avengers = [
    { name: 'Tony Stark', age: 45 },
    { name: 'Steve Rogers', age: 32 },
    { nae: 'Thor', age: 40 }, 
]

const avenger = avengers.find((avenger) => {
    return avenger.name === 'Tony Stark'
})
console.log(avenger)    // {name: 'Tony Stark', age: 45}

///////////////////////////////////////////////////
const arr = [1,2,3,4,5]
// some
    // 1. 
const result1 = arr.some(function (elem) {
    return elem % 2 === 0
})
    // 2.
const result2 = arr.some((elem) => {
    return elem % 2 === 0
})
    // 3.
const result3 = arr.some((elem) => elem % 2 === 0)
console.log(result3)    // true

// every
const result4 = arr.every((elem) => elem % 2 === 0)
console.log(result4)    // false