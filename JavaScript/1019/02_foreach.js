const colors = ['red', 'blue', 'green']

/*
// 1 단계
const printClr = function (color) {
    console.log(color)
}
colors.forEach(printClr)

// 2 단계, Python의 map의 동작원리와 비슷
colors.forEach(function (color) {
    console.log(color)
})
*/
// 3 단계, 화살표 함수로 만들기
colors.forEach((color) => {
    console.log(color)
})

// 4단계
// colors.forEach((color) => console.log(color))