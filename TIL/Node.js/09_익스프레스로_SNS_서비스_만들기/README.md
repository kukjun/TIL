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

   SQL( MySQL)을 데이터베이스로 사용함.

   ```consol
   npm i -g sequelize-cli
   ```

   `sequelize-cli` sequelize 커맨드 사용을 위함.

   ```consol
   npm i sequelize mysql2
   ```

   node_modules 폴더와 package-lock.json 생성

   ```consol
   sequelize init
   ```

   config, migrations, models, seeders 폴더 생성

3. **다른 폴더와 app.js 생성**

   * `views` : 템플릿 파일을 넣을 폴더
   * `routes` : 라우터를 넣을 폴더
   * `public` : 정적 파일을 넣을 폴더
   * `passport` : passport 패키지를 위한 폴더
   * `app.js` : 익스프레스 서버 코드를 담은 파일

**위 과정은 express-generator과정을 직접 만든 것이다.**
고정된 구조가 아니기 때문에 편의에 따라 바꾸어도 된다.

4. **필요한 npm 패키지를 설치하고 app.js를 작성한다. 템플릿 엔진은 pug를 사용한다.**
   * 

## 데이터베이스 세팅하기

## Passport 모듈로 로그인 구현하기

## Multer 모듈로 이미지 업로드 구현하기

## 프로젝트 마무리하기

