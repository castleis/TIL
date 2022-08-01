# HTML 문서 구조화
1. 텍스트 요소
2. 그룹 컨텐츠

3. **<form>**
`<form action="/search" method="GET"></form>`
- 정보를 서버에 제출하기 위해 사용하는 태그
- 기본 속성
  1. action : form을 처리할 서버의 URL(데이터를 보낼 곳)
  2. method : form을 제출할 때 사용할 HTTP 메서드
  3. enctype : method가 post인 경우 데이터의 유형

4. **<input>**
`<input type="text" name="q">`
- 다양한 타입을 가지는 입력 데이터 유형과 위젯이 제공됨
- form 태그 안에 사용
- 대표 속성
  1. name : form control에 적용되는 이름(이름/값 페어로 전송됨)
  2. value : form control에 적용되는 값(이름/값 페어로 전송됨)
  3. required, readonly, autofocus, autocomplete, disabled 등
- input label
    - label을 클릭하여 input 자체의 초점을 맞추거나 활성화 시킬 수 있음
      - 사용자는 선택할 수 있는 영역이 늘어나 웹/모바일 환경에서 편하게 사용할 수 있음
      - label과 input 입력의 관계가 시각적 뿐만 아니라 화면리더기에서도 label을 읽어 쉽게 내용을 확인할 수 있도록 함
    - <input>에 id속성을, <label>에는 for 속성을 활용하여 상호 연관을 시킴
- input 유형
  - text : 일반 텍스트 입력
  - password : 입력 시 값이 보이지 않고 문자를 특수기호(*)로 표현
  - email : 이메일 형식이 아닌 경우 form 제출 불가
  - number : min, max, step 속성을 활용하여 숫자 범위 설정 가능
  - file : accept 속성을 활용하여 파일 타입 지정 가능
  - 항목 선택 
    - 일반적으로 label 태그와 함께 사용하여 선택 항목을 작성함
    - 동일 항목에 대하여는 name을 지정하고 선택된 항목에 대한 value를 지정해야 함
      - checkbox : 다중선택 / radio : 단일선택
  - 기타 
    - 다양한 종류의 input을 위한 picker를 제공
      - color : color picker / date : date picker
    - hidden input을 활용하여 사용자 입력을 받지 않고 서버에 전송되어야 하는 값을 설정
      - hidden : 사용자에게 보이지 않는 input
  - <input>요소의 동작은 type에 따라 달라지므로 각각의 내용을 숙지할 것
    - [mozilla](https://developer.mozilla.org/ko/docs/Web/HTML/Element/Input)

# HTML 기본 구조
- HTML : Hyper Text Markup Language
  - 태그 등을 이용하여 문서나 데이터의 구조를 명시하는 언어
```html
<!DOCTYPE html>
<html lang = 'en'>  <!--문서의 최상위(root) 요소-->
<head> <!--문서 메타데이터 요소 / 문서 제목, 인코딩, 스타일, 외부파일 로딩 등-->
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body> <!--문서 본문 요소 / 실제 화면 구성과 관련된 내용-->
    blahblah
</body>
</html>
```
### head
- 메타데이터를 표현하는 규약인 Open Graph Protocol에 맞춰 작성
  - <title> : 브라우저 상단 타이틀
  - <meta> : 문서 레벨 메타데이터 요소
  - <link> : 외부 리소스 연결 요소 (css, favicon 등)
  - <script> : 스크립트 요소 (JavaScript 파일,코드)
  - <style> : CSS 직접 작성

### 요소 (Element)
- HTML의 요소는 태그(시작태그 + 종료 태그)와 태그 사이에 위치한 내용으로 구성
  - 요소는 태그로 내용을 감싸는 것, 정보의 성격과 의미를 정의한다. ex) `<h1>contents</h1>`
  - 내용이 없는 태그도 존재 (종료태그 X) : br,hr,img,input,ling,meta
- 요소는 중첩될 수 있음
  - 요소의 중첩으로 하나의 문서를 구조화할 수 있다
  - 태그의 쌍을 잘 확인해야 함 -> 오류를 반환하지 않고 레이아웃이 깨진채로 출력되기 때문에 디버깅이 힘들어질 수 있음

### 속성 (Attribute)
`<a herf="https://google.com"></a>`
- 속성을 통해 태그의 부가적인 정보를 설정할 수 있음
  - 태그별로 사용할 수 있는 속성은 다름
  - 공백은 없이, 쌍따옴표(") 사용
- 요소는 속성을 가질 수 있으며, 경로나 크기와 같은 추가적인 정보 제공
- 요소의 시작 태그에 작성하며 보통 이름과 값이 하나의 쌍으로 존재
- 태그와 상관 없이 사용가능한 속성(html global attribute)들도 있음
  1. id : 문서 전체에서 유일한 고유 식별자 지정
  2. class : 공백으로 구분된 해당 요소의 클래스의 목록
  3. data-* : 페이지에 개인 사용자 정의 데이터를 저장하기 위해 사용
  4. style : inline 스타일
  5. title : 요소에 대한 추가 정보 지정
  6. tabindex : 요소의 탭 순서

### 시맨틱 태그(Semantic tag)
- html 태그가 특정 목적, 역할 및 의미적 가치(semantic value)를 가지는 것