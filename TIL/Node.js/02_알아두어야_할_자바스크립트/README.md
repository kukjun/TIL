# 02. 알아두어야 할 자바스크립트

## 2.1 ES2015+

ES6라고도 하며 ES5에서 다른 언어들의 장점을 본딴  편리한 기능들이 많이 추가되었다.

<br>

### 2.1.1 const, let

원래 자바스크립트를 배울 때 var로 변수를 선언하는 방법부터 배운다. 하지만 ES6에서는 var을 const, let이 대체한다.

const와 let이 가지는 특징은 **블록스코프**이다.

* var, const 비교 Code

  ![image-20200710141802671](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200710141802671.png)

  x는 정상적으로 출력되는데 y는 에러가 발생한다.

  * var은 함수 스코프를 가지므로 if문의 블록과 관계없이 접근할 수 있다.
  * const, let는 **블록 스코프**를 가지므로 블록 밖에서는 변수에 접근할 수 없다.

#### block scope

블록 밖에서는 블록 안의 변수에 접근할 수 없다.

* 블록의 범위는 중괄호이다.

* 블록 스코프를 사용하므로 인해 호이스팅 같은 문제도 해결되고 코드 관리도 수월해졌다.

##### const

* 기본적인 변수 선언시 사용. 값은 변경할 수 없음
  * 선언하고 초기화하지 않으면 오류발생
* 블록스코프 사용

##### let

* 다른 값을 대입할 수 있음
* 블록스코프 사용

### 2.1.2. templet string

큰따옴표나 작은따옴표로 감싸는 기존 문자열과는 다르게 백틱( ` )으로 감싼다. **문자열 안에 변수를 넣을 수 있다.**

* 기존 문자열 예제

  ```javascript
  var num1 = 1;
  var num2 = 2;
  var result = 3;
  var string1 = num1 + ' 더하기' + num2 + '는 \'' + result + '\'';
  console/log(string1); // 1 더하기 2 는 '3'
  ```

* 템플릿 문자열 예제

  ```javascript
  const num3 = 1;
  const num4 = 2;
  const result2 = 3;
  const string2 = `&{num3} 더하기 ${num4}는 '${result2}'`;
  console.log(string2); // 1더하기 2는 '3'
  ```

### 2.1.3 object literal

객체 리터럴에 편리한 기능들이 추가되었다.

* 기존 문자열 예제

  ```javascript
  var sayNode = function() {
      console.log('Node');
  };
  var es = 'ES';
  var oldObject = {
      sayJS: function() {
          console.log('JS');
      },
      sayNode: sayNode,
  };
  oldObject[es + 6] = 'Fantastic';
  
  oldObject.sayNode(); // Node
  oldObject.sayJS(); // JS
  console.log(oldObject.ES6); // Fantastic
  ```

#### 객체에 동적 속성 추가

* 동적 속성 추가 예제

  ```javascript
  const newObject = {
      sayJS() {
          console.log('JS');
      },
      sayNode,
      [es + 6]: 'Fantastic'
  };
  
  newObject.sayNode(); // Node
  newObject.sayJS(); // JS
  console.log(newObject.ES6) // Fantastic
  ```
  * 객체의 메소드에 함수를 연결할 때 콜론을 붙이지 않아도 된다.

  * 속성명과 변수명이 겹치는 경우  한번만 쓸 수 있다.

    ```javascript
    { name : name, age : age} // ESS
    { name , age } // ES2015
    ```

  * 객체의 속성명을 동적으로 생성할 수 있다.

    * ES5에서는 ES6라는 속성명을 만들려면 객체 리터럴 밖에서 [ es + 6 ]를 해야 했었다.
    * ES2015 문법에서는 객체 리터럴 안에 선언해도 된다.

객체 리터럴에 추가된 문법은 코딩 시 편의를 위해 만들어진 것이라는 느낌이 강하다. **익숙해지면 코드를 줄일 수 있다.**

### 2.1.4 화살표 함수

화살표 함수(arrow function)라는 새로운 함수가 추가되었으며, 기존의 function() {}도 사용 가능하다.

* 예제

  ```javascript
  function add1(x, y) {
      return x + y;
  }
  
  const add2 = (x, y) => {
      return x + y;
  };
  
  const add3 = (x, y) => x + y;
  
  const add4 = (x, y) => (x + y);
  
  function not1(x) {
      return !x;
  }
  
  const not2 = x => !x;
  ```

기존의 function과 다른 점은 **this 바인드 방식**이다.

* 예제

  ```javascript
  var relationship1 = {
      name: 'zero',
      friends: ['nero', 'hero', 'xero'],
      logFriends: function() {
          var that = this; // relationship1을 가리키는 this를 that에 저장
          this.friends.forEach(function(friend) {
              console.log(that.name, friend);
          });
      },
  };
  relationship1.logFriends();
  
  const relationship2 = {
      name: 'zero',
      friends: ['nero', 'hero', 'xero'],
      logFriends() {
          this.friends.forEach( friend => {
              console.log(this.name, friend);
          });
      },
  };
  relationship2.logFriends();
  ```


### 2.1.5 비구조화 할당



### 2.1.6 프로미스



### 2.1.7 async/await



## 2.2 프런트엔드 자바스크립트

### 2.2.1 AJAX

### 2.2.2 FormData

### 2.2.3 encodeURIComponent, decodeURIComonent

### 2.2.4 data attribute와 dataset