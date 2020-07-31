# 6. 익스프레스 웹 서버 만들기

4장에서 직접 웹 서버를 만들 때 코드가 보기 좋지 않고 확장성도 떨어진다고 느꼈을 수 있다.
npm에는 서버 제작시 불편함을 해소하고 편의 기능을 추가한 웹 서버 프레임워크가 있다. 그 중 대표적인 것이 익스프레스이다.

**익스프레스**는 http모듈의 요청과 응답 객체에 추가 기능들을 부여했다. 기존 메서드들도 게속 사용할 수 있지만, 편리한 메서드들을 추가하여 기능을 보완했다. 코드를 분리하기 쉽게 만들어 관리하기도 용이하다. 그리고 if문으로 요청 메서드와 주소를 구별하지 않아도 된다.

## 6.1 Express-generator로 빠르게 설치하기

익스프레스 프레임워크는 익스프레스 외에도 많은 패키지를 사용하므로 입문자 입장에서 필요한 패키지를 찾아서 설치하기 어렵다. 다행히 프레임워크에 필요한 package.json을 만들어주고 기본 폴더 구조까지 잡아주는 패키지가 있다. 바로 Express-generator이다.

Express-generator를 전역 설치해보자.

```Consol
npm i -g express-generator
```

설치 완료 후 새 익스프레스 프로젝트를 생성해보자. 생성 프로젝트를 만들고자 하는 폴더로 이동해서 express <프로젝트 이름>을 입력한다.

```consol
express learn-express --view=pug
```

* **-- view=pug**?

  Express-generator는 기본적으로 Jade를 템플릿 엔진으로 설치한다. 하지만 Jade는 Pug로 개명했기 때문에 최신 버전인 Pug를 설치하기 위해서 express-generator에 옵션을 주었다.
  Pug대신 EJS를 템플릿 엔진으로 쓰고 싶으면 `--view=ejs`를 사용하면 된다.

폴더로 이동 후 npm 설치 명령어를 실행한다.

```consol
cd learn-exprewss && npm i
```

![image-20200731133206101](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200731133206101.png)

설치가 완료된 다음 폴더 안 내용이다.

* app.js

  핵심적인 서버 역할을 함.

* bin/www

  서버를 실행하는 스크립트.

* public

  외부(브라우저 등의 클라이언트)에서 접근 가능한 파일들을 모아둔 곳으로, 이미지, 자바스크립트, CSS파일이 들어있다.

* routes

  주소별 라우터들을 모아둔 곳
  앞으로 서버의 로직은 routes 폴더 안의 파일에 작성할 것이다.

* views

  템플릿 파일을 모아둔 곳

start 명령을 통해 시작할 수 있다.

```consol
npm start
```

<br>

## 6.2 익스프레스 구조 이해하기

 

## 6.3 미들웨어

미들웨어는 익스프레스의 핵심이다. 요청과 응답 중간에 위치하여 미들웨어라고 부른다.
뒤에 나오는 라우터와 에러 핸들러 또한 미들웨어의 일종으로 미들웨어가 익스프레스의 거의 대부분을 차지한다.
미들웨어는 요청과 응답을 조작하여 기능을 추가하기도 하고 나쁜 요청을 걸러내기도 한다. 미들웨어는 app.use와 함께 사용된다.

### 커스텀 미들웨어 만들기

### morgan

요청에 대한 정보를 콘솔에 기록해주는 미들웨어

* 사용 형태

  ```javascript
  ...
  var logger = require('organ');
  ...
  app.use(logger('dev'));
  ...
  ```

  함수의 인자를 바꾸면 다른 결과를 가질 수 있다.

* 함수 인자

  * dev
    순서대로 HTTP요청(GET)주소)(/) HTTP상태코드(200) 응답속도( 51.267ms) - 응답바이트(1539)
    개발 시 많이 사용
  * short
    개발 시 많이 사용
  * common, combined
    배포시 많이 사용

### body-parser

요청의 본문을 해석해주는 미들웨어이다. 보통 폼 데이터나 AJAX 요청의 데이터를 처리한다.

* 사용 형태

  ```javascript
  ...
  var bodyParser = require('body-praser');
  ...
  app.use(bodyParser.json());
  app.use(bodyParser.urlencoded({ exptend: false}))
  ```

익스프레스 4.16.0 버전부터 body-parser의 일부 기능이 익스프레스에 내장되어 있어서 require을 하지 않고 사용해도 된다.
단, Raw, Text 형식의 본문을 추가로 해석할 경우 body-praser를 추가해줘야 한다.

* Raw
  : 본문이 버퍼 데이터인 경우 해석하는 미들웨어

* Text
  : 본문이 텍스트 데이터인 경우 해석하는 미들웨어

* JSON
  : JSON 형식의 데이터 전달 방식

* URL-encoded
  : 주소 형식으로 데이터를 보내는 방식

  보통 폼 전송이 URL-encoded 방식을 주로 사용한다.

  * urlencoded 메서드를 보면 { extended: false }라는 옵션이 있다. 이 옵션이 false이면 노드의 querystring 모듈을 사용하여 쿼리스트링을 해석하고, true이면 qs 모듈을 사용하여 쿼리 스트링을 해석한다.
    * qs모듈은 npm 패키지로, querystring 모듈의 기능을 조금 더 확장한 모듈이다.

POST, PUT 요청의 본문을 전달받으려면 req.on('data')와 req.on('end')로 스트림을 사용해야 했던것과는 다르게 body-parser를 사용하면 내부적으로 본문을 해석해 req.body에  추가해준다.

하지만 multiapart/form-data 같은 폼을 통해 전송된 데이터는 해석하지 못한다.

### cookie-parser

cookie-parser는 요청에 동봉된 쿠키를 해석해준다.

* 사용 형태

  ```javascript
  ...
  var cookieParser = require('cookie-parser');
  ...
  app.use(cookieParser());
  ...
  ```

해석된 쿠키들은 req.cookies 객체에 들어간다. 예를 들어 name=kukjun 쿠키를 보냈다면 req.cookies는 { name: 'kukjun' }가 된다.

`app.use(cookieParser('secret code'));`

와 같이 첫 번째 인자로 문자열을 넣어줄 수 있다. 서명된 쿠키가 있는 경우, 제공한 무낮열을 키로 삼아 복호화할 수 있다. 수정된 쿠키는 클라이언트에서 수정했을 때 에버가 발생하므로 클라이언트에서 쿠키로 위험한 행동을 하는 것을 방지할 수 있다.

### static

static  미들웨어는 정적인 파일들을 제공한다.
익스프레스에 내장되어 있으므로 따로 설치할 필요가 없다.

* 사용 형태

  ```javascript
  ...
  app.use(express.static(path.join(__dirname, 'public')));
  ...
  ```

함수의 인자로 정적 파일이 담겨 있는 폴더를 지정하면 된다.

## 6.4 Router 객체로 라우팅 분리하기

## 6.5 템플릿 엔진 사용하기