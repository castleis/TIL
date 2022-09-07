# 개요
- 사용자로부터 HTML form, input 태그를 통해 받는 데이터를 받지만 Django 서버에 들어오는 요청 중에는 비정상적인 or 악의적인 요청이 있을 수 있음.
- 이처럼 사용자가 입력한 데이터가 개발자가 원하는 데이터 형식이 맞는지에 대한 유효성 검증이 반드시 필요
  - 유효성 검정은 많은 부가적인 것들을 고려해서 구현해야 하고, 이는 개발 새앗ㄴ성을 늦출뿐더러 쉽지 않음.
- Form은 Django의 유효성 검사 도구 중 하나로 외부의 악의적 공격 및 데이터 손상에 대한 중요한 방어수단
- Django는 Form에 관련된 작업의 아래 세 부분을 처리해줌
    1. 렌더링을 위한 데이터 준비 및 재구성
    2. 데이터에 대한 HTML forms 생성
    3. 클라이언트로부터 받은 데이터 수신 및 처리

# Django Form Class
## Form Class
- Django form 관리 시스템의 핵심!

### 1. Form Class 선언
- Model 과 마찬가지로 상속을 통해 선언
  - forms 라이브러리의 Form 클래스를 상속받음
  - Model 클래스와 비슷한 이름의 필드 타입을 많이 가지고 있지만 이름만 같을 뿐 같은 필드는 아님
- 앱 폴더에 forms.py를 생성 후 Class 선언
  - `from django import forms`
  - `class 클래스명(forms.Form):` -> forms 라이브러리의 Form 클래스 상속받기!
- Form class를 forms.py에 작성하는 것은 규약은 아니지만 더 나은 유지보수의 관점, 그리고 관행적으로 forms.py 파일 안에 작성하는 것을 권장!
- views.py에 forms 파일에서 생성한 Form 클래스를 import 후, view 함수를 업데이트, 그리고 해당 템플릿도 업데이트 해준다.

### 2. Form Class 사용
- Form fields : 입력에 대한 유효성 검사 로직을 처리, 템플릿에서 직접 사용
  - `forms.CharField()`
  - 이름만 같을 뿐, Model의 field 와는 다름
- **widget** : 웹 페이지의 HTML input 요소 렌더링을 담당(input 요소의 단순한 출력 부분을 담당), 반드시 form fields에 할당 됨.
  - `forms.CharField(widget = forms.Textarea)`
  - CharField input에서 Textarea로 바꿔줌
  - 이외에도 다양한 built-in 위젯이 있고 공식문서에서 찾아볼 수 있음
  - 왜 사용? -> 우리가 지금까지 쓰던 한줄씩 작성하던 방식과는 다르기 때문
    - Form class에서 컨트롤을 해줘야함

### 3. Widgets
- Django의 HTML input element의 표현을 담당
- 단순히 HTML 렌더링 처리, 유효성 검증과 아무런 관계가 없음

# Django ModelForm
- Form class를 작성하면서,, Model class와 겹치는 부분이 많은 것 같다는 생각이 듦
- Model을 통해 form class를 만들 수 있는 helper class
### 1. 선언
  - forms 라이브러리에서 파생된 ModelForm 클래스를 상속받음
  - 정의한 ModelForm 클래스 안에 Meta 클래스 선언 (그저 ModelForm의 설계 방식)  
  - **Meta class**
    - Model form의 정보를 작성하는 곳
    - model 속성으로 참조할 모델을 구성 : `model = 참조할 모델 명`
    - fields 속성으로 모델의 필드를 가져와 구성
      - `__all__` : 사용자가 입력하는, 모델의 모든 필드를 가져옴 (기본값 필드는 가져오지 않음)
      - `exclude` : 사용하지 않을 필드만 제외

### 2. view 함수의 구조 변화 (CRUD)
- HTTP requests 처리에 따른 구조 변화
  
  1. Create
- ```python
    form = '모델명'(request.POST)
    # form 검증!, 검증이 True라면 save, 다음 페이지로 redirect
    if form.is_valid():
        article = form.save()
        return redirect('articles:detail', article.pk)
    return redirect('articles:new')
    ```
    - `forms = 모델명(request.POST)` : POST로 request 받는 모든 데이터를 통째로 넘기기
    - 유효성 검사를 통과하면 데이터 저장 후 상세 페이지로 redirect (detail.html)
      - 통과하지 못하면 작성 페이지로 redirect (new.html)
    - 이전에 하나하나 request 받던 것을 한번에..!

  2. Update
    - ModelForm의 인자 instance는 수정 대상이 되는 객체(기존 객체)를 지정
    - instance : 수정이 되는 대상

## Form 과 ModelForm
- 각자 역할이 다름
- Form
  - 사용자로부터 받는 데이터가 DB와 연관되어 있지 않은 경우에 사용
  - 즉, DB에 영향을 미치지 않고 단순 데이터만 사용되는 경우
  - 예시 : 로그인, 사용자의 데이터를 받아 인증 과정에서만 사용 후 별도로 DB에 저장하지 않음
- ModelForm
  - 사용자로부터 받는 데이터가 DB와 연관되어 있는 경우에 사용
  - 데이터의 유효성 검사가 끝나면 데이터를 각각 어떤 레코드에 맵핑해야 할지 이미 알고 있기 때문에 곧바로 save() 호출 가능

---
### 참고
1. Meta data
  - 데이터를 표현하기 위한 데이터
  - 사진 파일은 사진 데이터를 저장하고 있음. 사진 데이터의 데이터는 촬영시각, 렌즈, 조리개값 등이 포함. 
  - 이러한 사진 데이터에 대한 데이터는 사진의 Meta data


2. 참조 값과 반환 값
  - 호출하지 않고 이름만 작성하는 방식의 의미는?
    - 함수를 호출하지 않고 함수만 **참조**하여 원하는 타이밍에, **필요한 시점에 호출**하기 위함 : `a = Func_A`
    - 함수 자체를 그대로 전달(함수의 참조값을 그대로 넘김)하여 다른 함수에서 필요한 시점에 호출
  - 함수를 호출한다면 반환 값을 받아옴 : `a = Func_A()`
  - 클래스도 마찬가지로 클래스를 호출하지 않고( == 인스턴스를 만들지 않고) 해당 클래스를 필요한 시점에 사용할 수 있음.
  - class Meta에서도 `model = 참조할 모델 명` 으로 model은 인스턴스가 아니라 참조할 모델의 참조값을 받아 해당 클래스의 필드나 속성 등을 내부에서 따로 참조할 수 있다.

3. form 인스턴스의 errors 속성
  - is_valid()의 반환 값이 False인 경우 form 인스턴스의 errors 속성에 값이 작성되는데, 유효성 검증을 실패한 원인이 딕셔너리 형태로 저장
  ```python
    if form.is_valid():
        return redirect()
    context = {
        'form' : form
    }
    return render(request, 'a.html', context)
    ```
  - 다음과 같은 구조로 코드를 작성하면 유효성 검증을 실패 했을 때 사용자에게 실패 결과 메시지 출력 가능

4. {{ forms.as_p }} : 각 필드가 단락 (<p></p> 태그)로 감싸져서 렌더링 -> 줄바꿈

5. save() method
   - form 인스턴스에 바인딩 된 데이터를 통해 데이터베이스 객체를 만들고 저장 후 반환!
   - ModelForm의 하위클래스는 키워드 인자 instance 여부를 통해 생성할지, 수정할지를 결정
     - instance가 제공되지 않은 경우 save()는 지정된 모델의 새 인스턴스를 만듦(Create)
     - 제공되면 save()는 해당 인스턴스를 수정(Update)

6. is_valid() method
   - 유효성 검사를 실행, 데이터가 유효한지 여부를 boolean으로 반환

### Rendering fields manually
- bootstrap을 form에 어떻게 적용?!
  - forms.py 안의 클래스에 적어놓은 각각의 인스턴스 widget의 attr 딕셔너리에 추가!
  - 무엇을 추가해야 하는지는 bootstrap의 공식문서 참고