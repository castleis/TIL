// 배열을 하나의 값으로 계산하는 동작이 필요할 때 사용
// map, filter 등 여러 배열 메서드 동작을 대부분 대체할 수 있음
const numbers = [90,80,70,100]

// 배열 요소들의 총 합 구하기
// 1 단계
// 콜백 함수) result : acc, number : element, 
// initialValue : 0 (없으면 배열의 제일 처음부터 들어감)
// 인자가 2개 : function 과 initial value 0
const sumNum1 = numbers.reduce(function (result,number) {
    return result + number
}, 0)
// console.log(sumNum1)

// 2
const sumNum2 = numbers.reduce((result,number) => {
    console.log(result)
    return result + number
}, 0)
// console.log(sumNum2)

// 평균 구하기
const avgNum = numbers.reduce((result,number) => result + number, 0) / numbers.length