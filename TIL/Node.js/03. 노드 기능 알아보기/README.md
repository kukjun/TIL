# 03. 노드 기능 알아보기

> 노드와 처음 상호작용을 해보고, 노드로 자바스크립트 파일을 실행하는 방법을 알아본다.

> 노드가 기본적으로 제공하는 객체와 모듈 사용법에 대해서도 알아본다.

> 모듈을 사용하면서 중요한 개념인 버퍼와 스트림, 동기와 비동기, 이벤트, 예외 처리에 대해서 배운다.

## 3.1 REPL 사용하기

> 입력한 코드를 읽고(**R**ead), 해석하고(**E**val), 결과물을 반환하고(**P**rint), 종료할 때까지 반복(**L**oop)한다고 해서 **REPL**(Read Eval Print Loop)라고 부른다.

![This is why your read-eval-print-loop is so amazing](https://cdn-media-1.freecodecamp.org/images/1*wOeV-wURvl_DeuBPreGGcg.jpeg)

자바스크립트는 스크립트 언어이므로 컴파일을 하지 않아도 즉석에서 코드를 실행할 수 있다.

* 노드도 비슷한 콘솔을 제공한다.
  * 명령 프롬프트에서 node 입력

<br>

REPL은 한두 줄짜리 코드를 테스트해보는 용도로는 좋지만 여러 줄의 코드를 실행하기에는 불편하다.
긴 코드는 자바스크립트 파일로 만든 후, 파일을 통째로 실행하는 것이 좋다.

## 3.2 JS 파일 실행하기

> 자바스크립트 파일을 만들어 명령 프롬프트로 실행시킬 수 있다.

* Syntax

  ```
  node [자바스크립트 파일 경로]
  ```

## 3.3 모듈로 만들기

> 노드는 코드를 모듈로 만들 수 있다는 점에서 브라우저의 자바스크립트와는 다르다.

**모듈**이란 특정한 기능을 하는 함수나 변수들의 집합이다.

* 자체로도 하나의 프로그램이면서 다른 프로그램의 부품으로도 사용할 수 있다.

* 보통 파일 하나가 모듈 하나가 된다. 파일별로 코드를 모듈화 할 수 있어 관리가 편리하다.

![img](https://thebook.io/img/006982/078.jpg)

### 모듈 예제

* var.js

  ```javascript
  const odd = '홀수입니다.';
  const even = '짝수입니다.';
  
  module.exports = { // 파일을 모듈로서 사용함. var.js
      odd,
      even,
  };
  ```

* func.js

  ```javascript
  const { odd, even } = require('./var'); // require 함수를 통해서 동일 경로의 var.js를 모듈로 사용
  
  function checkOddOrEven(num) { // 홀짝을 판별하는 함수.
      if (num % 2) { // 홀수이면
          return odd;
      }
      return even;
  }
  
  module.exports = checkOddOrEven; // var.js 모듈을 사용하는 파일을 다시 함수모듈로 만듬. func.js
  // 모듈은 객체뿐 아니라 함수나 변수도 가능
  ```

  * require 함수의 인자로 제공하는 경로를 지정하면 다른 파일을 모듈로 사용할 수 있다.

* index.js

  ```javascript
  const { odd, even } = require('./var'); // require 함수를 통해서 동일 경로의 var.js를 모듈로 사용
  const checkNumber = require('./func'); // require 함수를 통해서 동일 경로의 func.js를 모듈로 사용
  
  function checkStringOddOrEven(str) {
      if (str.length % 2) { // 홀수면
          return odd;
      }
      return even;
  }
  
  console.log(checkNumber(10));
  console.log(checkStringOddOrEven('hello'));
  ```

  