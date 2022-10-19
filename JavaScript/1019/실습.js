// 1번
const nums = [1,2,3,4,5,6,7,8]

for (let i = 0; i < nums.length; i++) {
  console.log()
}

// for (const i = 0; i < nums.length; i++) {
//                                     ^

// TypeError: Assignment to constant variable.
// 정답 : for문은 i를 재할당하여 사용하기 때문에 키워드를 const 대신 재할당이 가능한 let으로 바꿔줘야 합니다

// 2번
for (num of nums) {
  console.log(num, typeof num)
}
// 정답 : in은 객체를 순회하기 때문에 nums 안의 요소들, 숫자를 출력하려면 of로 바꿔준다
// in으로 배열 순회 시, 각 키 값에 해당하는 "0", "1", ... 을 순회하게 됨.

// 또는!! num 대신 nums[num] 을 출력
// for (num in nums) {
// console.log(nums[num], typeof nums[num])
// }