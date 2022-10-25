# DOM이란?
### 1. 웹페이지는 어떻게 만들어질까?
1. 파싱 : 브라우저가 읽어들인 문서를 파싱하여 최종적으로 어떤 내용을 페이지에 렌더링 할지 결정
	- 파싱 후 렌더 트리 생성
	- 렌더 트리를 생성하기 위해 필요한 것들
		1. DOM : HTML 요소들의 구조화 된 표현, 원본 HTML 문서의 객체 기반 표현 방식
		2. CSSOM : 요소들과 연관된 스타일 정보의 구조화된 표현
    - 파싱 (Parsing)
      - 구문 분석, 해석
      - 브라우저가 문자열을 해석하여 DOM Tree로 만드는 과정
2. 렌더링 수행

### 2. 그렇다면 DOM은 어떻게 생성되고 보여질까?
1. DOM 과 HTML의 차이
	- DOM은 단순 텍스트로 구성된 HTML 문서의 내용과 구조가 객체 모델로 변환되어 다양한 프로그램에서 사용될 수 있다는~~~~~~~ 점!!!!!!!!
2. DOM의 객체 구조
	- "노드 트리"로 표현
	- HTML 문서 안에서 태그가 각각 노드가 되고 이 노드들이 포함 관계에 따라 루트요소, 나뭇가지, 잎 등에 해당

### 3. DOM이 아닌 것
1. DOM은 HTML이 아니다.
	- DOM은 HTML로부터 생성되지만 항상 동일하지 않음
	1. DOM은 유효하지 않은 HTML 코드를 올바르게 교정
	2. DOM은 HTML 문서를 볼 수 있는 인터페이스 역할과 동시에 동적 자원이 되어 수정될 수 잇음
		- JS를 사용해 DOM에 새로운 노드를 추가할 수 있음
		- 하지만 HTML 문서의 내용을 변경하진 않는다.
2. DOM은 브라우저에서 보이는 것이 아니다.
	- 브라우저 뷰 포트에 보이는 것은 렌더트리(DOM과 CSSOM의 조합)
	- 렌더 트리는 오직 스크린에 그려지는 것으로 구성되어 있음 (DOM과 다르다)
	- 즉, 렌더링 되는 요소만 관련있기 때문에 시각적으로 보이지 않는 요소는 제외됨
3. DOM은 개발자도구에서 보이는 것이 아니다.
	- 개발자도구의 요소 검사기는 DOM과 가장 가까운 근사치를 제공하지만 DOM에 없는 추가적인 정보 또한 포함
	- (예를들면 CSS의 가상 요소 등)
	- 즉, 가상 요소는 DOM의 일부가 아니기 때문에 JS에 의해 수정될 수 없다.

### 4. 정리
- DOM은 문서 객체 모델 -> HTML 문서를 구조화하여 각 요소를 객체로 취급. 즉, 웹 페이지의 객체 지향 표현이다.
- 문서의 구조화된 표현을 제공하여 프로그램이 언어가 DOM 구조에 접근할 수 있는 방법을 제공, 문서 구조나 스타일, 내용 등을 쉽게 변경할 수 있도록 도움
- 즉, JavaScript는 DOM API를 통해 HTML과 CSS를 동적으로 수정, 사용자 인터페이스를 업데이트하는 일에 가장 많이 쓰임!

# DOM의 주요 객체
1. `window`
   - DOM을 표현하는 창, 가장 최상위 객체로 작성 시 생략 가능
2. `document`
   - 브라우저가 불러온 웹 페이지로 페이지 컨텐츠의 진입점 역할
   - `<body>` 등과 같은 수많은 요소들을 포함하고 있음
   - document는 window의 속성

### DOM 조작

#### 1. 선택하기
1. `document.querySelector(selector)`
   - 제공한 선택자와 일치하는 element **한 개** 선택
   - 제공한 CSS selector를 만족하는 첫 번째 element 객체를 반환 (없다면 null 반환)
   - selector
     - `(tagName)`
     - `('#id')` 
     - `('.class')`

2. `document.querySelectorAll(selector)`
   - 제공한 선택자와 일치하는 **여러 개** element를 선택
   - 매칭할 하나 이상의 셀렉터를 포함하는 유효한 CSS selector를 인자(문자열)로 받음
   - 제공한 CSS selector를 만족하는 NodeList를 반환
   - NodeList
     - index로만 각 항목에 접근 가능
     - 배열의 forEach 메서드 및 다양한 배열 메서드 사용 가능
     - `querySelectorAll()`에 의해 반환되는 NodeList는 DOM의 변경사항을 실시간으로 반영하지 않음

#### 2. 조작하기
1. 태그 생성
   - `document.createElement(tagName)`
   - 작성한 tagName의 HTML 요소를 생성하여 반환
2. 입력 메서드
   - Node`.innerText` = 
   - Node 객체와 그 자손의 텍스트 컨텐츠를 표현
   - 사람이 읽을 수 있는 요소만 남김
   - -> 줄바꿈을 인식하고 숨겨진 내용을 무시하는 등 최종적으로 스타일링이 적용된 모습으로 표현됨
3. 자식 추가
    1. Node`.appendChild()`
        - 한 Node를 특정 부모 노드의 자식 NodeList 중 **마지막 자식**으로 삽입
        - 한번에 오직 하나의 Node만 추가할 수 있음
        - 추가된 Node 객체를 반환
        - 주어진 노드가 이미 문서에 존재하는 다른 노드를 참조한다면 현재 위치에서 새로운 위치로 이동
    2. Node`.preappend()`
        - 노드를 특정 부모 노드의 자식 리스트 중 **제일 앞**으로 삽입
4. 삭제
   - Node`.removeChild()`
   - DOM에서 자식 노드 제거
   - 제거한 노드를 반환

5. 속성 조회
   - Element`.getAttribute(attributeName)`
   - 해당 요소의 지정된 값(문자열)을 반환
   - 인자(attributeName)는 값을 얻고자 하는 속성의 이름

6. 속성 설정
    - Element`.setAttribute(name, value)`
    - 지정된 요소의 값을 설정
    - 속성이 **이미 존재**하면 값을 **갱신**
    - 존재하지 않으면 지정된 이름과 값으로 새 속성을 **추가**
```JavaScript
// a tag 생성 및 컨텐츠 추가
const aTag = document.createElement('a')
aTag.innerText = '구글'
// a 태그의 href 속성 추가
aTag.setAttibute('href', 'https://google.com')
// div 태그의 자식 태그로 a 태그 추가
const div = document.querySelector('div')
div.appendChild(aTag)
// h1 tag 선택 및 클래스 목록 조회
const h1Tag = document.querySelector('h1')
// 클래스가 존재한다면 제거하고 false를 반환, 존재하지 않으면 클래스를 추가하고 true를 반환
h1.classList.toggle('blue')
console.log(h1.classList) // 확인해보기
```
- 이 외에도 많은 메서드들이 존재

# Event
- 프로그래밍하고 있는 시스템에서 일어나는 사건(action) 혹은 발생(occurrence)으로 각 이벤트에 대해 조작할 수 있도록 특정 시점을 시스템이 알려주는 것
  - ex) 버튼 클릭, 키보드 키 입력, 텍스트 복사 등
- 객체로서의 `Event`
  - 네트워크 활동이나 사용자와의 상호작용 같은 사건의 발생을 알리기 위한 객체
  - DOM 요소는 Event를 **수신**하고 받은 Event를 **처리**할 수 있음
  - Event처리는 주로 `addEventListener()`라는 Event handler를 다양한 html 요소에 **부착**하여 처리함

## EventTarget.`addEventListener()`(type, listener[, options])
- 지정한 이벤트가 대상에 전달될 때마다 호출할 함수를 설정
- 즉, 특정 Event가 발생하면, 할 일(콜백 함수)을 등록
- Event를 지원하는 모든 객체(Element, Document, Window 등)를 대상(EventTarget)으로 지정 가능
### 1. `type`
- 반응할 Event 유형을 나타내는 문자열 (대소문자 구분)
- input, click, submit 등

### 2. `listener`
- 지정된 타입의 Event를 수신한 객체
- JavaScript function 객체(콜백 함수)여야 함
- 콜백 함수는 발생한 이벤트의 데이터를 가진 Event 객체를 유일한 매개변수로 받음

### 3. Event 취소
- `event.preventDefault()`
- 현재 Event의 기본 동작을 중단
- HTML 요소의 기본 동작을 작동하지 않게 막음
- ex) a 태그 클릭 시 특정 주소로 이동하지 못하도록, form 태그에서 form 데이터 전송을 막는

```
lodash 라이브러리
- 모듈성, 성능 및 추가 기능을 제공하는 JS 유틸리티 라이브러리
- array, object 등 자료구조를 다룰 때 사용하는 유용, 간편한 유틸리티 함수들을 제공
- ex) reverse, sortBy, range, random 등
```
# `this`
- 어떠한 객체를 가리키는 키워드 (파이썬의 self 느낌)
- JS 함수는 호출될 때 this를 암묵적으로 전달 받음
- 하지만! JS는 해당 함수 호출 방식에 따라 this에 바인딩 되는 객체가 달라짐
- 즉, 함수를 선언할 때 this에 객체가 바인딩 되는 것이 아니라 함수를 호출할 때 함수가 어떻게 호출되었는지에 따라 동적으로 결정됨

## 1. 전역 문맥에서의 this
- 전역 객체를 가리킴
- 전역 객체는 모든 객체의 유일한 최상위 객체를 의미
- 브라우저에서는 브라우저의 전역 객체인 window를 가리킴

## 2. 함수 문맥에서의 this
- 함수 문맥에서의 this는 함수를 호출한 방법에 의해 결정됨

### 1. 단순 호출 시
- 전역 객체를 가리킴
- 브라우저에서는 window, Node.js에서는 global을 의미

### 2. 객체의 메서드로서 호출 시
- 메서드로 선언하고 호출한다면, 객체의 메서드이므로 해당 객체가 바인딩
```JavaScript
const myObj = {
    data: 1,
    myFunc() {
        console.log(this)       // myObj
        console.log(this.data)  // 1
    }
}
myObj.myFunc() // myObj
```

### 3. Nested (Function 키워드)
```JavaScript
const myObj = {
    numbers: [1],
    myFunc() {
        console.log(this)       // myObj
        this.numbers.forEach(function (number) {
            console.log(number) // 1
            console.log(this)   // window
        })
    }
}
myObj.myFunc()
```
- forEach의 콜백 함수 안에서의 this가 메서드의 객체인 myObj를 가리키지 못하고 전역 객체 window를 가리킴
- 이유는? 단순 호출 방식으로 사용되었기 때문!
- 이를 해결하기 위한 방법
  - 함수 표현식을 바꾸자 -> **"화살표 함수"**
  - ```JavaScript
    const myObj = {
    numbers: [1],
    myFunc() {
        console.log(this)       // myObj
        this.numbers.forEach((number) => {
            console.log(number) // 1
            console.log(this)   // myObj
            })
        }
    }
    myObj.myFunc()
    ```
  - 이전의 일반 function 키워드와 달리 메서드의 객체를 잘 가리킴
  - 이유 : 
    - 화살표 함수에서 this는 자신을 감싼 정적 범위
    - 자동으로 한 단계 상위 scope의 context를 바인딩한다.

### 4. 화살표 함수
- 화살표 함수는 호출의 위치와 상관없이 상위 스코프를 가리킴 (Lexical scope this)
#### Lexical scope
- 함수를 어디서 호출하는지가 아닌 **어디에 선언**하였는지에 따라 결정
- Static scope 라고도하며 대부분의 프로그래밍 언어에서 따르는 방식
- 따라서 함수 내의 함수 상황에서 화살표 함수를 쓰는 것을 권장

#### 예외 - `addEventListener()`
- adEventListener에서의 콜백 함수는 특별하게도 fucntion 키워드의 경우 addEventListener를 호출한 대상(eventTarget)을 뜻함
- 즉, 콜백 함수를 화살표 함수로 표현할 경우, 화살표 함수는 상위 스코프를 가리키기 때문에 window 객체가 바인딩 됨
- 결론
  - addEventListener의 콜백 함수는 function 키워드를 사용하기