# Database

- 체계화된 데이터의 모임
- 여러 사람이 공유하고 사용할 목적으로 통합 관리되는 정보의 집합
- 스프레드 시트와 달리 프로그래밍 언어를 사용해 작동 시킬 수 있음
- database를 조작하는 프로그램 = DBMS( Database Management System)
    - Oracle, MySQL, SQLite 등
    - DBMS에서 데이터베이스를 조작하기 위해 사용하는 언어를 SQL 이라고 함

# RDB : 관계형 데이터베이스

- Relational Database
- 데이터를 테이블, 행, 열 등으로 나누어 구조화
- 테이블 간 관계를 설정해 여러 데이터를 쉽게 조작할 수 있다는 장점!
- SQL을 이용하여 데이터를 조회 및 조작
- 기본 구조
    1. **스키마** : 테이블의 구조
        - 데이터 베이스에서 자료의 구조, 표현방법, 관계 등 전반적인 명세를 기술한 것
    2. **테이블** - 필드, 레코드, 기본 키
        - 필드와 레코드를 사용해 조직된 데이터 요소들의 집합(관계)
        - **필드(field)** : 속성, 컬럼(Column)
        - **레코드(record)** : 튜플, 행(Row). 테이블의 데이터는 레코드에 저장됨
        - **기본 키(PK : Primary Key)**
            - 각 레코드의 고유한 값 (각각의 데이터를 구분할 수 있는 고유값)
            - 기술적으로 다른 항목과 절대로 중복X, **단일 값(Unique)**
- RDB의 이점
    1. 데이터를 직관적으로 표현할 수 있음
    2. 관련한 각 데이터에 쉽게 접근할 수 있음
    3. 대량의 데이터도 효율적으로 관리 가능

### RDBMS : 관계형 데이터베이스 관리 시스템

- Relational Database Management System
- 웹 개발에서 대부분의 데이터베이스는 RDBMS을 사용하여 SQL로 데이터와 프로그래밍을 구성
- 관계형 데이터베이스를 만들고 업데이트하고 관리하는 데 사용하는 프로그램
    - SQLite, MySQL, PostgreSQL, Oracle Database 등

# SQL : Structured Query Language

- 쉽게 말하자면 SQL은 데이터베이스와 상호작용하는 방법
- RDBMS의 데이터를 관리하기 위해 설계된 특수 목적의 프로그래밍 언어
- RDBMS에서 데이터베이스 스키마를 생성 및 수정할 수 있으며, 테이블에서의 자료 검색 및 관리도 가능
- SQL Commands
    - DDL : 데이터 정의(Definition) 언어
        - 관계형 데이터베이스 구조를 정의하기 위한 명령어
    - DML : 데이터 조작(Manipulation) 언어 → CRUD
    - DCL : 데이터 제어(Control) 언어 → SQLite는 운영체제의 파일 접근 권한으로만 제어 가능

### SQL Syntax

- 모든 SQL문은 SELECT, INSERT, UPDATE 등과 같은 키워드로 시작, 하나의 statement는 세미콜론(;)으로 끝남
    - 세미콜론은 각 SQL문을 구분하는 표준 방법
    - SQL 키워드는 대소문자를 구분 X (대문자 작성 권장)

```
💡 Statement(문) : 독립적으로 실행할 수 있는 완전한 코드 조각, cluase로 구성됨

Clause(절) : statement의 하위 단위

Ex) SELECT column_name FROM table_name;

→ 하나의 문, 2개의 절 : [SELECT column_name] + [FROM table_name];

```

# DDL : 데이터 정의

- “Data Definition Language”
- DDL은 테이블 구조를 관리
    1. CREATE : 테이블 생성
    2. ALTER
    3. DROP : 삭제

## 1. CREATE TABLE

- 데이터베이스에 새 테이블을 만듦

```sql
-- 기본 구조
CREATE TABLE table_name (
	column_1 data_type constraints,
	column_2 data_type constraints,
	column_3 data_type constraints,
);

-- 실습에 사용할 테이블
CREATE TABLE contacts (
	name TEXT NOT NULL,
	age INTEGER NOT NULL,
	email TEXT NOT NULL UNIQUE
);
```

```
😊 Query 실행하기

- 실행하고자 하는 명령문에 커서를 두고 마우스 우클릭 → ‘Run Selected Query’ 선택
- id 컬럼은 직접 기본 키 역할의 컬럼을 정의하지 않으면 자동으로 rowid라는 컬럼으로 만들어짐
```

### SQLite Data Types

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

```
💡 Boolean type
SQLite에는 별도의 Boolean 타입이 없고 정수 0 (false)와 1(true)로 저장됨

```

```
💡 Date & Time Datatype

- SQLite에는 날짜 및 시간을 저장하기 위한 타입이 없음
- 대신 built-in ‘Data And Time Functions’로 TEXT, REAL, INTEGER 값으로 저장할 수 있음
```

- SQLite 데이터 타입 결정 규칙
    - 값에 둘러싸는 따옴표와 소수점 또는 지수가 없으면 → INTEGER
    - 값이 작은 따옴표나 큰따옴표로 묶이면 → TEXT
    - 값에 따옴표나 소수점, 지수가 없으면 → REAL
    - 값이 따옴표 없이 NULL이면 → NULL
- SQLite Datatypes 특징
    - 테이블을 생성할 때 컬럼에 대해 특정 데이터 타입을 선언하지 않아도 됨
    - 즉, SQLite는 컬럼에 선언된 데이터 타입에 의해서가 아니라 컬럼에 저장된 값에 따라 데이터 타입이 결정됨! (by 동적 타입 시스템)
        
        → 다만 다른 데이터베이스와의 호환성 문제를 위해 테이블 생성 시 데이터 타입을 지정하는 것을 권장
        
    - 데이터 타입을 지정하게 되면, 입력된 데이터의 타입을 지정된 데이터 타입으로 변환
        
        ex) TEXT타입 컬럼에 정수 1을 저장하면 문자 타입의 ‘1’로 저장됨
        
    - 타입 선호도 (Type Affinity)
        - 특정 컬럼에 저장된 데이터에 권장되는 타입
        - 데이터 타입 작성 시 SQLite의 5가지 데이터 타입이 아닌 다른 데이터 타입을 선언한다면, 내부적으로 각 타입의 지정된 선호도에 따라 5가지 선호도로 인식됨
        - INTEGER, TEXT, BLOB, REAL, NUMERIC
        - 타입 선호도는 다른 데이터베이스 엔진 간의 호환성을 최대화 하고 정적이고 엄격한 타입을 사용하는 데이터베이스의 SQL 문을 SQLite에서도 작동하도록 하기 위함
    
    <허용 가능한 타입 변환 표>
    
    | Column Datatype | Types Allowed in that Column |
    | --- | --- |
    | INTEGER | INTEGER, REAL, TEXT, BLOB |
    | REAL | REAL, TEXT, BLOB |
    | TEXT | TEXT, BLOB |
    | BLOB | INTEGER, REAL, TEXT, BLOB |
    
    <Type Affinity>
    
    | Example Typenames | Resulting Affinity |
    | --- | --- |
    | INT, INTEGER, TINYINT, SMALLINT, MEDIUMINT, BIGINT, UNSIGNED, INT2, INT8, BIG INT | INTEGER |
    | CHARACTER(20), VARCHAR(255), VARYING CHARACTER(255), NCHAR(55), NATIVE CHARACTER(70), TEXT, CLOB | TEXT |
    | BLOB | BLOB |
    | REAL, DOUBLE, FLOAT | REAL |
    | NUMERIC, DECIMAL(10,5), BOOLEAN, DATE, DATETIME | NUMERIC |

```
💡 static, rigid typing 데이터 베이스

- 저장되는 값의 데이터 타입은 컬럼에 선언된 데이터 타입에 의해 결정됨

```sql
CREATE TABLE my_table (
	a INTEGER NOT NULL,
	b TEXT NOT NULL,
);
```

- 만약 a 컬럼에 ‘123’, b 컬럼에 456 데이터를 삽입하려는 경우 삽입을 수행하기 전에 문자열 ‘123’을 정수 123으로 변환하고 정수 456을 문자열 ‘456’으로 변환
```

### Constraints

- 입력하는 자료에 대해 제약을 정하고, 제약에 맞지 않는다면 입력이 거부됨
- 사용자가 원하는 조건의 데이터만 유지하기 위한, 즉, **데이터의 무결성을 유지하기 위한** 보편적인 방법으로 테이블의 특정 컬럼에 설정하는 제약
- 데이터 무결성
    - **데이터의 정확성, 일관성**을 나타냄.
    - 데이터베이스 내의 데이터에 대한 정확성, 일관성을 보장하기 위해 데이터 변경 혹은 수정 시 여러 제한을 두어 데이터의 정확성을 보증하는 것
- Constraints 종류
    1. NOT NULL
        - 컬럼이 NULL 값을 허용하지 않도록!
        - 기본적으로 테이블의 모든 컬럼은 NOT NULL 제약 조건을 명시적으로 사용하는 경우를 제외하고는 NULL값을 허용
    2. UNIQUE
        - 컬럼의 모든 값이 서로 구별되거나 고유한 값이 되도록 함
    3. PRIMARY KEY
        
        ```sql
        CREATE TABLE table_name (
        	id INTEGER PRIMARY KEY,
        	...
        );
        ```
        
    - 테이블에서 행의 고유성을 식별하는데 사용되는 컬럼
    - 각 테이블에는 하나의 기본 키만 있음
    - 암시적으로 NOT NULL 제약 조건이 포함되어 있다.
    - INTEGER 타입에만 사용 가능!
    1.  AUTOINCREMENT
        - 사용되지 않은 값이나 이전에 삭제된 행의 값을 재사용하는 것을 방지
        - INTEGER PRIMARY KEY 다음에 작성하면 해당 rowid를 다시 재사용하지 못하도록 함
            
            ```sql
            CREATE TABLE table_name (
            	id INTEGER PRIMARY KEY AUTOINCREMENT,
            	...
            );
            ```
            
        - Django에서 테이블 생성 시 id 컬럼에 기본적으로 사용하는 제약조건이다!
    

```
rowid의 특징
- 테이블을 생성할 때마다 rowid라는 암시적 자동 증가 컬럼이 자동으로 생성됨
- 테이블의 행을 고유하게 식별하는 64비트 부호 있는 정수 값
- 테이블에 새 행을 삽입할 때마다 정수 값을 자동으로 할당
	- 값은 1에서 시작
	- 데이터 삽입 시, rowid 또는 INTEGER PRIMARY KEY 컬럼에 명시적으로 값이 지정되지 않은 경우, 
		SQLite는 테이블에서 가장 큰 rowid보다 하나 큰 다음 순차 정수를 자동으로 할당
		(AUTOINCREMENT와 관계 없이! 항상!)
- 만약 INTEGER PRIMARY KEY 키워드를 가진 컬럼을 직접 만들면 이 컬럼은 rowid 컬럼의 별칭으로 사용 가능
	- 즉, 새 컬럼 이름으로 rowid에 접근할 수 있으며 rowid로도 여전히 접근 가능
- 데이터가 최대 값에 도달했을 때 새로운 행을 삽입하려고 하면 SQLite는 사용되지 않는 정수를 찾아 사용
	- 찾을 수 없다면 SQLITE_FULL 에러 발생, 
		일부 행을 삭제하고 새 행을 삽입하면 삭제된 행에서 rowid 값을 재사용하려고 시도
```

## 2. ALTER TABLE

- MODIFY THE STRUCTURE OF AN EXISTING TABLE
- 기본 테이블의 구조를 수정 및 변경
    - **Rename** a table
    - **Rename** a column
    - **Add** a new coluumn to a table
        - 테이블에 기존 데이터가 있을 경우 다음과 같은 에러 발생
        - Cannot add NOT NULL column with default value NULL
    - **Delete** a column
    
    ```sql
    -- 1. Rename a table
    ALTER TABLE table_name RENAME TO new_table_name;
    
    -- 2. Rename a column
    ALTER TABLE table_name REMANE COLUMN column_name TO new_column_name;
    
    -- 3. Add a new column to a table
    ALTER TABLE table_name ADD COLUMN column_definition;
    	-- 테이블에 기존 데이터가 있을 경우 다음과 같은 에러 발생
    Cannot add NOT NULL column with default value NULL
    -- 이전에 이미 저장된 데이터들은 새롭게 추가되는 컬럼에 값이 없기 때문에 NULL이 작성되지만 
    새로 추가되는 컬럼에 NOT NULL 제약조건이 있기 때문에 기본값 없이는 추가될 수 없다는 에러가 발생
    -- 해결방법 : DEFAULT 제약조건 사용 (데이터를 추가할 때 값을 생략 시, 기본값 설정)
    ALTER TABLE new_table ADD COLUMN column_definition TEXT NOT NULL DEFAULT 'no context';
    
    -- 4. Delete a column
    ALTER TABLE table_name DROP COLUMN column_name;
    -- 삭제하지 못하는 경우
    -- 1. 컬럼이 다른 부분에서 참조되는 경우 : FOREIGN KEY(외래 키) 제약조건에서 사용되는 경우
    -- 2. PRIMARY KEY인 경우
    -- 3. UNIQUE 제약 조건이 있는 경우
    ```
    

## 3. DROP TABLE

- Remove a table from the database
- 데이터베이스에서 테이블을 제거
- 존재하지 않는 테이블을 제거하면 SQLite에서 오류가 발생
- 한 번에 하나의 테이블만 삭제할 수 있음
    - 여러 테이블을 삭제하려면 삭제하려는 만큼 DROP TABLE문을 실행해야 함
- DROP TABLE 문은 실행 취소하거나 복구할 수 없음!!

# DML : 데이터 조작

```sql
CSV 파일을 SQLite 테이블로 가져오기
1. DML.sql 파일 생성
2. 테이블 생성하기 -> CREATE TABLE table_name(
																);
3. 데이터베이스 파일 열기
		sqlite3 mydb.sqlite3
4. 모드(.mode)를 csv로 설정
		sqlite> .mode csv
5. .import 명령어를 사용하여 csv 데이터를 테이블로 가져오기
		sqlite> .import users.cvs users
6. import된 데이터 확인하기
```

### 1. SELECT

: SELECT 문을 사용하여 간단하게 단일 테이블에서 데이터를 조회하기

- Query data from data
- 특정 테이블에서 데이터를 조회하기 위해 사용
- `SELECT column1, column2 FROM table_name;`
    - SELECT 절에서 컬럼 또는 쉼표로 구분된 컬럼 목록을 지정 (column1과 column2)
        - 전체 데이터를 조회하려면 SELECT절에 모든 컬럼에 대한 약칭인 *** (asterisk)**를 사용
    - FROM절에서 데이터를 가져올 테이블을 지정 (table_name)
    - FROM절 뿐만 아니라 ORDER BY, DISTINCT, WHERE, LIMIT, LIKE, GROUP BY 등 다양한 절과 함께 사용할 수 있음

### 2. ORDER BY

**ORDER BY** : 쿼리의 결과를 정렬하기

- SELECT 문에 추가하여 결과를 정렬
- ORDER BY 절은 FROM절 뒤에 위치
- 하나 이상의 컬럼을 각각 오름차순, 내림차순으로 정렬할 수 있음
    - `ORDER BY column_1 ASC, column_2 DESC;`
    - ASC : 오름차순 (기본 값)
    - DESC : 내림차순
    - ORDER BY절은 하나 이상의 컬럼을 정렬할 경우 첫번째 열을 사용하여 행을 정렬하고 다음 두번째 컬럼을 사용하여 정렬 되어있는 행을 정렬하는 방식

```
😊 Sorting NULLs

- 정렬 시, SQLite는 NULL을 다른 값보다 작은 것으로 간주
- ASC → 시작 부분에 NULL / DECS → 끝부분에 NULL이 위치하게 될 것임
```

### 3. Filtering data

- 데이터를 필터링하여 중복 제거, 조건 설정 등 쿼리를 제어
- **Cluase** : SELECT DISTINCT, WHERE, LIMIT
- **Operator** : LIKE, IN, BETWEEN
1. **SELECT DISTINCT** clause
    - Remove duplicate rows in the result
    - `SELECT DISTINCT select_list FROM table_name;`
    - SELECT절을 사용할 때 선택적으로 사용하면 됨!
    - DISTINCT 절은 SELECT 키워드 바로 뒤에 나타나야 함
    - DISTINCT 키워드 뒤에 컬럼 또는 컬럼 목록을 작성
- 여러 컬럼을 DISTINCT 에서 선택하면 각 컬럼의 중복을 따로 계산하는 것이 아니라 두 컬럼을 하나의 집합으로 보고 중복을 제거
- SQLite는 NULL값을 중복으로 간주
    - NULL 값이 있는 컬럼에 DISTINCT 절을 사용하면 SQLITE는 NULL값의 한(1) 행을 유지

2. **WHERE** clause
    - Specify the search condition for rows returned by the query
    - WHERE 절은 SELECT 문에서 선택적으로 사용할 수 있는 절
        - SELECT 문 외에도 UPDATE 및 DELETE 문에서도 사용할 수 있음
    - FROM 절 뒤에 작성
    - WHERE 의 검색 조건 작성 형식
        
        `left_expression COMPARISON_OPERATOR right_expression`
        
        - `WHERE column_1 = 10`
        - `WHERE column_2 LIKE 'Ko%'`
        - `WHERE column_3 IN (1,2)`
        - `WHERE column_4 BETWEEN 10 AND 20`
    - Compoarison operators
        - 비교연산자
            - =, <> or !=, < , > , <=, >=
        - 논리연산자
            - 1(TRUE) ,0(FALSE) 또는 NULL 값을 반환
            - ALL, AND, ANY, BETWEEN, IN, LIKE, NOT, OR 등
    - **LIKE** operator
        - 패턴 일치를 기반으로 데이터 조회
        - SELECT, DELETE, UPDATE 문의 WHERE 절에서 사용
        - 기본적으로 대소문자 구분X → `‘A’ LIKE ‘a’` : TRUE
        - SQLite는 패턴 구성을 위한 두개의 와일드카드(wildcards)를 제공
            1. % (percent) : 0개 이상의 문자가 올 수 있음을 의미
                - ‘A%’ : A로 시작하는 모든 문자열과 일치
                - ‘%B’ : B로 끝나는 모든 문자열과 일치
                - ‘%CD%’ : CD를 포함하는 모든 문자열과 일치
            2. _ (underscore) : 단일 문자가 있음을 의미
                - ‘A_’ : A로 시작하고 총 2자리인 문자열과 일치 (AB, AC, AX 등)
                - ‘_B’ : B로 끝나고 총 2자리인 문자열과 일치 (XB, ZB 등)
        
        | 패턴 | 의미 |
        | --- | --- |
        | 2% | 2로 시작하는 패턴 |
        | %2 | 2로 끝나는 패턴 |
        | %2% | 2를 포함하는 패턴 |
        | _2% | 첫번째 자리에 아무 값이 하나 있고 두번째가 2로 시작하는 패턴(최소 2자리) |
        | 1___ | 1로 시작하는 4자리 패턴(반드시 4자리) |
        | 2_%_% ir 2__% | 2로 시작하고 최소 3자리인 패턴(3자리 이상) |

```
😊 Wildcards

- 파일을 지정할 때, 구체적인 이름 대신 여러 파일을 동시에 지정할 목적으로 사용하는 특수 기호!
    - *, ? 등
- 주로 특정한 패턴이 있는 문자열 혹은 파일을 찾거나, 긴 이름을 생략할 때
- 텍스트 값에서 알 수 없는 문자를 사용할 수 있는 특수 문자로, 유사하지만 동일한 데이터가 아닌 여러 항목을 찾기에 매우 편리한 문자
- 지정된 패턴 일치를 기반으로 데이터를 수집하는 데도 도움이 될 수 있음
```

- **IN** operator
    - 값이 값 목록에 있는 값과 일치하는지 확인
    - 표현식이 값 목록의 값과 일치하는지 여부에 따라 true 또는 false를 반환
    - IN 연산자의 결과를 부정하려면 `NOT IN` 연산자를 사용
- **BETWEEN** operator
    
    `test_expression BETWEEN low_expression AND high_expression`
    
    - 값이 값 범위에 있는지 테스트
    - 값이 지정된 범위에 있으면 TRUE 반환
    - SELECT, DELETE, UPDATE 문의 WHERE 절에서 사용
    - BETWEEN 연산자의 결과를 부정하려면 NOT BETWEEN 연산자를 사용

3. **LIMIT** clause
    
    `SELECT column_list FROM table_name LIMIT row_count;`
    
    - 쿼리에서 반환되는 행 수를 제한
    - SELECT 문에서 선택적으로 사용
    - row_count는 반환되는 행 수를 지정하는 양의 정수를 의미
    - **OFFSET** keyword
        - LIMIT 절을 사용하면 첫 번재 데이터부터 지정한 수 만큼의 데이터를 받아올 수 있지만, OFFSET과 함께 사용하면 특정 지정된 위치에서부터 데이터를 조회할 수 있음
        - LIMIT 10 OFFSET 10 → 11번재부터 20번째 데이터의 rowid와 이름 조회하기

4. **GROUP BY** clause
    - 특정 그룹으로 묶인 결과를 생성
    - 선택된 컬럼 값을 기준으로 데이터(행)들의 공통 값을 묶어서 결과로 나타냄
    - SELECT 문에서 선택적으로 사용가능한 절
    - SELECT 문의 FROM 절 뒤에 작성
        - WHERE 절이 포함된 경우 WHERE 절 뒤에 작성해야 함
    - 각 그룹에 대해 MIN, MAX, SUM, COUNT 또는 AVG와 같은 집계 함수(AGGREGATE FUNCTION)를 적용하여 각 그룹에 대한 추가적인 정보를 제공할 수 있음
        - **Aggregate function**
            - 집계함수
            - 값 집합의 최대값, 최소값, 평균, 합계 및 개수를 계산
            - 값 집합에 대한 계산을 수행하고 단일 값을 반환 (여러 행으로부터 하나의 결과 값을 반환하는 함수)
            - 제공하는 함수 목록 : AVG(), COUNT(), MAX(), MIN(), SUM()
            - AVG, MAX, MIN, SUM는 숫자를 기준으로 계산하기 때문에 반드시 컬럼의 데이터 타입이 숫자(INTEGER)일 때만 사용 가능
            - EX) users 테이블의 전체 행 수 조회하기 : `SELECT COUNT(*) FROM users;`
            - EX) 나이가 30살 이상인 사람들의 평균 나이 조회하기 : `SELECT AVG(age) FROM users WHERE age >= 30;`
    
    ```sql
    -- users 테이블에 각 성씨(last_name)가 몇 명씩 있는지 조회하기
    SELECT last_name, COUNT(*) FROM users GROUP BY last_name;
    
    -- AS 키워드를 사용해 컬럼명을 임시로 변경하여 조회
    SELECT last_name, COUNT(*) AS number_of_name FROM users GROUP BY last_name;
    
    -- 인원이 가장 많은 성씨(last_name) 순으로 조회하기
    SELECT last_name, COUNT(*) FROM users GROUP BY last_name ORDER BY COUNT(*) DESC;
    
    -- 각 지역(country)별 평균 나이(AVG(age)) 조회하기
    SELECT country, AVG(age) FROM users GROUP BY country;
    ```
    

### 4. Changing data

- 데이터를 삽입(INSERT), 수정(UPDATE), 삭제(DELETE) → **Statement**

```sql
-- Changing data 실습에 사용할 테이블 classmates
CREATE TABLE classmates(
	name TEXT NOT NULL,
	age INTEGER NOT NULL,
	address TEXT NOT NULL
);
```

1. **INSERT** statement
    
    ```sql
    -- 기본 구조
    INSERT INTO table_name (column1, coulmn2, ...)
    VALUES (value1, value2, ...);
    ```
    
    - 새 행을 테이블에 삽입
    - 문법 규칙
        1. 먼저 INSERT INTO 키워드 뒤에 데이터를 삽입할 테이블의 이름을 지정
        2. 테이블 이름 뒤에 쉼표로 구분된 컬럼 목록을 추가
            - 컬럼 목록은 선택 사항이지만 컬럼 목록을 포함하는 것이 권장됨
        3. VALUES 키워드 뒤에 쉼표로 구분된 값 목록을 추가
            - 만약 컬럼 목록을 생략하는 경우 값 목록의 모든 컬럼에 대한 값을 지정해야 함
            - 값 목록의 값 개수는 컬럼 목록의 컬럼 개수와 같아야 함
    
    ```sql
    -- 단일 행 삽입하기
    INSERT INTO classmates (name, age, address)
    VALUES ('홍길동', 23, '서울');
    
    INSERT INTO classmates
    VALUES (''홍길동', 23, '서울');
    
    -- 여러 행 삽입하기
    INSERT INTO classmates
    VALUES
    	('김철수', 30, '경기'),
    	('이영미', 31, '강원'),
    	('최지수', 26, '서울');
    ```
    

2. **UPDATE** statement
    
    ```sql
    -- 기본 구조
    UPDATE table_name
    SET column_1 = new_value_1,
    		column_2 = new_value_2
    WHERE
    	search_condition;
    ```
    
    - 테이블에 있는 기존 행의 데이터를 업데이트
    - 문법 규칙
        1. UPDATE 절 이후에 업데이트 할 테이블을 지정
        2. SET 절에서 테이블의 각 컬럼에 대해 새 값을 설정
        3. WHERE 절의 조건을 사용하여 업데이트 할 행을 지정
            - WHERE 절은 선택 사항이며, 생략하면 UPDATE 문은 테이블의 모든 행에 있는 데이터를 업데이트
        
        4. 선택적으로 ORDER BY 및 LIMIT 절을 사용하여 업데이트할 행 수를 지정할 수도 있음
        
    
    ```sql
    -- 2번 데이터의 이름과 주소를 수정하기
    UPDATE classmates
    SET name = '김철수영차붐',
    		address = '제주도'
    WHERE rowid = 2;
    ```
    
3. **DELETE** statement
    
    ```sql
    -- 기본구조
    DELETE FROM table_name
    WHERE search_condition;
    ```
    
    - 테이블에서 행을 제거
    - 한 행, 여러 행 및 모든 행을 삭제할 수 있음
    - 문법 규칙
        1. DELETE FROM 키워드 뒤에 행을 제거하려는 테이블의 이름을 지정
        2. WHERE 절에 검색 조건을 추가하여 제거할 행을 식별
            - WHERE 절은 선택 사항이며, 생략하면 DELETE 문은 테이블의 모든 행을 삭제
        3. 선택적으로 ORDER BY 및 LIMIT 절을 사용하여 삭제할 행 수를 지정할 수도 있음
