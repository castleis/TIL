# Namespace

- 개체를 구분할 수 있는 범위
### URL namespace
  - `app_name = ‘어플리케이션 이름’` → 각 어플리케이션 [url.py](http://url.py) 파일의 urlpatterns 바로 위에 app_name을 명시해두기
  - `{% url '앱이름 : 가야할 곳'%}` → URL 태그도 변경! app_name을 지정(?)하고 나서는 이렇게 사용하지 않으면 에러가 뜨기 때문에 모두모두 바꿔줘야 함
  - NoReverseMatch : URL 태그에서 에러! url 태그만 확인해보면 된다
  
### Template namespace

- articles/templates/ 와 pages/templates/
  - 장고는 templates 이후부터 읽고 있음
  - 따라서 장고는 articles/templates/index.html, pages/templates/index.html을 구분할 수 없다 
  - 그래서 앱의 등록순서에 따라 먼저 등록된 앱의 파일을 응답해준다
  - 현재 상황에서는 settings.py에 articles먼저 등록했기 때문에 pages의 index.html을 요청해도 articles의 index.html이 반환되는 것
  → 해결하기 위해서는 app/templates/새로운 폴더/index.html 새로운 폴더를 만드는 방법 밖에 없다 (새로운 이름공간 만들기)

- `app_name/templates/app_name`
  - articles/templates/index.html → articles/templates/articles/index.html
  - pages/templates/index.html → pages/templates/pages/index.html

- URL namespace와 Templates namespace를 모두 해결해줘야 정상적으로 작동.