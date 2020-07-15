# SQL Fundamental 1

## Tansaction

### About Transation

> 시스템에서 사용되는 '더 이상 쪼갤 수 없는' 업무처리의 단위

> DB의 무결성이 보장되는 상태에서 요청된 작업을 수행하기 위한 작업의 기본 단위

* ex

  은행에서 A(송신)와 B(수신) 사용자 사이의 계좌이체 - A가 B에서 100

## SQL Statement

#### Data Model

* Ciurse registration sustem
  * key Entity: 교수(Professor), 학생(Stutent), 개설과목(Course)
  * Association Entity: 강의(Lecture), 지도(Advise), 수강(Register)
    * 다대다를 연관시키기 위한 것, 각각의 primary키를 가진다.

![image-20200715144840921](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200715144840921.png)

#### Sample Data

* Professor Table
* Student Table

* Course Table
* Lecture

```sql
CREATE DATABASE Education ENCODING 'UTF-8';
\list
GRANT all ON DATABASE education TO scott WITH GRANT OPTION;
```

#### 외래키

```개ㅔ
CREATE TABLE professor(
    PCODE VARCHAR(4) PRIMARY KEY,
    PNAME VARCHAR(10),
    PDEPT VARCHAR(12),
    PPHONE vARCHAR(8)
);
```

```sql
CREATE TABLE student(
    SCODE VARCHAR(4) PRIMARY KEY,
    SNAME VARCHAR(10),
    SDEPT VARCHAR(12),
    SPHONE VARCHAR(8)
);
```

```sql
CREATE TABLE COURSE(
    CCODE VARCHAR(4) PRIMARY KEY,
    CNAME VARCHAR(10),
    CTIME INT,
    CROOM VARCHAR(8)
);
```

```sql
CREATE TABLE LECTURE(
	LPCODE VARCHAR(4) NOT NULL,
    LCCODE VARCHAR(4) NOT NULL,
    PRIMARY KEY (LPCODE, LCCODE),
    CONSTRAINT lpcode_fk FOREIGN KEY(LPCODE) REFERENCES 교수(PCODE),
    CONSTRAINT lccode_fk FOREIGN KEY(LCCODE) REFERENCES 과목(CCODE)
);
```

```sql
CREATE TABLE ADVISE(
	APCODE VARCHAR(4) NOT NULL,
    ASCODE VARCHAR(4) NOT NULL,
    PRIMARY KEY (APCODE, ASCODE),
    CONSTRAINT apcode_fk FOREIGN KEY(APCODE) REFERENCES 교수(PCODE),
    CONSTRAINT ascode_fk FOREIGN KEY(ASCODE) REFERENCES 학생(SCODE)
);
```

```sql
CREATE TABLE REGISTER(
    RSCODE VARCHAR(4) NOT NULL,
    RCCODE VarCHAR(4) NOT NULL,
    PRIMARY KEY (RSCODE, RCCODE),
    CONSTRAINT rscode_fk FOREIGN KEY(RSCODE) REFERENCES 학생(SCODE),
    CONSTRAINT rccode_fk FOREIGN KEY(RCCODE) REFERENCES 과목(CCODE)
);
```

```sql
INSERT INTO 교수 (PCODE, PNAME, PDEPT, PPHONE)
VALUES ('P001', '안기홍', '컴퓨터공학과', '821-1101');
INSERT INTO 교수 VALUES ('P002', '김정호', '컴퓨터공학과', '821-1102');
INSERT INTO 교수 VALUES ('P003', '이창석', '전파공학과', '821-1201');
INSERT INTO 교수 VALUES('P004', '박현주', '전파공학과', '821-1202');
INSERT INTO 교수 VALUES('P005', '김응규', '정보통신공학과', '821-1301');
INSERT INTO 교수 VALUES('P006', '김은기', '정보통신공학과', '821-1302');
```

#### CSV File 입력

```sql
insert into course (ccode, cname, ctime, croom) values
('C001', 'TCP/IP', 3, 'R001'),
('C002', 'HTML', 3, 'R002'),
('C003', 'OS', 3, 'R003'),
('C004', 'Database', 4, 'R004'),
('C005', 'Java', 2, 'R005'),
('C006', 'C', 2, 'R006'),
```

#### SQL File 입력

```sql
\i C:/SQL/202007-getting-started-with-pgsql/insert_lecture.sql
\i C:/SQL/202007-getting-started-with-pgsql/insert_advise.sql
\i C:/SQL/202007-getting-started-with-pgsql/insert_register.sql
```

#### 데이터 수정

```sql
UPDATE 교수 SET PNAME='안기홍' where PNAME='안기흥';
```

```sql
UPDATE advise SET APCODE='P003' where APCODE='P004';
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