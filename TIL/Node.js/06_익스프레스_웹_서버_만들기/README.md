# 6. 익스프레스 웹 서버 만들기

4장에서 직접 웹 서버를 만들 때 코드가 보기 좋지 않고 확장성도 떨어진다고 느꼈을 수 있다.
npm에는 서버 제작시 불편함을 해소하고 편의 기능을 추가한 웹 서버 프레임워크가 있다. 그 중 대표적인 것이 익스프레스이다.

**익스프레스**는 http모듈의 요청과 응답 객체에 추가 기능들을 부여했다. 기존 메서드들도 게속 사용할 수 있지만, 편리한 메서드들을 추가하여 기능을 보완했다. 코드를 분리하기 쉽게 만들어 관리하기도 용이하다. 그리고 if문으로 요청 메서드와 주소를 구별하지 않아도 된다.

* 익스프레스 외에도 koa, hapi등이 있으나 익스프레스의 사용자가 압도적으로 많다.

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
  화면 부분은 views 폴더 안에 작성할 것이다.

이렇게 구조가 명확하게 구분되어 있어 서버를 관리하기가 용이하다. 라우터를 컨트롤러로 본다면 MVC(모델-뷰-컨트롤러)패턴과도 비슷하다.

start 명령을 통해 시작할 수 있다.

```consol
npm start
```

실행한 후 http://localhost:3000 으로 접속하면 성공적을 접속되고 콘솔에는 추가적으로 클라이언트가 보낸 요청에 관한 정보가 기록된다.

![image-20200803172528035](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200803172528035.png)

http://localhost:3000/uesrs 에도 접근을 해보면 콘솔에 GET /users 요청이 기록된다.

![image-20200803172804075](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200803172804075.png)



<br>

## 6.2 익스프레스 구조 이해하기

익스프레스는 코드가 여러 개의 파일로 분산되어 있다. 각 부분마다 맡은 역할이 나누어져 있어 보기에도 좋고, 관리하기에도 좋다.

### bin/www

bin 폴더 아래에 들어 있는 www 파일이다.

* bin/www

  ```javascript
  #!/usr/bin/env node
  
  /**
   * Module dependencies.
   */
  
  var app = require('../app');
  var debug = require('debug')('learn-express:server'); // 콘솔에 로그를 남기는 모듈
  var http = require('http'); // 각 모듈들을 가져온다.
  
  /**
   * Get port from environment and store in Express.
   */
  
  var port = normalizePort(process.env.PORT || '3000');
  app.set('port', port);
  
  /**
   * Create HTTP server.
   */
  
  var server = http.createServer(app);
  
  /**
   * Listen on provided port, on all network interfaces.
   */
  
  server.listen(port);
  server.on('error', onError);
  server.on('listening', onListening);
  
  /**
   * Normalize a port into a number, string, or false.
   */
  
  function normalizePort(val) {
    var port = parseInt(val, 10);
  
    if (isNaN(port)) {
      // named pipe
      return val;
    }
  
    if (port >= 0) {
      // port number
      return port;
    }
  
    return false;
  }
  
  /**
   * Event listener for HTTP server "error" event.
   */
  
  function onError(error) {
    if (error.syscall !== 'listen') {
      throw error;
    }
  
    var bind = typeof port === 'string'
      ? 'Pipe ' + port
      : 'Port ' + port;
  
    // handle specific listen errors with friendly messages
    switch (error.code) {
      case 'EACCES':
        console.error(bind + ' requires elevated privileges');
        process.exit(1);
        break;
      case 'EADDRINUSE':
        console.error(bind + ' is already in use');
        process.exit(1);
        break;
      default:
        throw error;
    }
  }
  
  /**
   * Event listener for HTTP server "listening" event.
   */
  
  function onListening() {
    var addr = server.address();
    var bind = typeof addr === 'string'
      ? 'pipe ' + addr
      : 'port ' + addr.port;
    debug('Listening on ' + bind);
  }
  
  ```

  **bin/www 파일은 http 모듈에 express 모듈을 연결하고, 포트를 지정하는 부분이다.**

  * `#!/usr/bin/env node`

    www 파일을 콘솔 명령어로 만들 때 사용되는 주석. 전역 설치 후 rimraf와 같이 명령어로도 실행할 수 있다.

  * `var app = require('../app');
    var debug = require('debug')('learn-express:server');
    var http = require('http');`
    : app, debug, http 모듈을 가져온다.

  * `var port = normalizePort(process.env.PORT || '3000');
    app.set('port', port);`
    : `app.set('port', port)`로 서버가 실행될 포트를 설정한다. porcess.env 객체에 PORT 속성이 있다면 그 값을 사용하고, 없다면 기본값으로 3000번 포트를 이용하도록 하게 한다.
    `app.set(키, 값)`을 사용해서 데이터를 저장하고, 나중에 `app.get(키)`를 통해 가져올 수 있다.

  * `var server = http.createServer(app);`
    : http.createServer에 불러온 app 모듈을 넣는다. app모듈이 createServer 메서드의 콜백 함수 역할을 한다.

  * `server.listen(port);
    server.on('error', onError);
    server.on('listening', onListening);`
    : listen 하는 부분은 http 웹 서버와 동일하다. 동일하게 포트를 연결하고 서버를 실행한다. 익스프레스는 그저 콜백 함수 부분을 조금 다르게 만든 것이다.

### app.js

```javascript
var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
```



 next()는 미들웨어의 흐름을 제어하는 핵심적인 함수이다.

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

**실제 서버의 폴더 경로에는 public이 들어있지만, 요청 주소에는 public이 들어 있지 않기 때문에 외부인이 서버의 구조를 쉽게 파악할 수 없다.**

==check==

```javascript
app.use('/img', express.static(path.join(__dirname, 'public')));
```

이와 같이 정적 파일을 제공할 주소도 지정할 수 있다. public 폴더 안에 abc.png가 있다고 가정하면 앞에  /img 경로를 붙인 http://localhost:3000/img/abc.png 주소로 접근할 수 있다.

<br>

 static 미들웨어는 요청에 부합하는 정적 파일을 발견한 경우 응답으로 해당 파일을 전송한다. 
만약 파일을 찾지 못했다면 요청을 라우터로 넘긴다.

- 이처럼 자체적으로 정적 파일 라우터 기능을 수행하므로 최대한 위쪽에 배치하면 서버가 쓸데없는 미들웨어 작업을 하는 것을 막을 수 있다.

  ```javascript
  ...
  app.use(logger('dev'));
  app.ues(epress.static(path.join(__dirname, 'public')));
  app.use(express.json());
  app.use(express.urlencoded({ extended: false}));
  app.use(cokicParser());
  ...
  ```

  - 서비스에 따라 쿠키 같은 것이 정적 파일을 제공하는데 영향을 끼칠 수 있으므로 자신의 서비스에 맞는 위치를 선택하는 것이 좋다.

### express-session

세션 관리용 미들웨어이다. 로그인 등의 이유로 세션을 구현할 때 매우 유용하다. epress-generator로는 설치되지 않으므로 따로 설치해야한다. `npm i express-session`

설치 후에는 app.js에  express-session을 연결해야 한다.

* 사용 형태

  ```javascript
  ...
  var logger = require('morgan');
  var session = require('express-session');
  
  var indexRouter = require('./routes/index');
  var usersRouter = require('./routes/users');
  ...
  app.use(cookieParser('secret code'));
  app.use(session({
      resave: false,
      saveUninitialized: false,
      secret: 'secret code',
      cookie: {
      	httpOnly: ture,
      	secure: false,
  	},
  }));
  ...
  ```

  express 1.5 버전 이전에는 내부적으로 cookie-parser를 사용하고 있어서  cookie-parser 미들웨어보다 뒤에 위치해야 했지만 이후 버전에서는 순서가 상관이 없어졌다.

  * express-session은 인자로 세션에 대한 결정을 받는다.
  * resave는 요청이 왔을 때 세션에 수정사항이 생기지 않더라도 세션을 다시 저장할지에 대한 설정이다.
  * sabeUninitialized는 세션에 저장할 내역이 없더라도 세션을 저장할지에 대한 설정이다.
    보통 방문자를 추척할 대 사용된다.
  * secret은 필수 항목으로 cookie-parser의 비밀키와 같은 역할을 한다.

  express-session은 세션 관리 시 클라이언트에 쿠키를 보낸다 이를 **세션쿠키**라고 부른다. 안전하게 쿠키를 전송하려면 쿠키에 서명을 추가해야 하고, 쿠키를 서명하는데 secret의 값일 필요하다. cookie-parser의 secret과 같게 설정해야 한다.

  * cookie 옵션은 세션 쿠키에 대한 설정이다. 일반적인 쿠키 옵션이 모두 제공된다.

    * httpOnly를 사용해 클라이언트에서 쿠키를 사용하지 못하게 했다.
    * secure는 false로 해서  https가 아닌 환경에서도 사용할 수 있게 했다.

    배포 시, 둘다 true로 설정하는 것이 좋다.

    예제 코드에는 없지만 store 옵션도 있다.

    * store 옵션을 사용하면 데이터베이스에 세션을 저장할 수 있다. 보통 레디스를 자주 사용한다.

express-session은 req객체에 req.session을 만든다. 이 객체에 값을 대입하거나 삭제해서 세션을 변경할 수 있다. 나중에 세션을 한번에 삭제하려면 req.session.destory() 메서드를 호출하면 된다. 현재 세션의 아이디는 req.sessionID로 확인할 수 있다.

### connect-flash

일회성 메시지들을 웹 브라우저에 나타낼 떄 좋다. 직접 설치해주어야 한다. `npm i connect-flash`

connect-flash 미들웨어는 cookie-parser와 express-session을  사용하므로 이들보다는 뒤에 위치해야 한다.

* 사용 형태

  ```javascript
  var session = require('express-session');
  var flash = require('connect-flash');
  
  var indexRouter = require('./routes/index');
  var usersRouter = require('./routes/users');
  ...
  app.use(session({
    resave: false,
    saveUninitialized: false,
    secret: 'secret code',
      cookie: {
        httpOnly: ture,
        secure: false,
      },
  }));
  app.use(flash());
  ...
  ```

  * flash 미들웨어는 req 객체에 req.flash 메서드를 추가한다. req.flash(키, 값)으로 해당 키에 값을 설정하고 req.flash(키)로 해당 키의 대한 값을 불러온다.

flash와 세션을 테스트하기 위해 임시로 라우터를 만들었다. 라우터는 다음 절에서 설명한다.

* routes.user.js

  ```javascript
  var express = require('express');
  var router = express.Router();
  
  /* GET home page. */
  router.get('/', function(req, res, next) {
    res.render('index', { title: 'Express' });
  });
  
  router.get('/flash', function(req, res, next) {
    res.session.message = '세션 메시지';
    req.falsh('message', 'flash 메시지');
    res.redirect('/users/flash/result');
  });
  
  router.get('/flash/result', function(req, res) {
    res.send(`${req.session.message} ${req.flash('message')}`);
  });
  
  module.exports = router;
  ```

  첫번재 /users/flash/result에는 세션 메시지와  flash메시지가 모두 보인다. 하지만 재방문시에는 flash메시지가 보이지 않는다. 이러한 성질을 이용해서 로그인 에러나 회원가입 에러 같은 일회성 경고 메시지는 flash 미들웨어로 보내면 좋다.

매 요청마다 연결된 모든 미들웨어가 실행되므로 꼭 필요한 미들웨어만을 사용해야 한다.

**리다이렉트**

<br>

## 6.4 Router 객체로 라우팅 분리하기

if문으로 분기를 만들면 보기에도 좋지 않고 확장하기도 어렵다. 라우팅을 통해서 깔끔하게 관리할 수 있다.

* 사용 형태

  ```javascript
  ...
  var indexRouter = require('./routes/index');
  var usersRouter = require('./routes/users');
  ...
  app.use('/', indexRouter);
  app.use('/users', usersRouter);
  ...
  ```

  app.use를 사용하므로 미들웨어의 일종으로 볼 수 있다.

  * 첫번째 인자로 주소를 받으므로 특정 주소에 해당하는 요청이 왔을 때만 미들웨어가 동작하게 할 수 도 있다.

  * use 대신 get, post .. 등등 같은 HTTP 메서드들도 사용할 수 있다.

    ```javascript
    app.use('/', function(req, res, next) {
      console.log('/ 주소의 요청일 때 실행됩니다. HTTP 메서드는 상관없습니다');
      next();
    });
    app.get('/', function(req, res, next) {
      console.log('GET 메서드 / 주소의 요청일 때만 실행됩니다');
      next();
    });
    app.post('/data', function(req, res, next) {
      console.log('POST 메서드 /data 주소의 요청일 때만 실행됩니다');
      next();
    });
    ```

    * use 메서드는 모든 HTTP 메서드에 대해 요청 주소만 일치하면 실행되지만 use 메서드를 제외한 메서드들은 주소뿐만 아니라 HTTP 메서드까지 일치하는 요청일 때만 실행된다.

라우터를 살펴보면,

**routes/index.js**

```javascript
var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title:'Express' });
});

module.exports = router;
```

**routes/users.js**

```javascript
var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

module.exports = router;
```

router 객체는 express.Router()로 만들었다.
router에도 app처럼 다른 HTTP 메서드 들을 붙일 수 있다. use를 제외하고는 각각 HTTP 요청 메서드와 상응한다.

또, app.use처럼 router 하나에 미들웨어를 여러 개 장착할 수도 있다. 실제 라우터 로직이 실행되는 미들웨어 전에 로그인 여부 또는 관리자 여부를 체그하는 미들웨어를 중간에 넣어두곤 한다.
`router.get('/', middleware1, middleware2, middleware3);`

`router.get('/')`이면 / 주소로 GET 요청을 하는 것과 같다. res.render 메서드로 클라이언트에 응답을 보낸다. 익스프레스가 응답 객체에 새로 추가한 메서드이다. 이 메서드는 템플릿 엔진을 사용하는 부분이다.

users.js에서도 router.get(' / ')부분이 있다. 그래서  /users/로 GET요청을 했을 때 이 라우터의 콜백 함수가 실행된다.

사실 라우터`express.Router()`를 사용할 필요 없이 app.js에서 `app.get('/', 미들웨어)`, `app.get('/users', 미들웨어)`를 해도 기능은 동일하다. 하지만 **코드 관리를 위해 라우터를 별도로 분리**하는 것이다.

라우터에서는 반드시 요청에 대한 응답을 보내거나 에러 핸들러로 요청을 넘겨야 한다. 응답을 보내지 않으면 브라우저는 응답을 계속 기다린다. 응답에 제한 시간이 있으므로 영원히 기다리지는 않지만 기다리는 동안 다른 동작을 수행할 수 없을수도 있다. res 객체에 들어 있는 메서드들로 응답을 보낸다.

* next 함수에는 라우터에서만 동작하는 특수 기능이 있다. next(' route ')를 써서 라우터에 연결된 나머지 미들웨어들을 건너뛸 수 있다.

----

라우터의 주소에는 특수한 패턴을 사용할 수 있다.

* ```javascript
  router.get('/users/:id', function(req, res) {
    console.log(req.params, req.query);
  });
  ```

  주소의 :id에 다른 값을 넣을 수 있다.

  req.params 객체 안에 들어 있으므로, :id면 req.params.id로, :type이면 req.params.type으로 조회할 수 있다.

주소에 쿼리스트링을 쓸 때도 있다. 쿼리스트링의 키-값 정보는 req.params객체 안에 들어있다.
단, 일반 라우터보다 뒤에 위치해야 다른 라우터들을 방해하지 않는다.

에러가 발생하지 않았다면 라우터는 요청을 보낸 클라이언트에게 응답을 보내주어야 한다. 응답 메서드는 여러 가지지만 이 책에서는 send, sendFIle, json, redirect, render를 주로 사용한다.

* send `res.send(버퍼 또는 문자열 또는 HTML 또는 JSON)`
  : 만능 메서드로 버퍼 데이터나 문자열을 전송하거나, HTML 코드를 전송하기도 하고, JSON 데이터도 전송할 수 있다.
* sendFile `res.send(버퍼 또는 문자열 또는 HTML 또는 JSON)`
  :파일을 응답으로 보내주는 메서드
* json `res.json(JSON 데이터);`
  : JSON 데이터를 보내준다.
* redirect `res.redirect(주소);`
  : 응답을 다른 라우터로 보내 버린다.
  * 로그인 완료 후 다시 메인 화면으로 돌아갈 때 res.redirect(메인 화면 주소)를 입력하면 된다.
* render `res.render('템플릿 파일 경로', { 변수 });`
  : 템플릿 엔진을 렌더링할 때 사용한다. view 폴터 안 pug 확장자를 가지고 있는 파일들이 템플릿 엔진이다.

기본적으로 200 HTTP 상태코드를 응답하지만 (res.redirect는 302), 직접 바꿔줄 수도 있다. 다음과 같이 status 메서드를 먼저 사용하면 된다.

**하나의 요청에 하나의 응답만 보내야 한다.**

마지막으로 라우터가 요청을 처리하지 못하는 경우, 다음 미들웨어로 넘어간다. 404 HTTP 상태 코드를 보내주어야 하므로 다음 미들웨어에서 새로운 에러를 만들고 에러의 상태코드를 404로 설정한 뒤 에러 처리 미들웨어로 넘겨 버린다.

* 사용 형태

  ```javascript
  ...
  // 404 처리 미들웨어
  app.use(function(req, res, next) {
    next(createError(404));
  });
  
  // 에러 핸들러
  app.use(function(err, req, res, next) {
    // set locals, only providing error in development
    res.locals.message = err.message;
    res.locals.error = req.app.get('env') ==='development' ? err : {};
  
    // render the error page
    res.status(err.status || 500);
    res.render('error');
  });
  ...
  ```

  

## 6.5 템플릿 엔진 사용하기

HTML을 사용하다보면 반복되는 코드들도 일일이 코딩해서 넣어주어야 한다. 템플릿 엔진은 자바 스크립트를 사용해서 HTML을 렌더링할 수 있게 해준다. 따라서 기존 HTML과는 문법이 살짝 다를 수도 있고, 자바스크립트 문법이 들어 있기도 하다.
대표적으로 **Pug**와 **EJS**가 있다.

### Pug(Jade)

Pug는 예전 이름이 Jade인 템플릿 엔진으로 꾸준한 인기를 얻고 있다. 문법이 간단하여 코드의 양이 줄어들기 때문이다. Ruby와 문법이 비슷하지만 HTML과는 문법이 많이 달라서 호불호가 갈린다.

사용하려면 app.js에 다음 부분을 추가해야한다.

* app.js

  ```javascript
  ...
  app.set('views', path.join(__dirname, 'views'));
  app.set('view engine', 'pug');
  ...
  ```

  * views
    : 템플릿 파일들이 위치한 폴더를 지정하는 것이다. res.render 메서드가 이 폴더 기준으로 템플릿 엔진을 찾아서 렌더링한다.

    * ex

      res.render(' index ')라면 views/index.pug를 렌더링한다.

      res.render(' admin/main ')라면 views/admin/main.pug를 렌더링한다.

  * view engine
    : 어떤 종류의 템플릿 엔진을 사용할지를 나타낸다.

#### HTML과 Pug의 표현 비교

**Pug는 HTML과 다르게 화살괄호와 닫는 태그가 없다.**
탭, 스페이스로만 태그의 부모 자식 관계를 규명한다. 모든 파일에 동일한 종류의 들여쓰기를 적용하면 된다. 들여쓰기에 오류가 있으면 제대로 렌더링되지 않으니 주의한다.

화살 괄호가 없으므로 태그명 뒤에 소괄호로 묶어 적어준다.

* HTML

  ```html
  <!DOCTYPE html>
  <html>
      <head>
          <title>익스프레스</title>
          <link rel="stylesheet" href="/stylesheets/style.css">
      </head>
  </html>
  ```

* Pug

  ```pug
  doctype html
  html
    head
      title= title
      link(rel='stylesheet', href='/stylesheets/style.css')
  ```

<br>

속성 중 아이디와 클래스가 있는 경우에는 다음과 같이 표현할 수 있다. div 태그인 경우 div 문자는 생략할 수 있다.

* HTML

  ```html
  <div id="login-button"></div>
  <div class="post-image"></div>
  <span id="highlight"></span>
  <p class="hidden full"></p>
  ```

* Pug

  ```pug
  #login-button
  .post-image
  span#highlight
  p.hidden.full
  ```

<br>

HTML 텍스트는 다음과 같이 태그 또는 속성 뒤에 한 칸을 띄고 입력하면 된다.

* HTML

  ```html
  <p>Welcome to Express</p>
  <button type="submit">전송</button>
  ```

* Pug

  ```pug
  p Welcome to Express
  button(type='submit') 전송
  ```

<br>

pug에서 텍스트를 여러 줄로 입력하고 싶으면 파이프(|)를 넣어주면 된다. HTML 코드에서는 한 줄로 나온다.

* HTML

  ```html
  <p>안녕하세요. 여러 줄을 입력합니다.<br />태그도 중간에 넣을 수 있습니다.</p>
  ```

* Pug

  ```pug
  p
    | 안녕하세요.
    | 여러 줄을 입력합니다.
    br
    | 태그도 중간에 넣을 수 있습니다.
  ```

<br>

style이나 sript 태그로 CSS 또는 자바스크립트 코드를 작성하려면 태그 뒤에 점(.)을 붙여준다.

* HTML

  ```html
  <style>
      h1 {
          font-size: 30px;
      }
  </style>
  <script>
      var message ='Pug';
      alert(message);
  </script>
  ```

* Pug

  ```pug
  style.
    h1 {
      font-size: 30px;
    }
  script.
    var message ='Pug';
    alert(message);
  ```

<br>

#### 변수

HTML과 다르게 자바스크립트 변수를 템플릿에 렌더링할 수 있다. res.render 호출 시 보내는 변수를 Pug가 처리해준다. routes/index.js의 코드를 보면 다음 부분이 있다.