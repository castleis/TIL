function slowRequest(callBack) {
  console.log('1. 오래 걸리는 작업 시작 ...')
  setTimeout(function () {  
    callBack()
  }, 3000)    // 3000 : 3초 뒤 실행
}

function myCallBack() {
  console.log('2. 콜백함수 실행됨')
}

slowRequest(myCallBack)
console.log('3. 다른 작업 실행')

// 1 -> 3 -> 2 순으로 출력됨
// 1 -> 2 -> 3 순이 아닌 이유 : JS는 콜백 함수가 실행될때 까지 기다리지 않음
// 일단 다음 코드를 실행 -> 비동기식 처리!