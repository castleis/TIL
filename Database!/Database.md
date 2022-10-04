# Database

- 체계화된 데이터의 모임
- 여러 사람이 공유하고 사용할 목적으로 통합 관리되는 정보의 집합
- database를 조작하는 프로그램 = DBMS( Database Management System)
    - Oracle, MySQL, SQLite 등
    - DBMS에서 데이터베이스를 조작하기 위해 사용하는 언어를 SQL 이라고 함

# RDB

- Relational Database (관계형 데이터베이스)
- 데이터를 테이블, 행, 열 등으로 나누어 구조화 하는 방식
- 자료를 여러 테이블로 나누어서 관리하고, 이 테이블 간 관계를 설정해 여러 데이터를 쉽게 조작할 수 있다는 장점!
- sql을 이용하여 데이터를 조작
- 기본 구조
    1. 스키마 : 테이블의 구조
        - 데이터 베이스에서 자료의 구조, 표현방법, 관계 등 전반적인 명세를 기술한 것
    2. 테이블 - 필드, 레코드, 기본 키
        - 필드와 레코드를 사용해 조직된 데이터 요소들의 집합(관계)
        - 필드(field) : 속성, 컬럼(Column)
        - 레코드(record) : 튜플, 행(Row). 테이블의 데이터는 레코드에 저장됨
        - 기본 키(PK : Primary Key)
            - 각 레코드의 고유한 값 (각각의 데이터를 구분할 수 있는 고유값)
            - 기술적으로 다른 항목과 절대로 중복X, **단일 값(Unique)**
- RDB의 이점
    1. 데이터를 직관적으로 표현할 수 있음
    2. 관련한 각 데이터에 쉽게 접근할 수 있음
    3. 대량의 데이터도 효율적으로 관리 가능

### RDBMS

- Relational Database Management System (관계형 데이터베이스 관리 시스템)
- 관계형 데이터베이스를 만들고 업데이트하고 관리하는 데 사용하는 프로그램
    - SQLite, MySQL, PostgreSQL, Oracle Database 등

# SQL

- Structured Query Language
- 쉽게 말하자면 SQL은 데이터베이스와 상호작용하는 방법
- RDBMS의 데이터를 관리하기 위해 설계된 특수 목적의 프로그래밍 언어
- RDBMS에서 데이터베이스 스키마를 생성 및 수정할 수 있으며, 테이블에서의 자료 검색 및 관리도 가능
- SQL Commands
    - DDL : 데이터 정의(Definition) 언어
        - 관계형 데이터베이스 구조를 정의하기 위한 명령어
    - DML : 데이터 조작(Manipulation) 언어 → CRUD
    - DCL : 데이터 제어(Control) 언어 → SQLite는 운영체제의 파일 접근 권한으로만 제어 가능

### SQL Syntax

- 모든 SQL문은 키워드로 시작, 하나의 statement는 세미콜론(;)으로 끝남
    - 세미콜론은 각 SQL문을 구분하는 표준 방법
    - 키워드는 대소문자를 구분 X (대문자 작성 권장)

<aside>
💡 Statement(문) : 독립적으로 실행할 수 있는 완전한 코드 조각, cluase로 구성됨

Clause(절) : statement의 하위 단위

Ex) SELECT column_name FROM table_name;

→ 하나의 문, 2개의 절 : [SELECT column_name] + [FROM table_name];

</aside>

# DDL

- “Data Definition”
- DDL은 테이블 구조를 관리
    - CREATE : 테이블 생성
    - ALTER
    - DROP : 삭제
- Query 실행하기

# SQLite Data Types

1. NULL
    - NULL value
    - 정보가 없거나 알 수 없음을 의미
2. INTEGER
    - 정수
    - 크기에 따라 0,1,2,3,4,6 또는 8바이트와 같은 가변 크기를 가짐
3. REAL
    - 실수
    - 8바이트 부동 소수점을 사용하는 10진수 값이 있는 실수
4. TEXT
    - 문자 데이터
5. BLOB (Binary Large Object)
    - 입력된 그대로 저장된 데이터 덩어리 (대용 타입 없음)
    - 바이너리 등 멀티미디어 파일 (ex: 이미지 데이터)

<aside>
💡 Boolean type
SQLite에는 별도의 Boolean 타입이 없고 정수 0 (false)와 1(true)로 저장됨

</aside>

<aside>
💡 SQLite 데이터 타입 결정 규칙

- 값에 둘러싸는 따옴표와 소수점 또는 지수가 없으면 → INTEGER
- 값이 작은 따옴표나 큰따옴표로 묶이면 → TEXT
- 값에 따옴표나 소수점, 지수가 없으면 → REAL
- 값이 따옴표 없이 NULL이면 → NULL

즉, SQLite는 컬럼에 선언된 데이터 타입에 의해서가 아니라 컬럼에 저장된 값에 따라 데이터 타입이 결정됨! (by 동적 타입 시스템)

</aside>