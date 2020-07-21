# SQL Fundamental 1

## Tansaction

### About Transation

> 시스템에서 사용되는 '더 이상 쪼갤 수 없는' 업무처리의 단위

> DB의 무결성이 보장되는 상태에서 요청된 작업을 수행하기 위한 작업의 기본 단위

* ex

  은행에서 A(송신)와 B(수신) 사용자 사이의 계좌이체 - A가 B에서 100만원 송금

  1. 은행 데이터베이스에서 A의 잔액 확인
  2. B의 계좌가 있는지 확인 후, 계좌가 있으면 100만원 송금
  3. 송금이 정상적으로 이루어졌는지 확인하기(A계좌 - 100만원, B계좌 + 100만원)
  4. 3번째 단계가 정상 완료된 경우 종료하고, 그렇지 않은 경우, 모든 작업을 취소한 후 처음부터 다시 처리

### Commit Mode 설정 및 확인

#### Commit Mode

Commit모드를 확인하는 명령어

* Syntax

  ```sql
  \echo :AUTOCOMMIT
  ```

#### Set Commit Mode

Commit모드를 설정하는 명령어

* Syntax

  ```sql
  \set AUTOCOMMIT on/off
  ```

#### Begin

## SQL Statement

### Statement

* Data Definition Language
  DDL - 데이터베이스 객체/데이터 구조 정의
  * CREATE
    :  데이터베이스 객체 등을 생성
  * ALTER
    : 존재하는 데이터베이스 객체 등을 다시 정의
  * DROP
    : 데이터베이스 객체 등을 제거
* Data Manipulation Language
  DML -  데이터의 검색과 조작(삽입, 갱신, 그리고 삭제) 처리
  * INSERT
    : 데이터베이스 객체에 데이터 삽입
  * DELETE
    : 데이터베이스 객체에 저장되어 있는 데이터 삭제
  * UPDATE
    : 존재하는 데이터베이스 객체에 저장되어 있는 데이터 수정
  * SELECT
    : 데이터베이스 객체에 저장되어 있는 데이터 검색
* Data Control Language
  DCL - 데이터베이스 사용자/객체의 권한 제어
  * GRANT
    : 데이터베이스 객체에 권한 부여
  * REVOKE
    : 데이터베이스 객체에 허가된 권한 취소

### How to run SQL Statement

* Using PSQL Console
* Using Source Command with SQL Script files
  * <span style="color:red">모르는 부분 Check 필요</span>

<br>

## Table Control

### Data Model

* Course registration system
  * key Entity: 교수(Professor), 학생(Stutent), 개설과목(Course)
  * Association Entity: 강의(Lecture), 지도(Advise), 수강(Register)
    * 다대다를 연관시키기 위한 것, 각각의 primary키를 가진다.

![image-20200722010954714](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722010954714.png)

#### 테이블 생성하기

Sample Data로 테이블 모델 구현

* Professor Table

  ![image-20200722010521515](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722010521515.png)

  * CREATE TABLE professor

    ```sql
    CREATE TABLE professor(
        PCODE VARCHAR(4) PRIMARY KEY,
        PNAME VARCHAR(10),
        PDEPT VARCHAR(12),
        PPHONE vARCHAR(8)
    );
    ```

* Student Table

  ![image-20200722015958772](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722015958772.png)

  * CREATE TABLE student

    ```sql
    CREATE TABLE student(
        SCODE VARCHAR(4) PRIMARY KEY,
        SNAME VARCHAR(10),
        SDEPT VARCHAR(12),
        SPHONE VARCHAR(8)
    );
    ```

* Course Table

  ![image-20200722020114766](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722020114766.png)

  * CREATE TABLE course

    ```sql
    CREATE TABLE course(
        CCODE VARCHAR(4) PRIMARY KEY,
        CNAME VARCHAR(10),
        CTIME INT,
        CROOM VARCHAR(8)
    );
    ```

##### 외래키로 연결시킨 테이블

* Lecture

  ![image-20200722020234981](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722020234981.png)

  * CREATE TABLE lecture

    ```sql
    CREATE TABLE lecture(
    	LPCODE VARCHAR(4) NOT NULL,
        LCCODE VARCHAR(4) NOT NULL,
        PRIMARY KEY (LPCODE, LCCODE),
        CONSTRAINT lpcode_fk FOREIGN KEY(LPCODE) REFERENCES professor(PCODE),
        CONSTRAINT lccode_fk FOREIGN KEY(LCCODE) REFERENCES course(CCODE)
    );
    ```

* Advise

  ![image-20200722020316380](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722020316380.png)

  * CREATE TABLE advise

    ```sql
    CREATE TABLE advise(
    	APCODE VARCHAR(4) NOT NULL,
        ASCODE VARCHAR(4) NOT NULL,
        PRIMARY KEY (APCODE, ASCODE),
        CONSTRAINT apcode_fk FOREIGN KEY(APCODE) REFERENCES professor(PCODE),
        CONSTRAINT ascode_fk FOREIGN KEY(ASCODE) REFERENCES student(SCODE)
    );
    ```

* Register

  ![image-20200722020358992](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722020358992.png)

  * CREATE TABLE register

    ```sql
    CREATE TABLE register(
        RSCODE VARCHAR(4) NOT NULL,
        RCCODE VarCHAR(4) NOT NULL,
        PRIMARY KEY (RSCODE, RCCODE),
        CONSTRAINT rscode_fk FOREIGN KEY(RSCODE) REFERENCES student(SCODE),
        CONSTRAINT rccode_fk FOREIGN KEY(RCCODE) REFERENCES course(CCODE)
    );
    ```

#### 데이터 삽입하기

데이터를 삽입하는 방법은 직접 삽입하는 방법 외에도 여러가지가 있다.

##### 직접 삽입하기

* Syntax

  ```sql
  INSERT [INTO] <table_name> [(columnn_name>[, column_name, …])]
  VALUES ({expression | DEFAULT }, …) [, (…), …];
  ```

  * Table professor

    ```sql
    INSERT INTO professor (PCODE, PNAME, PDEPT, PPHONE)
    VALUES ('P001', '안기홍', '컴퓨터공학과', '821-1101');
    INSERT INTO professor VALUES ('P002', '김정호', '컴퓨터공학과', '821-1102');
    INSERT INTO professor VALUES ('P003', '이창석', '전파공학과', '821-1201');
    INSERT INTO professor VALUES('P004', '박현주', '전파공학과', '821-1202');
    INSERT INTO professor VALUES('P005', '김응규', '정보통신공학과', '821-1301');
    INSERT INTO professor VALUES('P006', '김은기', '정보통신공학과', '821-1302');
    ```

##### CSV File 삽입하기

* Syntax

  ```sql
  COPY table_name FROM 'file_path' ( FORMAT CSV, DELIMITER(',') );
  ```

  * Table course

    ```sql
    \COPY course FROM 'C:/SQL/course.csv' ( FORMAT CSV, DELIMITER(',') );
    ```

##### SQL File 삽입하기

* Syntax

  ```sql
  \i file_path
  ```

  * Table student

    ```sql
    \i C:/SQL/insert_student.sql
    ```

  * Table lecture

    ```sql
    \i C:/SQL/insert_lecture.sql
    ```

  * Table advise

    ```sql
    \i C:/SQL/insert_advise.sql
    ```

  * Table register

    ```sql
    \i C:/SQL/insert_register.sql
    ```

  

  

#### 데이터

```sql
UPDATE 교수 SET PNAME='안기홍' where PNAME='안기흥';
```

```sql
UPDATE advise SET APCODE='P003' where APCODE='P004';
```

```sql
INSERT INTO PROFESSOR (PCODE,PNAME,PDEPT,PPHONE)
VALUES ('P001','안기흥','컴퓨터공학과', '821-1101');
INSERT INTO PROFESSOR VALUES ('P002','김정호','컴퓨터공학과','821-1102');
INSERT INTO PROFESSOR VALUES ('P003','이창석','전파공학과','821-1201');
INSERT INTO PROFESSOR VALUES ('P004','박현주','전파공학과','821-1202');
INSERT INTO PROFESSOR VALUES ('P005','김응규','정보통신공학과','821-1301');
INSERT INTO PROFESSOR VALUES ('P006','김은기','정보통신공학과','821-1302');
```

```sql
SQL> \COPY COURSE FROM 'c:/sql/sample_data/course.csv'
( FORMAT CSV, DELIMITER(',') );
```



LIKE

* LIKE Operator
  *  % 무한
  * _ 한글자만

```sql
SELECT *
FROM PROFESSOR
WHERE PNAME LIKE '김%';
```



## Table Control

## Data Manipulation Language