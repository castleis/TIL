# HTTP
- Hyper Text Transfer Protocol
- HTML 문서와 같은 리소스들을 가져올 수 있도록 해주는 규칙, 규약
- 웹(WWW)에서 이루어지는 모든 데이터 교환의 기초
- 클라이언트 - 서버 프로토콜이라고도 부름
---
## HTTP 특징
1. 비 연결 지향 (Connectionless)
   - 서버는 요청에 대한 응답을 보낸 후 연결을 끊음
2. 무상태 (Stateless)
   - 연결을 끊는 순간 클라이언트와 서버 간의 통신이 끝나며 상태 정보가 유지되지 않음
   - 클라이언트와 서버가 주고받는 메시지들은 서로 완전히 독립적
- 이러한 특징이 있지만 웹 사이트를 사용할 때 페이지를 이동해도 로그인 **상태**가 유지됨
| 어떻게 로그인 상태를 유지할 수 있을까?
- 서버와 클라이언트 간 지속적인 상태 유지를 위해 **쿠키**와 **세션**이 존재
---

## Cookie
- HTTP 쿠키는 상태가 있는 세션을 만들도록 해줌!
- 서버가 사용자의 웹 브라우저에 전송하는 작은 데이터 조각
- 사용자가 웹사이트를 방문하면 해당 웹사이트의 서버를 통해 사용자의 컴퓨터(로컬)에 설치되는 작은 기록 정보 파일
  - 브라우저(클라이언트)는 쿠키를 로컬에 key,value의 데이터 형식으로 저장
  - 이후 동일한 서버에 재요청 시 저장해놓았던 쿠키를 함께 전송
- 쿠키는 현재와 과거, 두개의 요청이 동일한 브라우저에서 들어왔는지 아닌지를 판단할 때 주로 사용
  - 이를 통해 사용자의 로그인 상태 등을 유지할 수 있음
  - 상태가 없는 HTTP 프로토콜에서 상태 정보를 기억시켜주기 때문!
- 즉, 웹 페이지에 접속하면 웹 페이지를 응답한 서버로부터 쿠키를 받아 브라우저에 저장, 클라이언트가 같은 서버에 재요청할 때마다 요청과 함께 저장해두었던 쿠키도 함께 전송
#### 쿠키 사용 목적
1. **세션 관리** (Session management)
   - 로그인, 아이디 자동완성, 하루동안 안보기, 팝업 체크, 장바구니 등의 정보 관리
2. 개인화 (Personalization)
   - 사용자 선호, 테마 등의 설정
3. 트래킹 (Tracking)
   - 사용자 행동을 기록 및 분석

#### 세션
  - 사이트와 특정 브라우저 사이의 **state(상태)**를 유지시키는 것
  - 클라이언트가 서버에 접속하면 서버가 특정 session id를 발급, 클라이언트는 session id를 쿠키에 저장 (session id는 세션을 구별하기 위해 필요)
    - 클라이언트가 다시 동일한 서버에 접속하면 요청과 함께 쿠키(session id가 저장된)를 서버에 전달
    - 쿠키는 요청 때마다 서버에 함께 전송되므로 서버에서 session id를 확인해 알맞은 로직을 처리
  - 사용자의 session id 확인 루트 : 개발자도구 > Application > Cookie > sessionid 의 value : key
  ##### Session in Django
  - Django는 database-backed sessions 저장 방식을 기본 값으로 사용
    - session 정보는 Django DB의 django_session 테이블에 저장
    - 설정을 통해 다른 저장방식으로 변경 가능
  ##### 쿠키의 Lifetime
  1. Session cookie
    - 현재 세션이 종료되면 삭제됨
    - 브라우저 종료와 함께 세션이 삭제됨
   1. Persistent cookies
    - Expires 속성에 지정된 날짜 혹은 Max-Age 속성에 지정된 기간이 지나면 삭제됨

## **HTTP response status code**

- 클라이언트에게 특정 HTTP 요청이 성공적으로 완료되었는지 여부를 알려줌
- 응답은 5개의 그룹으로 나뉘어짐
    1. Informational responses (1XX)
    2. Successful responses (2XX)
    3. Redirection messages (3XX)
    4. Client error responses (4XX)
    5. Server error responses (5XX)


## **HTTP request method**

- HTTP는 request method를 정의하여 주어진 리소스에 수행하길 원하는 행동을 나타냄
- GET
    - 쿼리 스트링 파라미터로 데이터를 보내기 때문에 url을 통해 데이터를 보냄
    - 특정 리소스를 가져오도록 요청할 때 사용
    - 반드시 데이터를 가져올 때만 사용해야 함
    - DB에 변화를 주지 않음
    - CRUD에서 R 역할을 담당 (Reading)
    
- POST
    - 서버로 데이터를 전송할 때 사용
    - 서버에 변경사항을 만듦
    - 리소스를 생성/변경하기 위해 데이터를 HTTP **body**에 담아 전송
    - GET의 쿼리 스트링 파라미터와 다르게 URL로 보내지지 않음
    - CRUD 에서 C / U / D 역할을 담당
- 즉, GET은 단순히 조회하려는 경우 & POST는 서버나 DB에 변경을 요청하는 경우


## **403 Forbidden**

- 서버에 요청이 전달되었지만 권한 때문에 거절되었다는 것을 의미
- 서버에 요청은 도달했으나 서버가 접근을 거부할 때 반환됨
- 권한이 없다 → “작성자가 누구인지 모르기 때문에 함부로 작성할 수 없다”
- 모델(DB)을 조작하는 것을 단순 조회와 달리 최소한의 신원 확인이 필요하기 때문


## CSRF

- Cross - Site - Request - Forgery
- “사이트 간 요청 위조”
- 사용자가 자신의 의지와 무관하게 공격자가 의도한 행동을 하여 특정 웹페이지를 보안에 취약하게 하거나 수정, 삭제 등의 작업을 하게 만드는 공격 방법

CSRF 공격 방어

- “Security Token 사용 방식(CSRF Token)”
    - 사용자의 데이터에 임의의 난수 값(token)을 부여해 매 요청마다 해당 난수 값을 포함시켜 전송 시키도록 함
    - 이후 서버에서 요청을 받을 때마다 전달된 token 값이 유효한지 검증
    - 일반적으로 데이터 변경이 가능한 POST, PATCH, DELETE Method 등에 적용
    - Django는 DTL에서 csrf_token 템플릿 태그를 제공
        - `{% csrf_token %}`
        - 해당 태그가 없다면 Django서버는 요청에 대해 403 Forbidden으로 응답
        - 템플릿에서 내부 URL로 향하는 POST form을 사용하는 경우에만 사용
            → 외부 URL로 향하는 POST form에 대해서는 CSRF 토큰이 유출되어 취약성을 유발할 수 있기 때문에 사용해서는 안됨!!!
        - form 태그 안의 input type이 hidden으로 작성되며 value는 Django에서 생성한 hash 값으로 설정됨
    - 즉, **csrf_token 은 해당 POST 요청이 내가 보낸 것인지를 검증하는 것!!**

# Handling HTTP request
- 같은 목적의 요청을 처리하는 여러개의 view 함수를 method에 따라 같은 view 함수 내에서 처리하도록 해보자
- `if request.method == 'POST':`
  - POST방식의 view 함수 (게시판 pjt의 create)
  - 사용자의 입력을 받아서 DB에 저장 후 redirect
  - 즉, DB 조작이 들어가는 코드!
- `else:`
  - **request.method가 POST가 아니라면**
  - POST가 아닌 다른 방식의 view 함수 (게시판 pjt의 new)
  - 사용자에게 필요한 페이지를 render

is_authenticated : 로그인 / 비로그인 여부만 확인