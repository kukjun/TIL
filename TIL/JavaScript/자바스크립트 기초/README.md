## 변수와 상수

### 변수

변수(variable)는 데이터를 저장할 때 쓰이는 '이름이 붙은 저장소'이다.
JavaScript에서는 `let` 키워드를 사용해 변수를 저장한다.

* var

  만들어진 지 오래된 스크립트에서는 `let` 대신에 `var`이 발견된다. 유사하지만 차이점이 있다.

C언어와 다르게 자료형을 따로 정의하지 않아 **어떤 값이든 넣을 수 있고 원하는 만큼 변경할 수 있다.**

* 변수를 복사할 수 있다.

  ```javascript
  let Hello = 'Hello world';
  let message;
  
  message = Hello; //변수 message에 Hello값이 복사된다.
  ```
