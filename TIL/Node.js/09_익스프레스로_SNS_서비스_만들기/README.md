# 익스프레스로 SNS 서비스 만들기

지금까지 배운 것들을 바탕으로 실제 웹 서비스를 제작한다.

* Nodebird 제작

==async/await 자주 사용==

<br>

## 프로젝트 구조 갖추기

> Express-generator를 사용하지 않고 직접 폴더와 파일을 생성하고 연결하면서 구조를 익힌다.

1. **nodebird 폴더를 만들고 안에 `package.json`을 생성한다.** 

   직접 만들거나, `npm init`명령 중 아무거나 사용.

   * `package.json`

     ```json
     {
       "name": "nodebird",
       "version": "0.0.1",
       "description": "익스프레스로 만드는 SNS 서비스",
       "main": "app.js",
       "scripts": {
         "start": "nodemon app"
       },
       "author": "KukjunLee",
       "license": "kukjun",
     }
     ```

     `scripts - start`를 제외한 부분은 본인이 수정 가능

   <br>

2. **데이터베이스와 연동해야 하기 때문에 시퀼라이즈를 설치한다.**

   > SQL( MySQL)을 데이터베이스로 사용함.

   ```consol
   npm i -g sequelize-cli
   ```

   * `sequelize-cli` sequelize 커맨드 사용을 위함.

   ```consol
   npm i sequelize mysql2
   ```

   * node_modules 폴더와 package-lock.json 생성

   ```consol
   sequelize init
   ```

   * config, migrations, models, seeders 폴더 생성

3. **다른 폴더와 app.js 생성**

   * `views` : 템플릿 파일을 넣을 폴더
   * `routes` : 라우터를 넣을 폴더
   * `public` : 정적 파일을 넣을 폴더
   * `passport` : passport 패키지를 위한 폴더
   * `app.js` : 익스프레스 서버 코드를 담은 파일

**위 과정은 express-generator과정을 직접 만든 것이다.**
고정된 구조가 아니기 때문에 편의에 따라 바꾸어도 된다.

4. **필요한 npm 패키지를 설치하고 app.js를 작성한다. 템플릿 엔진은 pug를 사용한다.**

   ```consol
   npm i express cookie-parser express-session morgan connect-flash pug
   ```

   ```consol
   npm i -g nodemon
   npm i -D nodemon
   ```

   * 서버 코드에 수정 사항이 생길 때마다 매번 nodemon 모듈로 서버를 자동 재시작한다.
     * **nodemon은 개발용으로만 사용하는 것을 권장한다.**

5. **app.js 작성**

   * `app.js`

     콘솔 실행 명령어로 만들 필요가 없으므로 `bin/www`는 필요하지 않는다.

     라우터는 지금은 pageRouter만 있고, 404미들웨어, 에러 핸들링 미들웨어가 있다. 그리고 앱을 8001번 포트에 연결했다.

6. **비밀 키 연결 `dotenv`**

   cookieParser, express-session의 비밀키는 직접 하드코딩하지 않고 dotenv 패키지를 이용한다.

   ```consol
   npm i dotenv
   ```

   `.env` 파일을 생성하고 안에 `COOKIE_SECRET=nodebirdsecret`를 추가한다.

   * 키=값 형태로 비밀키가 추가된다. 
     비밀키는 .env파일에 모아두었다가 dotenv가 .env 파일을 읽어 process.env 객체에 넣는다.
     * config.json은 JSON 파일이므로 process.env를 사용할 수 없다.

   비밀키를  app.js로 불러수 있다.

   * `app.js`

     `require('dotenv').config();`를 호출하면 된다.
     이 이후로는 .env만 유출되지 않게 관리하면 된다.

7. **기본적인 라우터와 템플릿 엔진 만들기**

   * `routes/page.js`
   * `views/layout.pug`
   * `views/main.pug`
   * `views/profile.pug`
   * `views/join.pug`
   * `views/error.pug`

## 데이터베이스 세팅하기

> MySQL과 시퀼라이즈로 데이터베이스를 설정한다.

로그인 기능이 있으므로 사용자 테이블이 필요하고, 게시글을 저장할 게시글 테이블도 필요하다. 해시태그를 사용하므로 해시캐그 테이블도 만들어야 한다. 팔로잉 기능도 있다.



## Passport 모듈로 로그인 구현하기

SNS 서비스이므로 로그인이 필요하다. 회원가입과 로그인은 직접 구현할 수도 있지만 Passport를 사용하면 복잡한 작업을 생략할 수 있다.



## Multer 모듈로 이미지 업로드 구현하기

## 프로젝트 마무리하기

