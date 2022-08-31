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