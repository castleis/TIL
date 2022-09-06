# View decorators
- Decorator
  - 기존에 작성된 함수에 기능을 추가하고 싶을 때, 해당 함수를 수정하지 않고 기능을 추가해주는 **함수**
  - Django는 다양한 HTTP 기능을 지원하기 위해 view함수에 적용할 수 있는 여러 데코레이터를 제공
    - required_safe,

## Allowed HTTP methods
- django.views.decorators.http의 데코레이터를 사용하여 요청 메서드를 기반으로 접근을 제한
- 일치하지 않는 메서드 요청이라면 405 Method Not Allowed를 반환
- require_http_methods() : View 함수가 특정한 요청 method만 허용하도록 하는 데코레이터
- require_POST() : View 함수가 POST 요청 method만 허용하도록 하는 데코레이터
- require_safe() : require_GET이 있지만 Django에서는 require_safe를 사용하는 것을 권장