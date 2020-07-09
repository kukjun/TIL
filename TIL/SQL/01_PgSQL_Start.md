알고 있어야 하는 3가지

* 운영체제
* 네트워크
* 데이터베이스

# PgSQL Start

표준하고 가장 비슷한 SQL

4학년때 사용함

현업에서는 My SQL

* 점차 PgSQL로 변경 추세

<br>

## About PostgreSQL

### Database

Anytime, Anywhere.

데이터를 저장하는 공간.

* 로그인을 하는 경우도 database 접근이라고 볼수 있음

  현대의 일반인은 수많은 database를 접함

* 눈이 보이지 않음

  * 백엔드 시스템

### DBMS

database management system

다수의 사용자들이 데이터베이스 내의 데이터에 접근할 수 있도록 해주는 소프트웨어 도구의 집합

* 통칭 Database 라고도 부르나 Database와는 엄연히 다르다.

#### PostgreSQL

[Michael Stonevbraker](http://wikipedia.org/wiki/Michael_Stonebraker)가 만든 RDBMS

* RDBMS : relational database management system 으로 현재 범용화됨.

PostgreSQL은 오픈소스 라이브러리 코드이고 여러가지 지원사항이 많다.

* Ingres, Postgres, Illustra, informax, Sybase SQL .. 등등에 영향을 미침

<br>

**PostgreSQL 특징**

Interactive Graphics Retrieval System[Ingres]에서 출발

개발 단계부터 완벽한 [ACID]()와 [MVCC]()를 지원하는 아키텍처로 설계

* 대용량의 복잡한 트랜잭션 처리를 위한 RDBMS

RDBMS의 [white paper]()를 기반으로 Oracle, DB2 그리고 PostgreSQL이 구현

* MySQL이나 MariaDB와 같은 오픈소스 제품과 달리 PostgreSQL의 경우 상용 RDBMS 급의 기능을 제공

<br><br>

## Installation Guide

<br>

### Overview

* Supported Multi Platform
  * installer, Binary File, Source Code
  * Windows, OS X, Linux

<br>

### Deployment Types

* Stable
  * 일반적인 사용자가 사용하는 버전
* Development
  * 새로운 기능과 특징을 추가
  * Alpha, Beta, Release Candidate[RC]로 구분
* Maintenance
  * 정식 배포된 후, 5년 동안 버그 및 보안 관련 수정과 유지보수 지원

<br>

### Installing PgSQL on Wondows

1. PgSQL 홈페이지를 통해서 최신버전 [다운로드](https://www.postgresql.org/download/)

2. 설치 가이드를 따라서 설치
   * 가이드 중 관리자 비밀번호 설치하고 잃어버리지 않기
3. 설치 후 PgSQL 설치 경로를 환경 변수로 설정

<br><br>

## User Management

<br>

### User Privileges

* Classification of User privileges
  * Entire system
    
    * Administrator
    
      CREAT USER, FILE, PROCESS, SHUTDOWN, AND ETC.
    
  * Database, Table, Column, and ETC
    * CREATE, ALTER, DROP
    * SELECT, INSERT, UPDATE, DELETE
    * VIEW, TRIGGER, EXECUTE, AND ETC.
    
  * Additional privileges

[White_peper](https://www.postgresql.org/docs/current/database-roles.html)

<br>

### PgSQL Setting

수동으로 설정해놓아야 노트북이나 컴퓨터의 메모리를 잡아먹지 않는다.

1. 윈도우에서 실행.exe 실행
2. services.msc 실행
3. postgresql 을 찾아서 시작
4. 작업 끝나면 종료

### PgSQL Access & Quit

#### Access

DataBase 접속

* Syntax

  ```sql
  psql -U user_name -d database_name
  ```

  * -U user_name

    사용자 계정(아이디)

  * -d database_name

    데이터베이스 식별자 ( 기본적으로 사용자 ID )

#### Quit

PgSQL 접속 해제

* Syntax

  ```sql
  quit;
  ```

<br>

### DB CREATE & DROP

#### CREATE

* Syntax

  ```sql
  CREATE DATABASE database_name ENCODING 'encoding_type';
  ```

  * database_name

    데이터베이스 식별자

  * encoding_type

    데이터베이스 인코딩 타입으로 'UTF-8'로 설정

  * Whitepaper

    https://www.postgresql.org/docs/current/sql-createdatabase.html

* ex

  'exercise'와 'test'데이터베이스를 생성

  ```sql
  create database exercise ENCODING 'UTF-8';
  create database test ENCODING 'UTF-8';
  ```

<br>

#### DROP

* Syntax

  ```sql
  DROP DATABASE database_name;
  ```

  * database_name

    데이터베이스 식별자

  * Whitepaper

    https://www.postgresql.org/docs/current/sql-dropdatabase.html

* ex

  'test' 데이터베이스를 제거.

  ```sql
  drop database test;
  ```

### CREATE & DROP Users

사용자를 생성하고 제거할 수 있다.

#### CREATE

CREATE USER 명령을 사용하여 사용자를 생성

* Syntax

  ```sql
  CREATE USER username WITH PASSWORD 'password';
  ```

  * <u>대소문자 무관</u>

  * username

    사용자 계정[아이디]

  * password

    비밀번호. 반드시 어려운 비밀번호로 입력하며, 분실하지 않도록 유의

* ex

  사용자 아이디 'scott', 비밀번호 'tiger'

  사용자 아이디 'test', 비밀번호 'test1004'

  ```sql
  create user scott with password 'tiger';
  create user test with password 'test1004';
  ```

#### DROP

DROP UESR 명령을 사용하여 사용자를 제거

* Systax

  ```sql
  DROP USER username;
  ```

  * username

    사용자 계정[아이디]

* ex

  사용자 아이디 'test'를 제거.

  ```sql
  drop user test;
  ```

<br>

### GRANT & REVOKE Users

#### GRANT

GRANT 명령을 사용하여 사용자의 권한 부여

* Syntax

  ```sql
  GRANT <permission> ON DATABASE <database_name> TO <username> WITH GRANT OPTION;
  ```

  * <>은 필수적으로 입력해주어야 함

  * permission

    사용자에게 부여할 권한 지정

  * database_name

    데이터베이스 식별자

  * username

    사용자 계정
    
  * [White_paper](https://www.postgresql.org/docs/current/sql-grant.html)

* ex

  ```sql
  grant all on database exercise to scott with grant option;
  ```

#### REVOKE

REVOKE 명령을 사용하여 사용자의 권한 회수

* Syntax

  ```sql
  REVOKE <permission> ON DATABASE <database_name> FROM <username>;
  ```

  * permission

    사용자에게 부여할 권한 지정

  * database_name

    데이터베이스 식별자

  * username

    사용자 계정

  * [White_paper](https://www.postgresql.org/docs/current/sql-revoke.html)

<br>

## Using PostgreSQL

<br>

## PostgreSQL Data type

* 숫자형
  * INT(Small, Big), REAL, Double Percisionn Numeric
* 문자형
  * CHAR(사용X, 고정길이), VARCHAR, TEXT, AND ETC

* 날짜형
  * DATA, TIME(날짜), TIMESTAMP(날짜와 시간) AND ETC.
* 기타형
  * BOOLEAN, SERIAL(Small, Big)<u>채번?</u> , JSON, JSONB, ABD ETC.

<br>

### View DB

#### \list

시스템에 등록된 데이터베이스 보기

* Systax

  ```sql
  SQL> \list
  ```

  * alias로 등록된 간추린 명령어.
  
* Others

  ```sql
  SELECT pg_database.datname, pg_user.usename
    FROM pg_database, pg_user
   WHERE pg_database.datdba = pg_user.usesysid;
  ```



* pg_database, pg_user

  PgSQL의 시스템 카탈로그

### CHANGE DB

psql 모드에서 데이터베이스에 접속하기

* Systax

  ```sql
  SQL> \c database_name
  ```

## Table

**About Table?**

* 테이블은 관계형 데이터베이스의 기본적인 데이터 저장 단위
* 사용자가 접근 가능한 모든 데이터를 보유하며, **행(Row)과 열(Column)**로 구성

### CREATE TABLE

CREATE TABLE 명령어를 통해 테이블을 생성한다.

* Syntax

  ```sql
  CREATE TABLE [IF NOT EXISTS] table_name (<column-definition>);
  ```

  * **[]는 필수 사항이 아닌 선택사항**

    * IF NOT EXISTS

      기존에 동일한 이름의 테이블 이름이 있으면 생성하지 않음

  * table_name

    테이블 식별자

  * column-definition

    테이블을 구성하는 컬럼 이름과 컬럼 도메인 정보 등을 지정
    
    * Syntax \<cilumn-definition\>
    
      ```sql
      <colnmn_name> <datatype>
      		[NOT NULL | NULL]
      		[CHECK <expression>]
      		[DEFAULT <default_value>]
      		[UNIQUE [KEY] | [PRIMARY] KEY]
      ...
      ```
    
      * NOT NULL|NULL - NULL 값 허용 지정
      * CHECK - 컬럼의 제약조건 지정
      * DEFAULT - 컬럼의 기본값 지정
      * UNIQUE KEY | PRIMARY KEY - 유일 값, 기본 키 지정

* ex

  우리 조직의 학생은 학번(no), 성명(kname, 문자 4자리), 생년월일(birthday, 날짜)를 입력하고, 기본 키는 학번으로 지정한다. 단, 학번과 성명은 반드시 입력해야 한다.

  ```sql
  create table student1 (
  no INT NOT NULL PRIMARY KEY,
  kname VARCHAR(4) NOT NULL,
  birthday DATE
  );
  ```

### View Table list

시스템에 등록된 테이블의 목록 보기

* Syntax

  ```sql
  SQL> \dt
  ```

  * alias에 등록된 명령

* Others

  ```sql
  SELECT *
    FROM pg_tables
   WHERE tableowner = 'username';
  ```

  * username

    사용자 계정 식별자

  * pg_tables

    데이터베이스의 시스템 카탈로그

### View Table sturucture

* Syntax

  ```sql
  SQL> \d table_name
  ```

  * alias에 등록된 명령

* Others

  ```sql
  SELECT column_name, data_type, is_nullable, column_default
  FROM information_schema.columns
  WHERE table_name = 'table_name';
  ```

  * column_name, table_name

    컬럼과 테이블 식별자

  * information_schema

    데이터베이스의 시스템 카탈로그

### 테이블 수정하기

* Syntax

  ```sql
  ALTER TABLE [IF EXISTS] table_name (<column-definition>);
  ```

### 테이블 칼럼 추가하기

* Syntax

  ```sql
  ADD COLUMN <column_name> <column_definition> [column_constraint]
  ```

### 테이블 칼럼 수정하기

### 테이블 칼럼 삭제하기

* Syntax 

  ```sql
  DROP COLUMN <column_name>
  ```

* 

## 데이터 (등록, 조회, 수정, 삭제)

### 데이터 삽입

* Syntax

  ```sql
  INSERT INTO <table_name> [(<column_name>[, column_name, ...])]
  VALUES ({expression|DEFAULT}, ...) [, (...), ...];
  ```

  * table_name

    데이터를 삽입할 테이블을 지정

  * VALUES

    삽입할 데이터 값

  * expression

    컬럼에 입력할 값을 나열하며

### 데이터 수정

* Syntax

  ```sql
  UPDATE <table_name> SET column_name={expression|DEFAULT}
  		[, columnmn_name]
  ```

  * WHERE  필수

### 데이터 삭제

* Syntax

  ```sql
  DELETe FROM <table_name> [WHERE <query_condition>];
  ```

  * WHERE 필수

### 데이터 조회

* Syntax

  ```sql
  SELECT
  ```

## Using JDBC Connector

**절대로 사용X**
