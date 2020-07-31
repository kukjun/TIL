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


이처럼 모듈을 만들어두면 편리하다.
하지만 모듈이 너무 많아 관계가 얽히게 되면 구조를 파악하기가 힘들다.

**노드에서는 대부분의 파일이 다른 파일을 모듈로 사용하고 있으므로 모듈을 만들고 사용하는 방법을 꼭 알아두어야 한다.**

* EX2015 모듈(func.mjs)

  ```javascript
  import { odd, even } from './var';
  
  function checkOddOrEven(num) {
      if (num % 2) { // 홀수면
          return odd;
      }
      return even;
  }
  
  export default checkOddOrEven;
  ```

  * 노드에서도 9버전부터 2015 모듈시스템을 사용할 수 있다.
    * 확장자를 mjs로 지정해야하고 실행 시 node --experimental -modules [ 파일명 ]처럼 옵션을 붙어줘야 한다.

## 3.4 노드 내장 객체 알아보기

노드에서는 기본적인 내장 객체와 내장 모듈(3.5절)을 제공한다. 그래서 따로 설치하지 않아도 바로 사용할 수 있다.

### global

브라우저의 window와 같은 전역 객체이다. 전역 객체이므로 모든 파일에서 접근할 수 있다.

global 객체의 메서드는 global을 생략할 수 있다.

* ```javascript
  require // global.require
  console // global.console
  ```

노드는 DCM이나 BOM이 없어서 window,  document 객체를 사용할 수 없다.

#### gobal 예제

* globalA.js

  ```javascript
  module.exports = () => global.message;
  ```

* globalB.js

  ```javascript
  const A = require('./globalA');
  
  global.message = '안녕하세요.';
  console.log(A());
  ```

**B에서 선언한 global.message값을 globalA에서도 접근할 수 있다.**

* 프로그램의 규모가 커질수록 어떤 파일에서 global 객체에 값을 대입했는지 찾기 힘들어 유지보수에 어려움을 겪게 되므로 이를 남용하지 않도록 한다.

### console

브라우저의 console과 거의 비슷하다.

console 객체는 보통 **디버깅을 위해 사용**된다. 개발 중 변수에 값이 제대로 들어 있나 확인하기 위해 사용하기도 하고, 에러 발생 시 에러 내용을 콘솔에 표시하기 위해 사용하가도 하며, 코드 실행시간을 알아보려고도 사용한다.

#### console 로깅 함수 예제

* console.js

  ```javascript
  const string = 'abc'
  const number = 1;
  const boolean = true;
  const obj = {
      outside: {
          inside: {
              key: 'value',
          },
      },
  };
  
  console.time('전체 시간');
  console.log('평범한 로그입니다. 쉼표로 구분해 여러 값을 찍을 수 있습니다.');
  console.log(string, number, boolean);
  console.error('에러 메시지는 console.error에 담아주세요');
  
  console.dir(obj, { colors: false, depth: 2 });
  console.dir(obj, { colors: true, depth: 1});
  
  console.time('시간 측정');
  for (let i = 0; i < 100000; i++) {
      continue;
  }
  console.timeEnd('시간 측정');
  
  function b() {
      console.trace('에러 위치 추적');
  }
  
  function a() {
      b();
  }
  
  a();
  
  console.timeEnd('전체 시간');
  ```

  * console.time(레이블)
    : console.timeEnd(레이블)과 대응되어 같은 레이블을 가진 time과 timeEnd 사이의 시간을 측정한다.
  * console.log(내용)
    : 평범한 로그를 콘솔에 표시합니다. console.log(내용, 내용, ...)처럼 여러 내용을 동시에 표시할 수 있다.
  * console.error(에러 내용)
    : 에러를 콘솔에 표시한다.
  * console.dir(객체, 옵션)
    : 객체를 콘솔에 표시할때 사용한다. 첫 번째 인자로 표시할 객체, 두 번째 인자로 옵션을 넣는다.
    * 옵션의 colors를 true로 설정하면 코놋ㄹ에 색이 추가되어 보기 편하다.
    * 옵션의 depth는 객체 안의 객체를 몇 단계까지 보여줄지를 결정한다. (기본값 2)
  * console.trace(레이블)
    : 에러가 어디에서 발생했는지 추적할 수 있게 해준다.
    * 에러의 위치가 나오지 않을 경우 사용한다.

### Timer

타이머 기능을 제공하는 함수인 setTimeout, setInterval, setImmediate는 노드에서 global  객체 안에 들어있다.

* setTimeout(콜백 함수, 밀리초)
  : 주어진 밀리초 이후에 콜백 함수를 실행함.
* setInterval(콜백 함수, 밀리초)
  : 주어진 밀리초마다 콜백 함수를 반복 실행함.
* setImmediate(콜백 함수)
  : 콜백함수를 즉시 실행함.

이 타이머들은 아이디를 반환한다. **아이디를 사용해 타이머를 취소할 수 있다.**

* clearTimeout(아이디)
  : setTimeout을 취소함.
* clearInterval(아이디)
  : setInterval을 취소함.
* clearImmediate(아이디)
  : setImmediate를 취소함.

#### Timer 예제

* timer.js

  ```javascript
  const timeout = setTimeout(() => { // 함수를 일단 실행함!
      console.log('1.5초 이후에 실행');
  }, 1500);
  
  const interval = setInterval(() => {
      console.log('1초마다 실행');
  }, 1000);
  
  const timeout2 = setTimeout(() => {
      console.log('실행되지 않습니다.');
  }, 3000);
  
  setTimeout(() => {
      clearTimeout(timeout2);
      clearInterval(interval);
  }, 2500);
  
  const immediate = setImmediate(() => {
      console.log('즉시 실행');
  });
  
  const immediate2 = setImmediate(() => {
      console.log('실행되지 않습니다.');
  });
  
  clearImmediate(immediate2);
  ```

setImmediate(콜백)과 setTimeout(콜백, 0)은 같지 않다.

* 항상 setImmediate가 먼저 실행되는 것도 아니므로 setTimeout(콜백, 0)은 사용하지 않는편을 권장함.
  * 추가내용 필요

### _ _filename, _ _dirname

노드에서는 파일 사이에 모듈 관계가 있는 경우가 많아 현재 파일의 경로나 파일명을 알아야하는 경우가 있다.
_\_filename, \_\_dirname 키워드로 경로에 대한 정보를 제공한다.

#### filename, dirname 예제

* filename.js

  ```javascript
  console.log(__filename); // 파일의 경로
  console.log(__dirname); // 파일의 디렉토리 경로
  ```

  * 경로 처리를 할 수 있으나, /, \\, 문자열 등이 있으므로 path 모듈과 함께 쓴다.

<br>

### module, exports

mudule.export 말고 export 객체로도 모듈을 만들 수 있다.

* var.js

  ```javascript
  exports.odd = '홀수입니다.';
  exports.even = '짝수입니다.';
  ```

mudule.exports와 exports가 같은 객체를 참조하기 때문에 가능하다.

* export 객체 사용 시에 참조 관계가 깨지지 않도록 주의해야 한다.
  module.exports에는 어떤 값이든 대입해도 되지만 exports에는 반드시 객체처럼 속성명과 속성값을 대입해야 한다.
  * 객체가 아닌 다른 값을 넣으면 참조관계가 끊겨 모듈로서 기능하지 않는다.
    * 함수의 경우 exports를 사용할 수 없다.
      * 키, 값의 형태로 사용 가능하다.
  * 한 모듈에서 두가지 형태를 모두 쓰지 않는다.

### process

> process 객체는 현재 실행되고 있는 노드 프로세스에 대한 정보를 담고 있다.

* process REPL 입력

```javascript
process.version // 설치된 노드의 버전 찾기
process.arch // 프로세서 아키텍처 정보
process.platfrom // 운영체제 플랫폼 정보
process.pid // 현재 프로세스 아이디. 여러 개 가질 수 있음.
process.uptime() // 프로세스가 시작된 후 흐른 시간
process.execPath // 노드의 경로
process.cwd() // 현재 프로세스 실행 위치
process.cpuUsage() // 현재 CPU 사용량
```

#### process.env

REPL에 process.env를 입력하면 시스템의 환경 변수를 출력한다.

process.env는 서비스의 중요한 키를 저장하는 공간으로 사용.

* 서버나 데이터베이스의 비밀번호와 각종 API 키를 코드에 직접 입력하는 것은 서비스가 해킹당해 코드가 유출되었을 때, 비밀번호가 코드에 남아있어 추가 피해가 발생할 수 있다.

* 중요한 비밀번호는 process.env의 속성으로 대체한다.

  ```javascript
  const sercetID = process.env.SECRET_ID;
  const secretCode = process.env.SECRET_CODE;
  ```

  * process.env에 직접 넣어주면 된다. dotenv 사용 ( 9장 참조 )

#### process.nextTick(콜백)

이벤트 루프가 다른 콜백 함수들보다 nextTick의 콜백 함수를 우선으로 처리하도록 만든다.

* nextTick.js

  ```javascript
  setImmediate(() => {
      console.log('immediate');
  });
  
  process.nextTick(() => {
      console.log('nextTick'); // 다른 콜백들보다 우선시된다.
  });
  setTimeout(() => {
      console.log('timeout');
  }, 0);
  Promise.resolve().then(() => console.log('promise')); // resolve된 promise도  nextTick처럼 다른 콜백들보다 우선시된다.
  ```

  * promise.nextTick과 Promise를 마이크로태스크라고 따로 구분지어 부른다.
    * 마이크로태스크 큐가 태스크 큐보다 더 먼저 실행된다.
    * 이러한 마이크로태스크를 재귀 호출하게 되면 이벤트 루프는 마이크로태스크를 우선하여 처리하므로 콜백함수들이 실행되지 않을 수 있다.

![img](https://thebook.io/img/006982/091.jpg)

#### process.exit(코드)

실행 중인 노드 프로세스를 종료한다.

서버에 사용하면 서버가 멈추므로 사용하지 않는다.
하지만 서버 외의 독립적인 프로그램에서는 수동으로 노드를 멈추게 하기 위해 사용한다.

* exit.js

  ```javascript
  let i = 1;
  setInterval(() => { // 반복하는 함수 실행
      if (i == 5) {
          console.log('종료!');
          process.exit(); // 프로세스 종료
      }
      console.log(i);
      i += 1;
  }, 1000); // 1초마다 반복
  ```

  * process.exit의 인자가 0이나 없는 경우 정상종료이고 1을 주면 비정상 종료이다.

## 3.5 노드 내장 모듈 사용하기

노드는 웹 브라우저에서 사용되는 자바스크립트보다 더 많은 기능을 제공한다.

운영체제 정보에도 접근할 수 있고, 클라이언트가 요청한 주소에 대한 정보도 가져올 수 있다. 바로 노드에서 제공하는 모듈을 사용하면 된다.

### os

노드는 os 모듈에 정보가 담겨 있어 정보를 가져올 수 있다.

**os 모듈의 대표적인 메서드는 다음과 같다.**

* os.js

  ```javascript
  const os = require('os');
  
  console.log('운영체제 정보--------------------------------------');
  console.log('os.arch():', os.arch()); // process
  console.log('os.platform():', os.platform);
  console.log('os.type():', os.type());
  console.log('os.uptime():', os.uptime());
  console.log('os.hostname():', os.hostname());
  console.log('os.release():', os.release());
  
  console.log('경로-----------------------------------');
  console.log('os.homedir():', os.homedir());
  console.log('os.tmpdir():', os.tmpdir());
  
  console.log('cpu 정보------------------------------------');
  console.log('os.cpus():', os.cpus());
  console.log('os.cpus().length:', os.cpus().length);
  
  console.log('메모리 정보---------------------------------');
  console.log('os.freemem():', os.freemem());
  console.log('os.totalmem():', os.totalmem());
  ```

* 메서드 설명

  *  os.arch(): process.arch와 동일.

  * os.platform(): process.platform과 동일.

  * os.type(): 운영체제의 종류를 보여줌

  * os.uptime(): 운영체제 부팅 이후 흐른 시간(초)를 보여줌. 

    * process.uptime()은 노드의 실행 시간.

  * os.hostname(): 컴퓨터의 이름을 보여줌.

  * os.release(): 운영체제의 버전을 보여줌.

  * os.homedir(): 홈 디렉터리 경로를 보여줌.

  * os.tmpdir(): 임시 파일 저장 경로를 보여줌.

  * os.cpus(): 컴퓨터의 코어 정보를 보여줌.

    * os.cpus().length: 컴퓨터의 코어 개수를 보여줌

      하지만 노드는 싱글 스레드이므로 대부분의 경우 코어를 한개만 사용한다.

  * os.freemem(): 사용 가능한 메모리(RAM)를 보여줌.

  * os.totalmem(): 전체 메모리 용량을 보여줌.

  * os.constant(): 각종 에러와 신호에 대한 정보가 있음.

os 모듈은 주로 컴퓨터 내부 자원에 빈번하게 접근하는 경우 사용된다. 일반적인 웬 서비스를 제정할 때는 사용 빈도가 높지 않다. 하지만 운영체제별로 다른 서비스를 제공하고 싶을 때 os 모듈이 유용하다.

### path

 폴더와 파일의 경로를 쉽게 조작하도록 도와주는 모듈

path 모듈이 필요한 이유 중 하나는 운영체제별로 경로 구분자가 다르게 때문이다.

* Windows
  : \\로 구분

* POSIX (macOS, 리눅스)
  : /로 구분

  

* path.js

  ```javascript
  const path = require('path');
  
  const string = __filename;
  
  console.log('path.sep:', path.sep);
  console.log('path.delimiter:', path.delimiter);
  console.log('------------------------------');
  console.log('path.dirname():', path.dirname(string));
  console.log('path.extname():', path.extname(string));
  console.log('path.basename():', path.basename(string));
  console.log('path.basename():', path.basename(string, path.extname(string)));
  console.log('------------------------------');
  console.log('path.parse()', path.parse(string));
  console.log('path.format():', path.format({
    dir:'C:\\users\\zerocho',
    name:'path',
    ext:'.js',
  }));
  console.log('path.normalize():', path.normalize('C://users\\\\zerocho\\\path.js'));
  console.log('------------------------------');
  console.log('path.isAbsolute():', path.isAbsolute('C:\\'));
  console.log('path.isAbsolute():', path.isAbsolute('./home'));
  console.log('------------------------------');
  console.log('path.relative():', path.relative('C:\\users\\zerocho\\path.js','C:\\'));
  console.log('path.join():', path.join(__dirname,'..','..','/users','.','/zerocho'));
  console.log('path.resolve():', path.resolve(__dirname,'..','users','.','/zerocho'));
  ```

* 메서드 설명

  * path.sep: 경로의 구분자입니다. Windows는 \, POSIX는 /입니다.
  *  path.delimiter: 환경 변수의 구분자입니다. process.env.PATH를 입력하면 여러 개의 경로가 이 구분자로 구분되어 있습니다. Windows는 세미콜론(;)이고 POSIX는 콜론(:)입니다.
  *  path.dirname(경로): 파일이 위치한 폴더 경로를 보여줍니다.
  *  path.extname(경로): 파일의 확장자를 보여줍니다.
  *  path.basename(경로, 확장자): 파일의 이름(확장자 포함)을 보여줍니다. 파일의 이름만 표시하고 싶다면 basename의 두 번째 인자로 파일의 확장자를 넣어주면 됩니다.
  *  path.parse(경로): 파일 경로를 root, dir, base, ext, name으로 분리합니다.
  * path.format(객체): path.parse()한 객체를 파일 경로로 합칩니다.
  *  path.normalize(경로): /나 \를 실수로 여러 번 사용했거나 혼용했을 때 정상적인 경로로 변환해줍니다.
  *  path.isAbsolute(경로): 파일의 경로가 절대경로인지 상대경로인지 true나 false로 알려줍니다.
  * path.relative(기준경로, 비교경로): 경로를 두 개 넣으면 첫 번째 경로에서 두 번째 경로로 가는 방법을 알려줍니다.
  *  path.join(경로, ...): 여러 인자를 넣으면 하나의 경로로 합쳐줍니다. 상대경로인 ..(부모 디렉터리)과 .(현 위치)도 알아서 처리해줍니다.
  *  path.resolve(경로, ...): path.join()과 비슷하지만 차이가 있습니다. 차이점은 다음에 나오는 Note에서 설명합니다.

### url

인터넷 주소를 쉽게 조작하도록 도와주는 모듈

url 처리에는 크게 두가지 방법이 있다.

* WHATWG방식의 url (주소 위쪽)
* 예전부터 노드에서 사용하던 방식의 url (주소 아래쪽)

![img](https://thebook.io/img/006982/099.jpg)

* url.js

  ```javascript
  const url = require('url');
  
  const URL = url.URL;
  const myURL = new URL('http://www.gilbut.co.kr/book/bookList.aspx?sercate1=001001000#anchor');
  console.log('new URL():', myURL);
  console.log('url.format():', url.format(myURL));
  console.log('------------------------------');
  const parsedUrl = url.parse('http://www.gilbut.co.kr/book/bookList.aspx?sercate1=001001000#anchor');
  console.log('url.parse():', parsedUrl);
  console.log('url.format():', url.format(parsedUrl));
  ```

기존 노드 방식에서는 두 메서드를 사용한다.

* url.parse(주소)
  : 주소를 분해한다.
  * WHATWG 방식과 비교하면 username과 password 대신 auth 속성이 있고, searchPrams 대신 query가 있다.
* url.format(객체)
  : 분해되었던 url 객체를 다시 원래 상태로 조립한다.
  * WHATWG 방식의 url과 기존 노드의 url방식 모두 사용할 수 있다.

WHATWG 방식과 기존 노드 방식은 취향에 따라 선택해 사용하면 되지만, 예외인 경우도 있다.

* 주소가 host 부분 없이 pathname 부분만 오는 경우(/book/bookList.apsx), WHATWG 방식으로 이 주소를 처리할 수 없다.

WHATWG 방식은 search 부분을 searchParams라는 특수한 객체로 반환하므로 유용하다.

* search 부분은 보통 주소를 통해 데이터를 전달할 때 사용된다. search는 물음표로 시작하고  그 뒤에 키=값 형식으로 데이터를 전달한다.

* searchParams.js

  ```javascript
  const { URL } = require('url');
  
  const myURL = new URL('http://www.gilbut.co.kr/?page=3&limit=10&category=nodejs&category=javascript');
  console.log('searchParams:', myURL.searchParams);
  console.log('searchParams.getAll():', myURL.searchParams.getAll('category'));
  console.log('searchParams.get():', myURL.searchParams.get('limit'));
  console.log('searchParams.has():', myURL.searchParams.has('page'));
  
  console.log('searchParams.keys():', myURL.searchParams.keys());
  console.log('searchParams.values():', myURL.searchParams.values());
  
  myURL.searchParams.append('filter','es3');
  myURL.searchParams.append('filter','es5');
  console.log(myURL.searchParams.getAll('filter'));
  
  myURL.searchParams.set('filter','es6');
  console.log(myURL.searchParams.getAll('filter'));
  
  myURL.searchParams.delete('filter');
  console.log(myURL.searchParams.getAll('filter'));
  
  console.log('searchParams.toString():', myURL.searchParams.toString());
  myURL.search = myURL.searchParams.toString();
  ```

* 메서드 설명
  *  getAll(키): 키에 해당하는 모든 값들을 가져옵니다. category 키에는 두 가지 값, 즉 nodejs와 javascript의 값이 들어 있습니다.
  *  get(키): 키에 해당하는 첫 번째 값만 가져옵니다.
  *  has(키): 해당 키가 있는지 없는지를 검사합니다.
  *  keys(): searchParams의 모든 키를 반복기(iterator, ES2015 문법) 객체로 가져옵니다.
  *  values(): searchParams의 모든 값을 반복기 객체로 가져옵니다.
  *  append(키, 값): 해당 키를 추가합니다. 같은 키의 값이 있다면 유지하고 하나 더 추가합니다.
  *  set(키, 값): append와 비슷하지만 같은 키의 값들을 모두 지우고 새로 추가합니다.
  *  delete(키): 해당 키를 제거합니다.
  *  toString(): 조작한 searchParams 객체를 다시 문자열로 만듭니다. 이 문자열을 search에 대입하면 주소 객체에 반영됩니다.

query보다 searchParams가 더 유용한 이뉴는 query의 경우 다음 절에 나오는 querstring 모듈을 더 사용해야 하기 때문이다.

### qyerysting

WHATWG 방식의 url 대신 기존 노드의 url을 사용할 때  search 부분을 사용하기 쉽게 객체로 만드는 모듈이다.

* querystring.js

  ```javascript
  const url = require('url');
  const querystring = require('querystring');
  
  const parsedUrl = url.parse('http://www.gilbut.co.kr/?page=3&limit=10&category=nodejs&category=javascript');
  const query = querystring.parse(parsedUrl.query);
  console.log('querystring.parse():', query);
  console.log('querystring.stringify():', querystring.stringify(query));
  ```

모듈을 두개 사용(url, querystring)

* 매서드 설명
  * querystring.parse(쿼리) : url의 query 부분을 자바 스크립트 객체로 분해한다.
  * querystring.stringify(객체) : 분해된 query 객체를 문자열로 다시 조립해준다.

### crypto

다양한 방식의 암호화를 도와주는 모듈. 몇 가지 메서드는 익혀두면 실제 서비스에도 적용할 수 있으므로 매우 유용하다.

데이터베이스가 해킹 당하더라도 고객의 정보가 안전할 수 있도록 이중으로 안전장치를 해 놓는것

#### 단방향 암호화

복호화 할 수 없는 암호화 방식을 의미한다.
즉, 단방향 암호화는 한 번 암호화하면 원래 문자열을 찾을 수 없다.

복호화할 수 없더라도 의미가 있다.
고객의 비밀번호를 암호화해서 데이터베이스에 저장한다. 그리고 로그인할 때마다 입력받은 비밀번호를 같은 암호화 알고리즘으로 암호화한 후 데이터베이스의 비밀번호화 비교하면 된다. 이러면 비밀번호는 어디에도 저장되지 않고 암호화 된 문자열로만 비교한다.

단방향 알고리즘은 대부분은 해시 기법을 사용한다.

##### 해시 기법

> 어떠한 문자열을 고정된 길이의 다른 문자열로 바꿔버리는 방식

* hash.js

  ```javascript
  const crypto = require('crypto');
  
  console.log('base64:', crypto.createHash('sha512').update('비밀번호').digest('base64'));
  console.log('hex:', crypto.createHash('sha512').update('비밀번호').digest('hex'));
  console.log('base64:', crypto.createHash('sha512').update('다른 비밀번호'). digest('base64'));
  ```

  비밀번호라는 문자열을 해시를 통해 바꾸었다.

  * createHash(알고리즘)
    : 사용할 해시 알고리즘을 넣어준다. md5, shal, sha356, sha512 등이 가능하지만 md5와 shal은 이미 취약점이 발견되어 현재는 sha512를 사용한다. 하지만 sha512도 취약해지면 더 강화된 알고리즘으로 바꾸어야 한다.
  * update(문자열)
    : 변환할 문자열을 넣어준다.
  * digest(인코딩)
    : 인코딩할 알고리즘을 넣어준다. bash64, hax, latin1이 주로 사용되는데 그 중 base64가 문자열이 가장 짧아 애용된다. 결과물로 변환된 문자열을 반환한다.

현재는 주로 pbkdf2나  bcrypt, scrypt라는 알고리즘으로 비밀번호를 암호화하고 있다.
이 중 노드에서는 pbkdf2라는 알고리즘을 지원한다.

pbkdf2는 기존 문자열에  salt라고 불리는 문자열을 붙인 후 해시 알고리즘을 반복해서 적용하는 것이다.

* pbkdf2.js

  ```javascript
  const crypto = require('crypto');
  
  crypto.randomBytes(64, (err,buf) => {
      const salt = buf.toString('base64');
      console.log('salt:', salt);
      crypto.pbkdf2('비밀번호', salt, 100000, 64, 'sha512', (err, key) => {
          console.log('password:', key.toString('base64'));
      });
  });
  ```

  먼저 randomBytes() 메서드로 64바이트 길이의 문자열을 만들어준다. 이것이 salt가 된다. pbkdf2() 메서드에는 순서대로 비밀번호, salt, 반복 횟수, 출력 바이트, 해시 알고리즘을 인자로 넣어준다.
  **즉 sha512로 변환된 결과값을 다시 sha512로 변환하는 과정을 횟수만큼 반복한다.**

#### 양방향 암호화

##### 양방향 대칭형 암호화

암호화된 문자열을 복호화할 수 있다. 여기에서는 키(열쇠)라는 것이 사용된다. 암호를 복호화하려면 암호화할 때 사용한 키와 같은 키를 사용해야 한다.

* cipher.js

  ```javascript
  const crypto = require('crypto');
  
  const cipher = crypto.createCipher('aes-256-cbc', '열쇠');
  let result = cipher.update('암호화할 문장', 'utf8', 'base64');
  result += cipher.final('base64');
  console.log('암호화:', result);
  
  const decipher = crypto.createDecipher('aes-256-cbc', '열쇠');
  let result2 = decipher.update(result, 'base64', 'utf8');
  result2 += decipher.final('utf8');
  console.log('복호화:', result2);
  ```
  * crypto.createCipher(알고리즘, 키)
    : 암호화 알고리즘과 키를 넣어준다. 암호화 알고리즘은 aes-256-cbc를 사용.
  * cupher.update(문자열, 인코딩, 출력 인코딩)
    : 암호화할 대상고 ㅏ대상의 인코딩, 출력 결과물의 인코딩을 넣어준다. 보통 문자열은 utf8, 함호는 base64를 많이 사용한다.
  * cipher.final(출력 인코딩)
    : 출력 결과물의 인코딩을 넣어주면 암호화가 완료된다.
  * crypto.createDecipher(알고리즘, 키)
    : 복호화할 때 사용한다. 암호화할 때 사용했던 알고리즘과 키를 그대로 넣어주어야 한다.
  * decipher.update(문자열, 인코딩, 출력 인코딩)
    : 암호화된 문장, 그 문장의 인코딩, 복호화 할 인코딩을 넣어준다. update에 넣었던 역순으로 넣는다.
  * decipher.final(출력인코딩)
    : 복호화 결과물의 인코딩을 넣어준다.

### util

> 이름처럼 각종 편의 기능을 모아놓은 모듈. 계속해서 API가 추가되고 있고, 가끔 deprecated되어 사라지는 경우도 있다.

* deprecated
  : 프로그래밍 용어로 중요도가 떨어져 더 이상 사용되지 않고 앞으로는 사라지게 될 것이라는 뜻이다. 이전 사용자를 위해 제거하지는 않지만 곧 없앨 예정이므로 더이상 사용하지 말라는 의미이다.

util에서 자주 쓰이는 두 모듈을 소개한다.

* util.js

  ```javascript
  const util = require('util');
  const crypto = require('crypto');
  
  const dontUseMe = util.deprecate((x, y) => {
      console.log(x + y);
  },'dontUseMe 함수는 deprecated되었으니 더 이상 사용하지 마세요!');
  dontUseMe(1, 2);
  
  const randomBytesPromise = util.promisify(crypto.randomBytes);
  randomBytesPromise(64)
      .then((buf) => {
          console.log(buf.toString('base64'));
      })
      .catch((error) => {
          console.error(error);
      });
  ```

  * util.deprecete
    : 함수가  deprecated 처리되었음을 알려준다. 첫 번째 인자로 넣은 함수를 사용했을 때 경고 메시지가 출력된다. 두 번쨰 인자로 경고 메시지 내용을 넣으면 된다. 함수가 조만간 사라지거나 변경될 때 알려줄 수 있어 유용하다.
  * util.promidify
    : 콜백 패턴을 프로미스 패턴으로 바꾸어준다. 바꿀 함수를 인자로 제공하면 된다. 이렇게 바꾸어두면 async/await 패턴까지 사용할 수 있어 좋다. randomBytes와 비교해본다. 프로미스를 콜백으로 바꾸는 util.callbackify도 있지만 자주 사용되지 않는다.

## 3.6 파일 시스템 접근하기

fs 모듈을 파일 시스템에 접근하는 모듈이다. 즉 파일을 생성하거나 삭제하고, 읽거나 쓸 수 있다. 폴더를 만들었다 지웠다 할 수도 있다.
웹 브라우저에서 자바스크립트를 사용할 때는 파일 다운로드와 파일 시스템 접근이 금지되어 있으므로 노드의 fs 모듈이 낯설 것이다.

파일 시스템 접근이 가능해 파일을 읽을 수 있다.

* readme.js

  ```javascript
  const fs = require('fs');
  
  fs.readFile('./readme.txt', (err,data) => {
      if (err) {
          throw err;
      }
      console.log(data);
      console.log(data.toString());
  });
  ```

  동일 경로에 있는 readme 파일을 열고 읽는다.

  * readFile의 결과물은 버퍼라는 형식으로 제공된다. 버퍼틑 사람이 읽을 수 있는 형식이 아니므로 toString()을 사용해 문자열로 변환해 읽는다.

파일을 만들수도 있다.

* writeFile.js

  ```javascript
  const fs = require('fs');
  
  fs.writeFile('./writeme.txt','글이 입력됩니다', (err) => {
      if (err) {
          throw err;
      }
      fs.readFile('./writeme.txt', (err, data) => {
          if (err) {
              throw err;
          }
          console.log(data.toString());
      });
  });
  ```

  writeFile() 메서드에 생성될 파일의 경로와 내용을 입력해준다.

### 동기 메서드와 비동기 메서드

노드는 대부분의 메서드를 비동기 방식으로 처리한다. 하지만 몇몇 메서드는 동기 방식으로도 사용할 수 있다.
특히 fs 모듈이 그런 메서드를 많이 가지고 있다.

파일 하나를 여러번 읽어 본다.

* async.js

  ```javascript
  const fs = require('fs');
  
  console.log('시작');
  fs.readFile('./readme2.txt', (err, data) => {
    if (err) {
      throw err;
    }
    console.log('1번', data.toString());
  });
  fs.readFile('./readme2.txt', (err, data) => {
    if (err) {
      throw err;
    }
    console.log('2번', data.toString());
  });
  fs.readFile('./readme2.txt', (err, data) => {
    if (err) {
      throw err;
    }
    console.log('3번', data.toString());
  });
  console.log('끝');
  ```

  비동기 메서드들은 백 그라운드에 해당 파일을 읽으라고만 요청하고 다음 작업으로 넘어간다. 따라서 파일 읽기 요청만 3번 보내고 console.log('끝')을 찍는다. 나중에 읽기가 완료되면 백그라운드가 다신 메인 스레드에 알림을 준다. 메일 스레드는 그제서야 등록된 콜백 함수를 실행한다. 이 방식은 많은 I/O요청이 들어와도 메인 스레드가 백 그라운드에 요청 처리를 위임하므로 매우 효율적이다.

파일을 순서대로 출력하고 싶은 경우

* sync.js

  ```javascript
  const fs = require('fs');
  
  console.log('시작');
  let data = fs.readFileSync('./readme2.txt');
  console.log('1번', data.toString());
  data = fs.readFileSync('./readme2.txt');
  console.log('2번', data.toString());
  data = fs.readFileSync('./readme2.txt');
  console.log('3번', data.toString());
  console.log('끝');
  ```

  readFile() 대신 readFileSync()라는 메서드를 사용했다. 콜백 함수를 넣는 대신 직접 return 값을 받아온다.
  이 경우 많은 I/O 요청이 들어왔을 때, 문제가 생길 수 있다.

비동기 방식으로 성능 유지하기

* asyncOrderj.js

  ```javascript
  const fs = require('fs');
  
  console.log('시작');
  fs.readFile('./readme2.txt', (err, data) => {
      if (err) {
          throw err;
      }
      console.log('1번', data.toString());
      fs.readFile('./readme2.txt', (err, data) => {
          if (err) {
              throw err;
          }
          console.log('2번', data.toString());
          fs.readFile('./readme2.txt', (err, data) => {
              if (err) {
                  throw err;
              }
              console.log('3번', data.toString());
          });
      });
  });
  console.log('끝');
  ```

  * 콜백은 promise async/await으로 해결 가능

data를  data.toString()으로 변환하는 이유를 알기 위해는 버퍼를 이해해야 한다.

### 버퍼와 스트림 이해하기

파일을 읽거나 쓰는 방식은 버퍼를 이용하는 방법과 스트림을 이용하는 방법이 있다.
우리에겐 버퍼링과 스트리밍이 더 익숙한데 영상을 로딩중일때 버퍼링한다고 하고, 영상을 실시간으로 송출할 때는 스트리밍한다고 한다.

버퍼링은 영상을 재생할 수 있을 때까지 데이터를 모으는 동작이고, 스트리밍은 방송인의 컴퓨터에서 시청자의 컴퓨터로 영상 데이터를 조금씩 전송하는 동작이다. 스트리밍 과정을 버퍼링할 수 도 있다.

### 기타 fs 메서드

## 3.7 이벤트 이해하기

## 3.8 예외 처리하기

