# 4장 http 모듈로 웹 서버 만들기

### 서버와 클라이언트의 관계

#### 서버

서버는 클라이언트가 있기에 동작한다.

#### 클라이언트

클라이언트는 서버에게 요청을 하고 서버는 응답으로써 작용한다.

## 4.1 요청과 응답 이해하기

![img](https://thebook.io/img/006982/132.jpg)

클라이언트에서 서버로 요청(request)을 보내고 서버에서는 요청의 내용을 읽고 처리한 뒤 클라이언트에게 응답(response)을 보낸다.

따라서 서버에는 **요청을 받는 부분**과 **응답을 보내는 부분**이 있어야 한다.
요청과 응답은 이벤트 방식이며, 요청에 따른 작업수행을 위해 이벤트 리스너를 미리 등록해야 한다.

이벤트 리스너를 가진 노드 서버

* createServer.js

  ```javascript
  const http = require('http');
  
  http.createServer((req, res) => {
      // 여기에 어떻게 응답할지 적어줍니다.
  });
  ```

  http 모듈을 사용했고 http 모듈에 있는 createServer 메서드를 사용했다.
  req는 request, res는 respond를 줄여서 표현했고 req객체는 요청에 관한 정보들을 res객체는 응답에 관한 정보를 담고 있다.

### http.createServer

http 모듈에 들어있는 메서드. 서버를 만들기 위해서 사용하고, 인자로 요청에 대한 콜백함수를 넣을 수 있다

#### res

응답에 관한 정보를 담은 객체

* res.write

  : 클라이언트로 데이터를 보내는 메서드.
  HTML 모양의 문자열을 보냈지만 버퍼를 보낼수도 있다. 여러번 호출할 수도 있다.

* res.end

  : 응답을 종료하는 메서드
  만약 인자가 있다면 그 데이터도 클라이언트로 보내고 응답을 종료한다. 

#### req

<br>

요청에 대한 응답과 서버와의 연결을 추가해본다.

* server1.js

  ```javascript
  const http = require('http');
  
  http.createServer((req, res) => {
      res.write('<h1>Hello Node!</h1>');
      res.end('<p>Hello Server!</p>');
  }).listen(8080, () => {
      console.log('8080번 포트에서 서버 대기 중입니다!');
  });
  ```

  createServer 메서드 뒤에 listen 메서드를 붙이고 클라이언트에게 공개할 포트 번호와 포트 연결 완료 후 실행될 콜백 함수를 넣어준다. 이제 이 파일을 실행하면 서버는 8080 포트에서 요청이 오기를 대기한다.

listen 메서드에 콜백 함수를 넣는 대신, 서버에 listening 이벤트 리스너를 붙여도 된다.

* server1-0.js

  ```javascript
  const http = require('http');
  
  const server = http.createServer((req, res) => {
      res.write('<h1>Hello Node!</h1>');
      res.end('<p>Hello Server!</p>');
  });
  server.listen(8080);
  server.on('listening', () => {
      console.log('8080번 포트에서 서버 대기 중입니다!');
  });
  server.on('error', (error) => {
      console.error(error);
  });
  ```

  res.write에서 문자열을 보내고, res.end에 있는 문자열도 크랄리언트로 보낸다.
  브라우저는 응답 내용을 받아서 렌더링을 한다.

<br>

![img](https://thebook.io/img/006982/135_1.jpg)

위 그림은 서버 구조도이다.

<br>

* localhost

  현재 컴퓨터 내부 주소를 가리킨다. 외부에서 접근할 수 없고 자신의 컴퓨터에서만 접근할 수 있기 때문에 서버 개발 시 테이스용으로 많이 사용된다.
  localhost 대신 127.0.0.1을 주소로 사용해도 같다. 이러한 숫자 주소를 IP라고 한다.

* port

  포트는 서버 내에서 프로세스를 구분하는 번호이다. 서버는 HTTP 요청을 대기하는 것 외에도 다양한 작업을 한다. 데이터베이스와도 통신해야 하고 FTP 요청을 처리하기도 한다. 따라서 서버는 프로세스에 포트를 다르게 할당하여 들어오는 요청을 구분한다.

  * 유명한 포트 번호

    : 21(FTP), 80(HTTP), 443(HTTPS), 3306(MYSQL)이 있다. 포트 번호는 IP 주소 뒤에 콜론과 함께 붙여 사용한다.

  80번 포트를 사용하면 주소에서 포트를 생략할 수 있다.

<br>

res.write 메서드로 한 줄씩 HTML코드를 적는 것은 너무 비효율적이므로, HTML 파일을 읽어서 전송하는 방법을 사용해 본다.

* server2.html

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8" />
      <title>Node.js 웹 서버</title>
  </head>
  <body>
      <h1>Node.js 웹 서버</h1>
      <p>만들 준비되셨나요?</p>
  </body>
  </html>
  ```

* server2.js

  ```javascript
  const http = require('http');
  const fs = require('fs');
  
  http.createServer((req, res) => {
      fs.readFile('./server2.html', (err, data) => {
          if (err) {
              throw err;
          }
          res.end(data);
      });
  }).listen(8081, () => {
      console.log('8081번 포트에서 서버 대기 중입니다!');
  });
  ```

  fs 모듈을 사용했다. fs 모듈로 HTML 파일을 읽는다. data 변수에 저장된 버퍼를 그대로 클라이언트에 보내주면 된다. 

<br>

<br>

## 4.2 쿠키와 세션 이해하기

클라이언트에서 보내는 요청에는 한 가지 큰 단점이 있다. 바로 누가 요청을 보내는지 모른다는 것이다. 물론 요청을 보내는 IP주소나 브라우저의 정보를 받아올 수는 있다. 하지만 여러 컴퓨터가 공통으로 IP주소를 가지거나 한 컴퓨터를 여러 사람이 사용할 수도 있으므로 이는 위험하다.

그래서 로그인을 구현해야 하는데 이를 구현하려면 쿠키와 세션에 대해 알고 있어야 한다.

사용자가 웹 사이트에 방문해서 로그인을 할 때 내부적으로는 쿠키와 세션을 사용하고 있다. 그래서 로그인 한 후 새로고침을 해도 로그아웃이 되지 않는다. 그 이유는 클라이언트가 서버에게 여러분이 누구인지를 지속적으로 알려주고 있기 때문이다.

**쿠키는 클라이언트 로컬에 저장되는 Key-Value쌍의 작은 데이터 파일이고, 세션은 브라우저가 종료되기 전까지 클라이언트의 요청을 유지하게 해주는 기술이다.**

### 쿠키

당신들이 누구인지 기억하기 위해서, 서버는 요청에 대한 응답을 할 때 쿠키라는 것을 같이 보내준다.
쿠키는  name=kukjun 같이 단순한 '키-값'의 쌍이다.

서버로부터 쿠키가 오면 웹 브라우저는 쿠키를 저장해두었다가 요청할 때마다 쿠키를 동봉해서 보내준다. 서버는 요청에 들어있는 쿠키를 읽어서 사용자가 누구인지 파악한다.

브라우저는 쿠키가 있으면 자동으로 동봉해서 보내주므로 따로 처리할 필요가 없다. 서버에서 브라우저르 쿠키를 보낼 때만 코드를 작성하여 처리하면 된다.

![img](https://thebook.io/img/006982/138.jpg)

즉, 서버는 미리 클라이언트에 요청자를 추정할 만한 정보를 쿠키로 만들어 보내고, 그 다음부터는 클라이언트로부터 쿠키를 받아 요청자를 파악한다. 쿠키가 사용자가 누구인지 추적하는 것이다. 개인정보 유출을 방지하기 위해 쿠키를 주기적으로 지우라는 말이 바로 이러한 이유 때문이다.

쿠키는 요청과 응답의 헤더에 저장된다. 요청과 응답은 각각 헤더와 본문을 가진다. 
서버에서 직접 쿠키를 만들어 요청자의 브라우저에 넣어본다.

* server3.js

  ```javascript
  const http = require('http');
  
  const parseCookies = (cookie ='') =>
      cookie
          .split(';')
          .map(v => v.split('='))
          .map(([k, ...vs]) => [k, vs.join('=')])
          .reduce((acc, [k, v]) => {
              acc[k.trim()] = decodeURIComponent(v);
              return acc;
          }, {});
  
  http.createServer((req, res) => {
      const cookies = parseCookies(req.headers.cookie);
      console.log(req.url, cookies);
      res.writeHead(200, {'Set-Cookie':'mycookie=test' });
      res.end('Hello Cookie');
  })
      .listen(8082, () => {
          console.log('8082번 포트에서 서버 대기 중입니다!');
      });
  ```

  * parseCookies
    : 쿠키는 name=kukjun;year=1998처럼 문자열 형식으로 오므로 이를 {name : 'kukjun', year : '1994'}와 같이 객체로 바꾸는 함수이다.

  createServer 메서드의 콜백에서는 제일 먼저 req 객체에 담겨 있는 쿠키를 분석한다. 쿠키는 req.headers.cookie에 들어있다. req.headers는 요청의 헤더를 의미한다.

  응답의 헤더에 쿠키를 기록해야 하므로 res.writeHead 메서드를 사용한다. 첫 번째 인자로 200이라는 상태 코드를 넣었는데 이는 성공이라는 의미이다. 두 번째 인자로는 헤더의 내용을 한다. Set-Cookie는 브라우저한테 다음과 같은 값의 쿠키를 저장하라는 의미이다. 실제로 응답을 받은 브라우저는 mycookie=test라는 쿠키를 저장한다.

  * 파비콘

    ![img](https://thebook.io/img/006982/140.jpg)

    파비콘이란 위와 같이 웹 사이트 탭에 보이는 이미지를 뜻한다.

    HTML에 파비콘에 관한 정보를 넣어두지 않았으므로 브라우저가 추가로 favicon.ico를 요청한 것이다.

##### http 상태 코드

res.writeHead에 첫 번째 인자로 성공을 알리는 상태 코드인 200을 넣어주었는데, 브라우저는 서버에서 보내주는 상태 코드를 보고 요청이 성공했는지 실패했는지를 판단한다. 대표적인 상태 코드들을 알아보자

* 2XX: 성공을 알리는 상태 코드이다. 대표적으로 200(성공), 201(작성됨)이 많이 사용된다.

* 3XX: 리다이렉션(다른 페이지로 이동)을 알리는 상태 코드이다. 어떤 주소를 입력했는데 다른 주소의 페이지로 넘어갈 때 이 코드가 사용된다. 대표적으로 301(영구 이동), 302(임시 이동)가 있다.

* 4XX: 요청 오류를 나타냅니다. 요청 자체에 오류가 있을 때 표시됩니다. 대표적으로 401(권한 없음), 403(금지됨), 404(찾을 수 없음)가 있습니다.

* 5XX: 서버 오류를 나타낸다. 요청은 제대로 왔지만 서버에 오류가 생겼을 때 발생한다. 이 오류가 뜨지 않게 주의해서 프로그래밍해야 한다. 이 오류를 클라이언트로 res.writeHead로 직접 보내는 경우는 없고, 예기치 못한 에러 발생 시 서버가 알아서 5XX대 코드를 보낸다. 500(내부 서버 오류), 502(불량 게이트웨이), 503(서비스를 사용할 수 없음)이 자주 사용된다.

##### 헤더와 본문

![img](https://thebook.io/img/006982/141.jpg)

요청과 응답은 모두 헤더와 본문을 가지고 있습니다. 헤더는 요청 또는 응답에 대한 정보를 가지고 있는 곳이고, 본문은 서버와 클라이언트 간에 주고받을 실제 데이터를 담아두는 공간입니다. 쿠키는 부가적인 정보이므로 헤더에 저장합니다.

<br>

이제 쿠키가 나인지를 식별해주는 방법을 알아보자. 다음 두 파일을 같은 폴더안에 생성한다.

* server4.html

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8" />
      <title>쿠키&세션 이해하기</title>
  </head>
  <body>
  <form action="/login">
      <input id="name" name="name" placeholder="이름을 입력하세요" />
      <button id="login">로그인</button>
  </form>
  </body>
  </html>
  ```

* server4.js

  ```javascript
  const http = require('http');
  const fs = require('fs');
  const url = require('url');
  const qs = require('querystring');
  
  const parseCookies = (cookie ='') =>
      cookie
          .split(';')
          .map(v => v.split('='))
          .map(([k, ...vs]) => [k, vs.join('=')])
          .reduce((acc, [k, v]) => {
              acc[k.trim()] = decodeURIComponent(v);
              return acc;
          }, {});
  
  http.createServer((req, res) => {
      const cookies = parseCookies(req.headers.cookie);
      if (req.url.startsWith('/login')) {
    const { query } = url.parse(req.url);
          const { name } = qs.parse(query);
          const expires = new Date();
          expires.setMinutes(expires.getMinutes() + 5);
          res.writeHead(302, {
              Location:'/',
              'Set-Cookie': `name=${encodeURIComponent(name)}; 
  Expires=${expires.toGMTString()}; HttpOnly; Path=/`,
          });
          res.end();
      } else if (cookies.name) {
    res.writeHead(200, {'Content-Type':'text/html; charset=utf-8' });
          res.end(`${cookies.name}님 안녕하세요`);
      } else {
          fs.readFile('./server4.html', (err, data) => {
              if (err) {
                  throw err;
              }
              res.end(data);
          });
      }
  })
      .listen(8083, () => {
          console.log('8083번 포트에서 서버 대기 중입니다!');
      });
  ```

  * 쿠키가 노출되어 있고, 조작될 위험이 있으므로 위험하다.

서버가 사용자 정보를 관리하도록 만들기

* server5.js

  ```javascript
  const http = require('http');
  const fs = require('fs');
  const url = require('url');
  const qs = require('querystring');
  
  const parseCookies = (cookie ='') =>
      cookie
          .split(';')
          .map(v => v.split('='))
          .map(([k, ...vs]) => [k, vs.join('=')])
          .reduce((acc, [k, v]) => {
              acc[k.trim()] = decodeURIComponent(v);
              return acc;
          }, {});
  
  const session = {};
  
  http.createServer((req, res) => {
      const cookies = parseCookies(req.headers.cookie);
      if (req.url.startsWith('/login')) {
          const { query } = url.parse(req.url);
          const { name } = qs.parse(query);
          const expires = new Date();
          expires.setMinutes(expires.getMinutes() + 5);
          const randomInt = +new Date();
          session[randomInt] = {
              name,
              expires,
          };
          res.writeHead(302, {
              Location:'/',
              'Set-Cookie': `session=${randomInt}; Expires=${expires.toGMTString()}; HttpOnly; Path=/`,
          });
          res.end();
      } else if (cookies.session && session[cookies.session].expires > new Date()) {
          res.writeHead(200, {'Content-Type':'text/html; charset=utf-8' });
          res.end(`${session[cookies.session].name}님 안녕하세요`);
      } else {
          fs.readFile('./server4.html', (err, data) => {
              if (err) {
                  throw err;
              }
              res.end(data);
          });
      }
  })
      .listen(8084, () => {
          console.log('8084번 포트에서 서버 대기 중입니다!');
      });
  ```

### 세션



<br>

## 4.3 REST API와 라우팅

서버에 요청을 보낼 때는 주소를 통해 요청의 내용을 표현한다.
요청이 주소를 통해 들어오므로 서버가 이해하기 쉬운 주소를 사용하는 것이 좋다. 여기서 REST API가 등장한다.

### REST API

REpresentational State Transfer의 약어. 네트워크 구조의 한 형식

HTTP URI

#### 주소

서버의 자원을 정의하고, 자원에 대한 주소를 지정하는 방법을 가리킨다. 주소의 의미를 명확히 전달하기 위해 명사로 구성된다.
/user이면 사용자 정보에 관련된 자원을 요청하는 것이고, /post라면 게시글과 관련된 자원을 요청하는 것이라고 추측할 수 있다.

#### 요청 메서드

REST API는 주소 외에도 HTTP 요청 메서드라는 것을 사용한다.

* GET: 서버 자원을 가져오고자 할 때 사용합니다. 요청의 본문(body)에 데이터를 넣지 않습니다. 데이터를 서버로 보내야 한다면 쿼리스트링을 사용합니다.

* POST: 서버에 자원을 새로 등록하고자 할 때 사용합니다. 요청의 본문에 새로 등록할 데이터를 넣어 보냅니다.

* PUT: 서버의 자원을 요청에 들어 있는 자원으로 치환하고자 할 때 사용합니다. 요청의 본문에 치환할 데이터를 넣어 보냅니다.

* PATCH: 서버 자원의 일부만 수정하고자 할 때 사용합니다. 요청의 본문에 일부 수정할 데이터를 넣어 보냅니다.

* DELETE: 서버의 자원을 삭제하고자 할 때 사용합니다.

주소 하나가 요청 메서드를 여러 개 가질 수 있다. GET메서드의 /user 주소로 요청을 보내면 사용자 정보를 가져오는 요청이라는 것을 알 수 있고, POST 메서드의 /user 주소로 요청을 보내면 새로운 사용자를 등록하려 한다는 것을 알 수 있다.

![img](https://thebook.io/img/006982/150.jpg)

**이렇게 주소와 메서드만 보고 요청의 내용을 명확하게 알아볼 수 있다는 것이 장점이다.**

또 GET 메서드 같은 경우에는 브라우저에서 캐싱할 수도 있어서 같은 주소의 GET 요청을 할 때 서버에서 가져오는 것이 아니라 캐시에서 가져올 수도 있습니다. 이렇게 캐싱이 되면 성능이 좋아집니다.

http프로토콜을 사용하면 클라이언트가 누구든 상관없이 서버와 소통할 수 있다. iOS, 안드로이드, 웹이 모두 같은 주소로 요청을 보낼 수 있다. 즉 **서버와 클라이언트가 분리되어 있다**

REST API를  따르는 서버를 RESTful 하다고 표현한다. RESTful한 웹 서버를 만들어보자

![image-20200727151310857](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200727151310857.png)

* testFront.css

  ```css
  a {
      color: blue;
      text-decoration: none;
  }
  ```

* testFront.html

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8" />
      <title>Restful SERVER</title>
      <link rel="stylesheet" href="./restFront.css" />
  </head>
  <body>
  <nav>
      <a href="">Home</a>
      <a href="/about">About</a>
  </nav>
  <div>
      <form id="form">
          <input type="text" id="username">
          <button type="submit">등록</button>
      </form>
  </div>
  <div id="list"></div>
  <script src="./restFront.js"></script>
  </body>
  </html>
  ```

* restFront.js

  ```javascript
  function getUser() { // 로딩 시 사용자가 가져오는 함수
      var xhr = new XMLHttpRequest();
      xhr.onload = function () {
          if (xhr.status === 200) {
              var users = JSON.parse(xhr.responseText);
              var list = document.getElementById('list');
              list.innerHTML ='';
              Object.keys(users).map(function (key) {
                  var userDiv = document.createElement('div');
                  var span = document.createElement('span');
                  span.textContent = users[key];
                  var edit = document.createElement('button');
                  edit.textContent ='수정';
                  edit.addEventListener('click', function () { // 수정 버튼 클릭
                      var name = prompt('바꿀 이름을 입력하세요');
                      if (!name) {
                          return alert('이름을 반드시 입력하셔야 합니다');
                      }
                      var xhr = new XMLHttpRequest();
                      xhr.onload = function () {
                          if (xhr.status === 200) {
                              console.log(xhr.responseText);
                              getUser();
                          } else {
                              console.error(xhr.responseText);
                          }
                      };
                      xhr.open('PUT','/users/' + key);
                      xhr.setRequestHeader('Content-Type','application/json');
                      xhr.send(JSON.stringify({ name: name }));
                  });
                  var remove = document.createElement('button');
                  remove.textContent ='삭제';
                  remove.addEventListener('click', function () { // 삭제 버튼 클릭
                      var xhr = new XMLHttpRequest();
                      xhr.onload = function () {
                          if (xhr.status === 200) {
                              console.log(xhr.responseText);
                              getUser();
                          } else {
                              console.error(xhr.responseText);
                          }
                      };
                      xhr.open('DELETE','/users/' + key);
                      xhr.send();
                  });
                  userDiv.appendChild(span);
                  userDiv.appendChild(edit);
                  userDiv.appendChild(remove);
                  list.appendChild(userDiv);
              });
          } else {
              console.error(xhr.responseText);
          }
      };
      xhr.open('GET','/users');
      xhr.send();
  }
  window.onload = getUser; // 로딩 시 getUser 호출
  // 폼 제출
  document.getElementById('form').addEventListener('submit', function (e) {
      e.preventDefault();
      var name = e.target.username.value;
      if (!name) {
          return alert('이름을 입력하세요');
      }
      var xhr = new XMLHttpRequest();
      xhr.onload = function () {
          if (xhr.status === 201) {
              console.log(xhr.responseText);
              getUser();
          } else {
              console.error(xhr.responseText);
          }
      };
      xhr.open('POST','/users');
      xhr.setRequestHeader('Content-Type','application/json');
      xhr.send(JSON.stringify({ name: name }));
      e.target.username.value ='';
  });
  
  ```

  

## 4.4 https와 http2

### https

https 모듈은 웹 서버에 SSL 암호화를 추가합니다. GET이나 POST 요청을 할 때 오고 가는 데이터를 암호화해서 중간에 다른 사람이 요청을 가로채더라도 내용을 확인할 수 없게 해줍니다. 요즘은 로그인이나 결제가 필요한 창에서 https 적용이 필수가 되는 추세입니다.

SSL이 적용된 웹 사이트에 방문하면 그림 4-19와 같이 브라우저 주소창에 자물쇠 표시가 나옵니다.
![img](https://thebook.io/img/006982/158.jpg)

 암호화를 적용하는 만큼, 그것을 인증해줄 수 있는 기관도 필요합니다. 인증서는 인증 기관에서 구입해야 합니다.

### http2

노드의 http2 모듈은 SSL 암호화와 더불어 최신 HTTP 프로토콜인 http/2를 사용할 수 있게 해줍니다. http/2는 요청 및 응답 방식이 기존 http/1.1보다 개선되어 훨씬 효율적으로 요청을 보냅니다. http/2를 사용하면 웹의 속도도 많이 개선됩니다.

![img](https://thebook.io/img/006982/159.jpg)

암호화를 적용하는 만큼, 그것을 인증해줄 수 있는 기관도 필요합니다. 인증서는 인증 기관에서 구입해야 합니다.

<br>

## 4.5 cluster

cluster 모듈은 싱글 스레드인 노드가 CPU 코어를 모두 사용할 수 있게 해주는 모듈입니다.
포트를 공유하는 노드 프로세스를 여러 개 둘 수도 있어 요청이 많이 들어왔을 때 병렬로 실행된 서버의 개수만큼 요청이 분산되게 해 서버에 무리가 덜 가게 된다. 예를 들어 코어가 8개인 서버를 cluster 모듈을 설정하여 코어 하나당 노드 프로세스 하나가 돌아가게 할 수 있습니다. 성능이 꼭 8배가 되는 것은 아니지만 코어를 하나만 사용할 때에 비해 성능이 개선됩니다.

하지만 장점만 있는 것은 아니며, 세션을 공유하지 못하는 등의 단점도 있습니다.  Redis 등의 서버를 도입하여 해결할 수 있습니다.

* cluster.js

  ```javascript
  const cluster = require('cluster');
  const http = require('http');
  const numCPUs = require('os').cpus().length;
  
  if (cluster.isMaster) {
    console.log(`마스터 프로세스 아이디: ${process.pid}`);
    // CPU 개수만큼 워커를 생산
    for (let i = 0; i < 10; i += 1) {
      cluster.fork();
    }
    // 워커가 종료되었을 때
    cluster.on('exit', (worker, code, signal) => {
      console.log(`${worker.process.pid}번 워커가 종료되었습니다.`);
    });
  } else {
    // 워커들이 포트에서 대기
    http.createServer((req, res) => {
      res.write('<h1>Hello Node!</h1>');
      res.end('<p>Hello Cluster!</p>');
    }).listen(8085);
  
    console.log(`${process.pid}번 워커 실행`);
  }
  ```

  