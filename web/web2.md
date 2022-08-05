# Flexbox
- 레이아웃 배치 전용 기능.
- flex 레이아웃을 만들기 위한 기본적인 html구조
```html
<div class="container">
    <div class="item">helloflex</div>
    <div class="item">abc</div>
    <div class="item">helloflex</div>
</div>
```
- 부모 요소인 div.container를 플렉스 컨테이너라고 부르고 자식 요소인 div.item들을 플렉스 아이템이라 부름.
- 컨테이너가 Flex의 영향을 받는 전체 공간이고 설정된 속성에 따라 각각의 아이템들이 어떤 형태로 배치되는 것
<br>

### Flex의 속성 
1. 컨테이너에 적용하는 속성
```html
.container{
    display : flex;
    flex-direction : row; /* column, row-reverse, column-reverse */
    flex-wrap : nowrap;   /* wrap, wrap-reverse */
}
```
- flex 아이템들은 가로방향으로 배치되고 자신이 가진 내용물의 width 만큼만 차지
- height는 컨테이너의 높이만큼 늘어남 -> 컬럼(column)의 높이가 자동으로 쫙~ 맞는다!
- inline-flex : 컨테이너가 주변 요소들과 어떻게 어우러질지 결정하는 값, inline-block처럼 동작
- 아이템들이 배치된 방향의 축을 Main Axis, 수직인 축을 Cross Axis
- flex-direction : 아이템들이 배치되는 축의 방향을 결정하는 속성
- flex-wrap : 컨테이너가 더이상 아이템들을 한 줄에 담을 여유공간이 없을 때 아이템 줄바꿈을 어떻게 할지 결정하는 속성
  - nowrap : 기본값, 줄바꿈 X, 넘치면 밖으로 빠짐
  - wrap : 줄바꿈 O , -reverse는 역순으로 배치
- flex-flow : direction과 wrap을 한꺼번에 지정할 수 있는 단축 속성
  - direction, wrap 순으로 한칸 떼고 써주면 됨.

### 정렬
- justify : 메인축 방향으로 정렬
- align : 수직축 방향으로 정렬

- justify-content : 메인축 방향으로 아이템들을 정렬하는 속성
  - : flex-start; / end; 
  - : center;
  - : space-between; / around; / evenly; 
- align-items : 수직축 방향으로 아이템들을 정렬하는 속성
  - : stretch; (기본값) 아이템들이 수직축 방향으로 끝까지 쭈욱 늘어남
  - : flex-start; / end;
  - : center;
  - : baseline; 아이템들을 텍스트 베이스라인 기준으로 정렬
- align-content : `flex-wrap:warp;` 이 설정된 상태에서 아이템들의 행이 2줄 이상 되었을 때 수직축 방향 정렬을 결정하는 속성


1. 아이템에 적용하는 속성

수직 수평 가운데 정렬 방법
display : flex;
align-content : center;
justify-content(메인 축에 수평 방향) -> 메인 축을 따라 움직임
align-items(메인 축에 수직 방향) -> 메인 축의 수직으로 움직임
메인 축은 flex-direction으로 바꿀 수 있음