# Model
웹 애플리케이션의 데이터를 구조화하고 조작하기 위한 추상적인 계층

## Database

- 체계화된 데이터의 모임
- 검색 및 구조화 같은 작업을 보다 쉽게 하기 위해 조직화된 데이터를 수집하는 저장 시스템
- 기본 구조
    1. 스키마(Schema)
    - 뼈대 (Structure)
    - 데이터베이스에서 자료의 구조, 표현 방법, 관계 등을 정의한 구조
    - 예를들어 column - datatype 나타내줌
    2. 테이블
    - 필드와 레코드를 사용해 조직된 데이터 요소들의 집합
    - 관계(Relation)라고도 부름
    - 필드(field) - 속성, 열(컬럼,column)
        - 각 필드에는 고유한 데이터 형식이 지정됨 (int, text 등)
    - record - 튜플, 행(row)
        - 실제 데이터.
        - 테이블의 데이터는 레코드에 저장됨
    - PK (Primary Key)
        - 기본 키
        - 각 레코드의 고유한 값(식별자로 사용)
        - 기술적으로 **다른 항목과 절대로 중복될 수 없는 단일 값(unique)**
        - 데이터베이스 관리 및 테이블 간 관계 설정 시 주요하게 활용 됨
___
## Model

- 사용자가 저장하는 데이터들의 필수적인 필드들과 동작들을 포함
- 저장된 데이터베이스의 구조 (layout). 데이터베이스 자체가 아니라 데이터베이스와 상호작용하면서 필요한 데이터들을 받아오는..?
- 일반적으로 각각의 모델은 하나의 데이터베이스 테이블에 매핑(mapping)
    - 모델 클래스 1개 == 데이터베이스 테이블 1개
- 모델 클래스를 작성하는 것은 데이터베이스 테이블의 스키마를 정의하는 것
    - 모델 클래스 == 테이블 스키마

### Model 이해하기

- 각 모델은 django.models.Model 클래스의 서브 클래스로 표현
    - 각 모델은 django.db.models 모듈의 Model 클래스를 상속받아 구성됨
- models 모듈을 통해 어떠한 타입의 DB 필드(컬럼)을 정의할 것인지 정의
- Django Model Field
    - Django는 모델 필드를 통해 테이블의 필드(컬럼)에 저장할 데이터 유형(INT, TEXT 등)을 정의
    - 데이터 유형에 따라 다양한 모델 필드를 제공
        - DataField(), CharField(), IntegerField() 등
___

## Migrations

- Django가 모델에 생긴 변화(필드 추가, 수정 등)를 실제 DB에 반영하는 방법
- 설계도를 만들고(makemigrations), 설계도를 기반으로 DB와 동기화(migrate)
- 주요 명령어
    1. **makemigrations**
    - `python [manage.py](http://manage.py) makemigrations`
    - migrations 폴더 안에 마이그레이션 파일이 생성됨.
    - 아직 DB에 테이블이 생긴 것은 아님.
    - 마이그레이션 파일은 파이썬으로 작성된 설계도, 청사진을 나타내는 것 뿐, 데이터베이스와 상호작용은 아직 없다.
    - 마이그레이션 파일 특 : 파일 명이 000# 으로 시작
    2. **migrate**
    - makemigrations로 만든 설계도를 실제 데이터베이스에 반영하는 과정 (db.sqlite3 파일에 반영)
    - 결과적으로 **모델의 변경사항과 데이터 베이스를 동기화**
    - `python [manage.py](http://manage.py) migrate`
    - 첫 migrate 할 때는 장고에 기본적으로 내장되어있는 앱의 설계도도 함께 migrate되기 때문에 여러 항목이 주르르르륵 나온당
- db.sqlite3 이 데이터 베이스, 처음에는 비워져 있지만 migrate 할 때 비로소 채워진다.
    - db.sqlite3 마우스 우클릭
    - Open Database
    - 왼쪽 하단에 SQLITE EXPLORER 눌러주면
    - 그 안에 db.sqlite3 이 있고 그 안에 테이블들이 저장되어 있다.
    - `앱이름_클래스이름` 으로 저장되어 있음
    - id, title, content 등 스키마가 저장되어 있는 것을 볼 수 있다.
    - 이름 옆에 오른쪽 화살표 누르면 테이블 확인할 수 있음.
- 기타 명령어
    1. showmigrations
    - `python [manage.py](http://manage.py) showmigrations`
    - migrations 파일들이 migrate 됐는지 여부를 확인하는 용도
    - [X] 표시가 있으면 migrate가 완료되었음을 의미
    2. sqlmigrate
    - `python [manage.py](http://manage.py) sqlmigrate articles 0001`
    - 해당 migrations 파일이 SQL문으로 어떻게 해석될지 미리 확인할 수 있음
> 반드시 기억해야 할 migration 3단계
>   1. models.py에서 변경사항이 발생하면
>   2. migration 생성 (설계도 생성) : `makemigrations`
>   3. DB 반영 (Model 과 DB의 동기화) : `migrate`

### Model 변경사항 반영하기

1. 추가 모델 필드 작성 후 다시 한번 makemigrations 진행
    - 내부적으로는 내부에 이미 존재하는 컬럼들을 복사해뒀다가 추가된 컬럼만큼의 크기에 다시 붙여넣기를 한다.
    - 이 때 데이터가 공백이라면 데이터베이스에 추가하는 것이 불가능하기 때문에 기본값(default)이 필요
2. DB와 동기화 migrate
- migrations 파일을 새로 갱신하지 않고 쌓아나가는 이유
    - git을 커밋할 때, 변경사항을 저장해나는 것처럼 버전을 기록해두고 문제가 생겼을 시 돌아가 쉽게 수정할 수 있도록 하기 위함
- DateTimeField()
    - Python의 datetime.datetime 인스턴스로 표시되는 날짜 및 시간을 값으로 사용하는 필드
    - DateField를 상속받는 클래스
    - 선택 인자
        1. auto_now_add
            - 최초 생성 일자 (Useful for creation of timestamps)
            - Django ORM이 최초 insert(테이블에 데이터 입력) 시에만 현재 날짜와 시간으로 갱신 (테이블에 어떤 값을 최초로 넣을 때)
        2. auto_now
            - 최종 수정 일자 (Useful for “last-modified” timestamps)
            - Django ORM이 save를 할 때마다 현재 날짜와 시간으로 갱신

---
# ORM

- 설계도는 어떻게, 누가 해석할까?
    - 장고(Python) — migrate →  DB(SQL만 알아들음)
    - 이 과정에서 중간에 번역을 담당하는 것이 ORM!
- **O**bject - **R**elational - **M**apping
- 객체 지향 프로그래밍 언어를 사용하여 호환되지 않는 유형의 시스템 간(Django ↔ DB)에 데이터를 변환하는 프로그래밍 기술
- Django 는 내장 Django ORM을 사용
- 한마디로 SQl을 사용하지 않고도
- 사용 이유 : **생산성!**
    - DB를 객체(Object)로 바로 조작 가능
- 장점
    - 객체지향 언어로 DB 조작이 가능
    - 객체 지향적 접근으로 인한 높은 생산성
- 단점
    - ORM 만으로 완전한 서비스를 구현하기 어려운 경우가 있음

---
# QuerySet API

- QuerySet과 상호작용하기 위해 사용하는 도구
    - 메서드, 연산자 등

### **Database API**
- Model을 만들면 Django는 객체들을 만들고 읽고 수정하고 지울 수 있는 DB API를 자동으로 만듦
- Model class . Manager . Queryset API
- objects manager
    - Django 모델이 데이터베이스 쿼리 작업을 가능하게 하는 인터페이스
    - 이 Manager(objects)를 통해 특정 데이터를 조작(메서드)할 수 있음
    - **“DB를 Python class로 조작할 수 있도록 여러 메서드를 제공하는 manager”**

### **Query**
- 데이터베이스에 특정한 데이터를 보여 달라는 요청
- 쿼리문을 작성한다 → 원하는 데이터를 얻기 위해 데이터베이스에 요청을 보낼 코드를 작성한다
- 이 때, 파이썬으로 작성한 코드가 ORM에 의해 SQL로 변환되어 데이터베이스에 전달되며 데이터베이스의 응답 데이터를 ORM이 **QuerySet** 이라는 자료 형태로 변환하여 우리에게 전달

### **QuerySet**
- 데이터베이스에게서 전달 받은 객체 목록(데이터 모음)
    - 순회가 가능한 데이터로써 1개 이상의 데이터를 불러와 사용할 수 있음
- Django ORM을 통해 만들어진 자료형이며, 필터를 걸거나 정렬 등을 수행할 수 있음
- “objects” manager를 사용하여 복수의 데이터를 가져오는 **queryset method를 사용할 때 반환되는 객체**
    - 단, 데이터베이스가 단일한 객체를 반환할 때는 QuerySet이 아닌 모델(Class)의 인스턴스로 반환됨
---

# CRUD 
- Create / Read / Update / Delete
- 기본적인 데이터 처리 기능 4가지를 묶어서 일컫는 말

### 1. Create

1. 첫번째 방법
    1. 클래스를 통한 인스턴스 생성
        - `article = Article()`
    2. 클래스 변수명과 같은 이름의 인스턴스 변수를 생성 후 값 할당
        - `article.title =`
    3. 인스턴스로 save 메서드 호출
        - `article.save()`
2. **두번째 방법**
    1. 인스턴스 생성 시 초기 값을 함께 작성하여 생성
        - `article = Article(title=' ', content=' ')`
    2. 인스턴스로 save 메서드 호출
        - `article.save()`
3. 세번째 방법
    1. QuerySet API 중 create() 메서드 활용
    - 위 2가지 방식과는 다르게 바로 생성된 데이터가 반환된다
- `.save()`
    - 객체를 데이터베이스에 저장
    - 데이터 생성 시 save를 호출하기 전에는  객체의 id 값은 None
        - id 값은 Django가 아니라 데이터베이스에서 계산되기 때문
    - 단순히 모델 클래스를 통해 인스턴스를 생성하는 것은 DB에 영향을 미치지 않음. 
    → **반드시 save를 호출**해야 테이블에 레코드가 생성됨
    
    데이터 베이스에 저장되는 시간은 무조건 UTC이고, settings.py에서 시간을 한국으로 바꾼 것은, 읽ㅇ르 때 한국 시간으로 바꿔서 읽는다는 뜻
    
- redirect() 동작 이해하기
    - 인자에 작성된 곳으로 요청을 보냄
    - 사용 가능한 인자
        1. view name (URL pattern name) : `return redirect('articles:index')`
        2. absolute or relative URL  : `return redirect('/articles/')`

### 2. Read

- QuerySet API method는 크게 2가지로 분류
    - 데이터의 목록을 받느냐(**return new querysets**),
    - 하나를 받느냐(**do not return querysets**)
- `.all()`
    - QuerySet return
    - 전체 데이터 조회
- `get()`
    - 단일 데이터 조회
    - 객체를 찾을 수 없으면 예외, 둘 이상의 객체를 찾으면 예외
        
        → PK와 같이 고유성을 보장하는 조회에서 사용해야 함! ( PK는 get으로만 접근 )
        
- `filter()`
    - 지정된 조회 매개 변수와 일치하는 객체를 포함하는 새 **QuerySet**을 반환
    - 없어도 빈 쿼리셋을 반환, 하나만 있어도 쿼리셋으로 반환!!
    - 하지만 pk를 조회할 때는 사용하지 않는다.
        
        →   1. 쿼리셋으로 반환하기 때문 (한번 더 접근해야 함)
        
        1. 없을 때도 빈 쿼리셋을 반환하기 때문에 적절하지 않음
- `Field lookups`
    - 특정 레코드에 대한 조건을 설정하는 방법
    - QuerySet 메서드인 filter(), exclude() 및 get()에 대한 키워드 인자로 지정됨
    - 다양한 built-in lookups는 공식문서 참고
    - content 컬럼에 ‘dj’가 포함된 모든 데이터 조회
        → `Article.objects.filter(content**__contains**=’dj’)`

### 3. Update

- Update 단계 
1. 수정하려는 article 인스턴스 객체를 조회 후 반환값을 저장
2. article 인스턴스 객체의 인스턴스 변수 값을 새로운 값으로 할당 (수정)
3. save() 인스턴스 메서드 호출

### 4. Delete

1. 삭제하고자 하는 article 인스턴스 객체를 조회 후 반환값을 저장
2. delete() 인스턴스 메서드 호출
- 삭제하고 난 후에는 그 자리가 다시 채워지는 것이 아님. 재사용하지 않음
- id=1 을 삭제한 후 다시 데이터를 추가하면 id=4 에 저장됨