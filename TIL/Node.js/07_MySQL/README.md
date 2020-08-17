# . My SQL

 서버의 데이터를 변수에 저장하면, 서버가 종료되면 메모리가 정리되면서 저장했던 데이터들도 사라지게 된다. 이를 방지하기 위해서 데이터 베이스를 사용해야 한다.

## 7.1 데이터베이스란?

데이터베이스는 관련성을 가지며 중복이 없는 데이터들의 집합이다. 이러한 데이터베이스를 관리하는 시스템을 DBMS라고 한다.

보통 서버의 하드 디스트나 SSD 등의 저장 매체에 데이터를 저장한다. 저장 매체가 고장나거나 사용자가 지우지 않는이상 데이터가 보존되므로 서버 종료 여부와 상관없이 데이터를 계속 사용할 수 있다.

### DBMS

데이터베이스를 관리하는 시스템

RDBMS라고 부르는 관계형 DBMS가 많이 사용된다.

## 7.2 MySQL 설치하기



## 7.3 워크벤치 설치하기

## 7.4 데이터베이스 및 테이블 생성하기

워크벤치를 사용하는 방법 (GUI)과 프롬프트를 사용하는 방법(CLI)이 있다.

CLI 사용시에는 먼저 MySQL에 접속해야한다. MySQL의 bin폴더 경로에서 명령 프롬프트 실행

```
mysql -h localhost -u root -p
```

### 데이터베이스

#### 생성

데이터 베이스를 생성함

* Syntax

  ```mysql
  CREATE SCHEMA <database_name>;
  ```

  * MYSQL에서 SCHEMA는 데이터베이스와 같은 개념임
  * `CREATE SCHEMA`와 같이 MySQL이 기본적으로 알고 잇는 구문을 **예약어**라고 한다. 예약어는 소문자로 써도 되지만 **사용자 정의 이름과 구분하기 위해 대문자로 쓰는 것이 좋다.**

* ex

  ```mysql
  CREATE SCHEMA nodejs;
  ```


<br>

#### 사용

데이터베이스를 사용함

* Syntax

  ```mysql
  use <database_name>;
  ```

* ex

  ```mysql
  use nodejs;
  ```


<br>

### 테이블

데이터가 들어갈 수 있는 틀을 의미한다. 테이블에 맞는 데이터만 들어갈 수 있다. 

#### 생성

테이블을 생성함

* Syntax

  ```mysql
  CREATE TABLE <database_name.table_name> (<column-definition>);
  ```
  * `<column-definition>`

    테이블을 구성하는 컬럼 이름과 컬럼 도메인 정보 등을 지정

    * Syntax `<column-definition>`

      ```mysql
      <column_name> <datatype>
      	[UNSIGNED]
      	[ZEROFILL]
      	[NOT NULL | NULL]
      	[AUTO_INCREMENT]
      	[DEFAULT <default_value>],
      	
      [PRIMARY KEY(<column_name>)],
      [UNIQUE INDEX <index_name> (<column_name> [ASC | DESC]))]
      	
      [COMMENT = 'text']
      <DEFAULT CHARSET=<encording_type>>
      <ENGINE=<engine_type>>
      ;
      ...
      ```

      **컬럼 설정**

      * `<column_name>` : 컬럼의 이름
      * `<datatype>` : 컬럼의 데이터 타입
        * `INT` : 정수를 의미
        * `VARCHAR(자릿수)` : 가변길이 문자열
        * `TINYINT` : -127부터 128까지의 정수를 저장할 때 사용, 1또는 0만 저장하면 불값(Boolean)과 같은 역할을 수행함
        * `TEXT` : VARCHAR로 처리하기에 긴 문자열을 처리
        * `DATETIME` : 날짜와 시간에 대한 정보를 담고 있다.
      * `[UNSIGNED]` : 숫자 자료형에 적용되는 옵션. 음수를 무시하고 양수로만 값은 저장함. `FLOAT`, `DOUBLE`형은 사용할 수 없음
      * `[ZEROFILL]` :숫자의 자릿수가 고정되어 있을 때 사용하는 옵션 `INT(4)`에서 1을 0001로 표기할 수 있음.
      * `[NOT NULL | NULL]` : 빈칸을 허용할지 묻는 옵션
      * `[AUTO_INCREMENT]` : 숫자를 저절로 올리는 옵션. 데이터를 넣으면 1부터 값을 1씩 증가시켜 적용함
      * `[DEFAULT <default_value>]` : 컬럼의 값이 없을 때 기본 값을 대신 넣어주는 옵션
      * `[PRIMARY KEY(<column_name>)]` : 기본키를 설정함. 데이터베이스가 별도로 칼럼을 관리하므로 조회 시 속도가 빠르다.
      * `[UNIQUE INDEX <index_name> (<column_name> [ASC | DESC]))]` : 해당 값이 고유해야 하는지에 대한 옵션. 데이터베이스가 별도로 칼럼을 관리하므로 조회 시 속도가 빠르다.

      **테이블 자체 설정**

      * `[COMMENT = 'text']` : 테이블에 대한 보충 설명을 의미.
      * `<DEFAULT CHARSET=<encording_type>>` : 인코딩 타입을 설정. uft8로 설정해야 한글이 입력됨
      * `<ENGINE=<engine_type>>` : 엔진을 설정함. MySIAM과 InnoDB가 많이 사용

* ex

  사용자 정보를 저장하는 테이블

  ```mysql
  CREATE TABLE nodejs.users (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  age INT UNSIGNED NOT NULL,
  married TINYINT NOT NULL,
  comment TEXT NOT NULL,
  create_at DATETIME NOT NULL DEFAULT now(),
  PRIMARY KEY(id),
  UNIQUE INDEX name_UNIQUE (name ASC))
  COMMENT = '사용자 정보'
  DEFAULT CHARSET=utf8
  ENGINE=InnoDB;
  ```

  사용자 댓글을 저장하는 테이블

  ```mysql
  CREATE TABLE nodejs.comments (
  id INT NOT NULL AUTO_INCREMENT,
  commenter INT NOT NULL,
  comment VARCHAR(100) NOT NULL,
  created_at DATETIME NOT NULL DEFAULT now(),
  PRIMARY KEY(id),
  INDEX commenter_idx (commenter ASC),
  CONSTRAINT commenter
  FOREIGN KEY (commenter)
  REFERENCES nodejs.users (id)
ON DELETE CASCADE
  ON UPDATE CASCADE)
  COMMENT = '댓글'
  DEFAULT CHARSET=utf8
  ENGINE=InnoDB;
  ```
  

<br>

#### 확인

만들어진 테이블을 확인하는 명령

* Syntax

  ```mysql
  DESC <table_name>;
  ```

* ex

  ```mysql
  DESC users;
  ```

만들어진 모든 테이블을 확인하는 명령

* Syntax

  ```mysql
  SHOW TABLES;
  ```

<br>

#### 제거

테이블을 잘못 만들었을 경우 제거하는 명령

* Syntax

  ```mysql
  DROP TABLE <table_name>;
  ```

* ex

  ```mysql
  DROP TABLE users;
  ```

<br>


### FOREIGN KEY

외래 키라고 부르며 다른 테이블의 기본키를 저장한다.

* Syntax

  ```mysql
  FOREIGN KEY <Table Constraint> ::=
  
  [ CONSTRAINT <constraint_name> ]
  FOREIGN KEY (<column_name>) ]
  	REFERENCES referenced <database_name.table_name (column)>
  ```


## 7.5 CRUD 작업하기

CRUD란 Create, Read, Update, Delete의 두문자어로, 데이터베이스에서 많이 하는 작업 네가지를 일컫는다.
CRUD 작업을 하는 방법만 익혀도 웬만한 프로그램은 다 만들 수 있을 정도로 많이 사용된다.

<br>

### Create(생성)

데이터를 생성해서 데이터베이스에 넣는 작업이다.

* Syntax

  ```mysql
  INSERT INTO <database_name.table_name> [(<column_name>[, column_name, ...])]
  VALUES ({expression|DEFAULT}, ...) [, (...), ...];
  ```

  * `database_name.table_name` : 데이터를 삽입할 테이블을 지정
    * `use <database>` 명령어를 사용했다면 `table_name`만 입력해도 된다.
  * `VALUES` : 삽입할 데이터 값
  * `expression` : 컬럼에 입력할 값을 나열하면, 기본 값을 사용하고 싶을 때에는 DEFAULT 키워드 사용

* ex

  `nodejs.users`에 데이터 삽입

  ```mysql
  INSERT INTO nodejs.users (name, age, married, comment) VALUES ('zero', 24, 0, '자기소개1');
  ```

  ```mysql
  INSERT INTO nodejs.users (name, age, married, comment) VALUES ('nero', 32, 1, '자기소개2');
  ```

  * `id`는 `AUTO_INCREMENT`에 의해 자동으로 들어감.
  * `created_at`은 `DEFAULT` 값이 자동으로 들어감.

  `nodejs.comments`에 데이터 삽입

  ```mysql
  INSERT INTO nodejs.comments (commenter, comment) VALUES (1, '안녕하세여 zero의 댓글입니다.');
  ```

### Read(조회)

Read는 데이터베이스에 있는 데이터를 조회하는 작업이다.

* Syntax

  ```mysql
  SELECT target_column FROM table_name
  [WHERE <query_condition>]
  [ORDER BY <column_name>]
  [ LIMIT <number> [OFFSET <number>] ];
  ```

  * `target_column`

    조회할 컬럼 리스트

  * `table_name`

    조회할 대상 테이블

  * `query_condition`

    조회하고자 하는 테이블 내의 대상을 지정

  * `ORDER BY`

    column_name 기준으로 내림차순 정렬

    * `DESC`

      오름차순으로 정렬

  * `LIMIT <number> [OFFSET <number>]`

    조회 할 로우의 개수를 설정

    * `OFFSET <number>`

      건너 뛸 로우의 개수를 설정

* ex

  `nodejs.users` 전체 대상 조회

  ```mysql
  SELECT * FROM nodejs.users;
  ```

  `nodejs.commnets` 전체 대상 조회

  ```mysql
  SELECT * FROM nodejs.comments;
  ```

  `nodejs.users `이름과 결혼 여부만 조회

  ```mysql
  SELECT name, married FROM nodejs.users;
  ```

  `nodejs.users` 결혼을 했고 나이가 30세 이상인 사용자를 조회

  ```mysql
  SELECT name, age, married
  FROM nodejs.users
  WHERE age >= 30
  AND married = 1;
  ```

  `nodejs.users` 결혼을 안했거나 나이가 30세 초과인 사용자를 조회

  ```mysql
  SELECT id, name
  FROM nodejs.users
  WHERE married = 0
  OR age > 30;
  ```

  `nodejs.users` 나이가 많은 순서대로 정렬

  ```mysql
  SELECT id, name
  FROM nodejs.users
  ORDER BY age DESC;
  ```

  `nodejs.users` 조회할 로우 1개

  ```mysql
  SELECT id, name
  FROM nodejs.users
  ORDER BY age DESC
  LIMIT 1;
  ```

  `nodejs.users` 조회할 로우 1개, 건너뛸 로우 1개

  ```mysql
  SELECT id, name
  FROM nodejs.users
  ORDER BY age DESC
  LIMIT 1 OFFSET 1;
  ```

### Update(수정)

Update는 데이터베이스에 있는 데이터를 수정하는 작업이다.

* Syntax

  ```mysql
  UPDATE <table_name> SET column_name={expression|DEFAULT}
  					[, column_name={expression|DEFAULT}] ...
  [WHERE <query_condition>]
  ```

  * **WHERE  필수**

* ex

  `nodejs.users` id가 2인 data의 commet를 '바꿀 내용'으로 변경

  ```mysql
  UPDATE nodejs.users SET comment = '바꿀 내용'
  WHERE id = 2;
  ```

### Delete(삭제)

Delete는 데이터베이스에 있는 데이터를 삭제하는 작업이다.

* Syntax

  ```mysql
  DELETE FROM <table_name> [WHERE <query_condition>];
  ```

  * **WHERE 필수**

* ex

  `nodejs.users` id가 2인 data 삭제

  ```mysql
  DELETE FROM nodejs.users WHERE id = 2;
  ```


## 7. Sequelize 사용하기

MySQL 작업을 쉽게 할 수 있도록 도와주는 라이브러리

Sequelize는 ORM으로 분류된다.

* ORM(Object-relational Mapping)

  자바스크립트 객체와 데이터베이스의 릴레이션을 매핑해주는 도구

Sequelize를 사용하면 자바 스크립트 구문을 알아서 SQL로 바꾸어준다. 따라서 자바스크립트만으로 MySQL을 조작할 수 있다.

#### Install

1. Express-generator로 새 프로젝트를 생성하고 Sequelize를 설치한다.

   ```consol
   express learn-sequelize --view=pug
   ```

2. 완료 후 learn-sequelize 폴더로 이동해 npm 패키지들을 설치한다.

   ```consol
   cd learn-sequelize
   ```

   ```consol
   npm i
   ```

3. 시퀼라이즈에 필요한 sequelize와 mysql2 패키지를 설치하고 sequelize 커맨드 사용을 위해 sequelize-cli를 전역 설치한다. 설치 후 sequelize init 명령을 호출한다.

   ```consol
   npm i sequelize mysql2
   ```

   ```consql
   npm i -g sequelize-cli
   ```

   ```consol
   sequelize init
   ```

4. `models/index.js` 내용 안에 오류가 많이 발생하므로 수정

   * `models/index.js`

     ```javascript
     const path = require('path');
     const Sequelize = require('sequelize');
     
     const env = process.env.NODE_ENV ||'development';
     const config = require(path.join(__dirname,'..','config','config.json'))[env];
     const db = {};
     
     const sequelize = new Sequelize(config.database, config.username, config.password, config);
     
     db.sequelize = sequelize;
     db.Sequelize = Sequelize;
     
     module.exports = db;
     ```

<br>

### MySQL 연결하기

Sequelize를 통해 express.app과 MySQL을 연결한다. app.js에서 추가한다.

* app.js

  ```js
  ...
  var indexRouter = require('./routes/index');
  var usersRouter = require('./routes/users');
  var sequelize = require('./models').sequelize;
  
  var app = express();
  sequelize.sync();
  ...
  ```

### 모델 정의하기

MySQL에서 정의한 테이블을 Sequelize에서도 정의해야 한다. MySQL의 테이블은 Sequelize 모델과 대응된다.
시퀼라이즈는 모델과 MySQL의 테이블을 연결해주는 역할을 한다.

 User와 Comment 모델을 만들어 users 테이블과 comments 테이블에 연결한다. 시퀄라이즈는 기본적으로 모델 이름은 단수형으로, 테이블 이름은 복수형으로 사용한다.

1. User 모듈을 만든다.

   일반적으로 모듈은 단수형, 테이블은 복수형 이름을 사용한다.

   * `models/user`

     ```js
     module.exports = (sequelize, DataTypes) => {
       return sequelize.define('user', {
         name: {
           type: DataTypes.STRING(20),
           allowNull: false,
           unique: true,
         },
         age: {
           type: DataTypes.INTEGER.UNSIGNED,
           allowNull: false,
         },
         married: {
           type: DataTypes.BOOLEAN,
           allowNull: false,
         },
         comment: {
           type: DataTypes.TEXT,
           allowNull: true,
         },
         created_at: {
           type: DataTypes.DATE,
           allowNull: false,
           defaultValue: sequelize.literal('now()'),
         },
       }, {
         timestamps: false,
       });
     };
     ```

     sequelize는 알아서 id를 기본 키로 연결하므로 id칼럼을 따로 적어줄 필요가 없다.

     sequelize의 자료형은 MySQL의 자료형과 조금 다르다.

     * VARCHAR -> STRING
     * INT -> INERGER
     * TINYINT -> BOOLEAN
     * DATETIME -> DATE
     * INTEGER.UNSIGNED.ZEROFILL
     * NOT NULL -> allowNull
     * DEFAULT -> defaultValue

     define 메서드의 세 번째 인자는 테이블 옵션이다. timestamps 속성의 값이 false로 되어 있다.

     * timestamps 속성이 true면 sequelize는 createdAt와 updatedAt 컬럼을 추가한다. 그리고 로우가 생성될 때와 수정될 때의 시간이 자동으로 입력된다.

     * **기타 테이블 옵션**

       * paranoid
         : timestamps가 true여야 설정 가능. paranoid를 true로 설정하면 deletedAt라는 컬럼이 추가되고, 로우를 삭제하는 sequelize 명령을 내렸을때 삭제하는 대신 deletedAt에 제거된 날짜를 입력한다. 로우를 조회하는 명령을 내렸을때, deletedAt가 null이면 로우가 삭제되지 않았음을 의미한다.

         백업 데이터베이스가 없을 경우 임의로 삭제표시를 남길때 사용

       * underscored

         createdAt, updatedAt, deletedAt 컬럼과 시퀄라이즈가 자동으로 생성해주는 관계 컬럼들으 ㅣ이름을 스네이크 케이스 형식으로 바꾸어준다.

       * tableName

         테이블 이름을 다른 것으로 정하고 싶을 때 사용한다. 시퀄라이즈는 자동으로 define 메서드의 첫 번째 인자를 복수형으로 만들어 테이블 이름으로 사용한다.

2. Comment 모델을 만든다.

   * `models/comments`

     ```javascript
     module.exports = (sequelize, DataTypes) => {
       return sequelize.define('comment', {
         comment: {
           type: DataTypes.STRING(100),
           allowNull: false,
         },
         created_at: {
           type: DataTypes.DATE,
           allowNull: true,
           defaultValue: sequelize.literal('now()'),
         },
       }, {
         timestamps: false,
       });
     };
     ```
     
     user 테이블과 연결된 commenter 컬럼이 없다. 이는 모델을 정의할 때 넣어주지 않아도 된다.

3. 모델을 생성한 다음 `models/index.js`와 연결한다.

   * models/index.js

     ```js
     ...
     db.sequelize = sequelize;
     db.Sequelize = Sequelize;
     
     db.User = require('./user')(sequelize, Sequelize);
     db.Comment = require('./comment')(sequelize, Sequelize);
     
     module.exports = db;
     ```

     db라는 객체에 User와 Comment 모델을 담아두었다.

4. config 폴더 안의 config.json 수정

   * `config/config.json`

     ```json
     {
       "development": {
         "username": "root",
         "password": "[@leekukchun0519]",
         "database": "node.js",
         "host": "127.0.0.1",
         "dialect": "mysql",
         "operatorsAliases": false
       },
         ...
     }
     ```

     이 설정은 process.env.NODE_ENV가 development일 때 적용된다.

     배포시 process.env.NODE_ENV를 production으로 설정 해둔다. 즉, 배포 환경을 위해 데이터베이스를 설정할 때에는 config.json의 production 속성을 수정하면 된다. 테스트시에도 마찬가지이다.

<br>

### 관계 정의하기

users 테이블과 comments 테이블 간의 관계를 정의 해본다.

#### 1:N

> 한 사용자는 덧글 여러개를 달 수 있지만 덧글 하나에 사용자가 여러명일 수는 없다.

시퀼라이즈에서는 1:N 관계를 hasMany라는 메서드로 표현한다.

* hasMany를 사용해서 users 테이블의 로우 하나를 불러올 때 연결된 comments 테이블의 로우들도 같이 불러올 수 있다.
* belongsTo를 사용해 반대로 comments 테이블의 로우를 불러올 때 연결된 users 테이블의 로우를 가져온다.

`modeles/index.js`에서 모델들을 연결해준 곳 밑에 추가로 넣어준다.

* `models/index.js`

  ```javascript
  ...
  db.sequelize = sequelize;
  db.Sequelize = Sequelize;
  
  db.User = require('./user')(sequelize, Sequelize);
  db.Comment = require('./comment')(sequelize, Sequelize);
  
  db.User.hasMany(db.Comment, { foreignKey: 'commenter', sourceKey: 'id'});
  db.Comment.belongsTo(db.User, { foreignKey: 'commenter', targetKey: 'id'});
  
  module.exports = db;
  ```

`npm start`명령 실행

==안됨==

#### 1:1

> 사용자  한 명은 자신의 정보를 담고 있는 테이블과만 관계가 있다.

1대1 관계에서는 hasOne 메서드를 사용한다.

* hasOne 메서드를 통해서 연결된 테이블의 로우를 불러올 수 있다.
* delongsTo를 사용해도 동일하다.

#### N:M

> 게시글 테이블과 해시태그(#) 테이블 관계를 에로 들 수 있다.

시퀼라이즈에서 N:M 관계를 표현하기 위해 belongsToMany 메서드가 있다.

### 쿼리 알아보기

### 쿼리 수행하기

