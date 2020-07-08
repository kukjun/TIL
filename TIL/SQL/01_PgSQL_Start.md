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

Database

* 데이터를 저장하는 공간

  * 로그인을 하는 경우도 Database 접근이라고 볼수 있음

    수많은 database를 접함

  * 눈이 보이지 않음

    * 백엔드 시스템

Database 관리 시스템

* PostgreSQL 같은 프로그램
  * 통칭 Database 라고도 부르나 엄연히 다르다.

PostgreSQL은 오픈소스 라이브러리 코드이고 여러가지 지원사항이 많다.

* Ingres, Postgres, Illustra, informax, Sybase SQL .. 등등에 영향을 미침

<br>

### PostgreSQL 특징

Interactive Graphics Retrieval System[Ingres]에서 출발

개발 단계부터 완벽한 <u>ACID</u>와 <u>MVCC</u>를 지원하는 아키텍처로 설계

* 대용량의 복잡한 트랜잭션 처리를 위한 RDBMS

RDBMS의 화이트페이퍼를 기반으로 Oracle, DB2 그리고 PostgreSQL이 구현

* MySQL이나 MariaDB와 같은 오픈소스 제품과 달리 PostgreSQL의 경우 상용 RDBMS 급의 기능을 제공

<br><br>

## Installation Guide

<br>

### Overview

* Supported Multi Platform
  * installer, Binary File, Source Code
  * Windows, OS X, Linux
* https://www.postgresql.org/download/
* BigSQL
  * https://www.openscg.com/bigsql/postgresql/installers.jsp/

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

<br>

### PgSQL Package Security

<br><br>

## Configuration Guide

<br>

### PgSQL Configuration File

<br>

### PgSQL Start & Stop

<br><br>

## User Management

<br>

### User Privileges

* Classification of User privileges
  * Entire system
    * Administrator
  * Database, Table, Column, and ETC
    * CREATE, ALTER, DROP
    * SELECT, INSERT, UPDATE, DELETE
    * VIEW, TRIGGER, EXECUTE, AND ETC.
  * Additional privileges

<br>

### 데이터베이스 생성과 삭제

#### 생성

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

#### 삭제

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

### Creating / Removing Users

#### Creating Users

CREATE USER 명령을 사용하여 사용자를 생성

* Syntax

  ```sql
  CREATE USER username WITH PASSWORD 'password';
  ```

  * 대소문자 무관

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

#### Removing Users

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

### Granting Permissions

#### Granting

* Syntax

  ```sql
  GRANT <permission> ON DATABASE <database_name> TO <username> WITH GRANT OPTION
  ```

  * <>은 필수적으로 입력해주어야 함

  * permission

    사용자에게 부여할 권한 지정

  * database_name

    데이터베이스 식별자

  * username

    사용자 계정

* ex

  ```sql
  grant all on database exercise to scott with grant option;
  ```

psql -U username -d database_name

#### Revoking

* Syntax

  ```sql
  
  ```

  

GRANT 명령을 사용하여 사용자에게 관한 부여

<br>

### Changing Passwords

<br><br>

## Using PostgreSQL

<br><br>

### 데이터베이스 보기

* 시스템에 등록된 데이터베이스 보기

  * PSQL Console

    ```sql
    SQL> \list
    ```

    

### 데이터베이스 접속

## Table

### 테이블이란?

* About Table?
  * 테이블인 관계형 데이터베이스의 기본적인 데이터 저장 단위
  * 사용자가 접근 가능한 모든 데이터를 보유하며, **행과 열**로 구성

### 테이블 생성하기

* Syntax

  ```sql
  CREATE TABLE [IF NOT EXISTS] table_name (<column-definition>);
  ```

  * table_name

    테이블 식별자

  * IF NOT EXISTS

    기존에 동일한 이름의 테이블 이름이 있으면 생성하지 않음

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

### 테이블 목록 보기

### 테이블 구조 보기

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

  

## PostgreSQL 데이터 타입

* 숫자형
  * INT(Small, Big), REAL, Double Percisionn Numeric
* 문자형
  * CHAR(사용X, 고정길이), VARCHAR, TEXT, AND ETC

* 날짜형
  * DATA, TIME(날짜), TIMESTAMP(날짜와 시간) AND ETC.
* 기타형
  * BOOLEAN, SERIAL(Small, Big)<u>채번?</u> , JSON, JSONB, ABD ETC.

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

