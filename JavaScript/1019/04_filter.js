const products = [
    { name: 'cucumber', type: 'vegetable'},
    { name: 'banana', type: 'fruit'},
    { name: 'carrot', type: 'vegetable'},
    { name: 'apple', type: 'fruit'}
]

// callback 함수
const fruitFilter = function (product) {
    return product.type === 'fruit'
}       

const newArray1 = products.filter(fruitFilter)
console.log(newArray1)

// 2
const newArray2 = products.filter(function (product) {
    return product.type === 'fruit'
})

// 3
const newArray3 = products.filter((product) => {
    return product.type === 'fruit'
})