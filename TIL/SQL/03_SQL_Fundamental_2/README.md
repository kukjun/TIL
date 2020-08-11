# SQL Fundamental 2

## Aggregation & Grouping

<br>

### Aggregation

집합

* Abstract **집합함수**
  * AVG
    : Calculates the average value in a column
  * COUNT
    : Determines the number of rows in a table
  * MAX
    : Determines the maximum value in a table
  * MIN
    : Determines the minimum value in a column
  * SUM
    : Calculates a total of the values in a column

* ex

  Calculate the total, minimum, maximum, count, and average of the ctime

  ```sql
  SELECT SUM(CTIME), MIN(CTIME), MAX(CTIME), ROUND( AVG(CTIME), 2 )
  FROM COURSE;
  ```

<br>

### Grouping

> Creates groups of rows that share common characteristics

> Calculations in the SELECT command are performed for the entire group

* ex

  학과별 교수 인원을 조회하라

  ```sql
  SELECT PDEPT, COUNT(*)
  FROM PROFESSOR
  GROUP BY PDEPT;
  ```

<br>

### Processing Build Environment

* Run Scripts

  ```sql
  \i C:/SQL/device.sql;
  ```

* Query

  ```sql
  SQL> \d DEVICE;
  SQL> \d DEVICE_DATA;
  SQL> SELECT * FROM DEVICE;
  SQL> SELECT * FROM DEVICE_DATA;
  ```

* ex

  DEVICE ID별로 수집된 데이터의 개수, 총합, 평균을 ID 오름차순으로 조회하라

  ```sql
  SELECT DD_DEVICE_ID 아이디, COUNT(DD_DEVICE_DATA) 개수, SUM(DD_DEVICE_DATA) 총합, ROUND(AVG(DD_DEVICE_DATA), 2) 평균
  FROM DEVICE_DATA
  GROUP BY DD_DEVICE_ID
  ORDER BY DD_DEVICE_ID;
  ```

  C501, 503에서 수집된 데이터를 장치 아이디 별로 합계와 평균을 조회하시오

  ```sql
  SELECT D.DEVICE_ID "장치 아이디", SUM(DD.DD_DEVICE_DATA) 합계, ROUND(AVG(DD.DD_DEVICE_DATA), 2) 평균
  FROM DEVICE D, DEVICE_DATA DD
  WHERE DD.DD_DEVICE_ID = D.DEVICE_ID
  AND ( D.DEVICE_LOC ='C503' OR D.DEVICE_LOC='C501')
  GROUP BY D.DEVICE_ID;
  ```

  장치 아이디 별로 수집한 데이터의 총합이 280 이상인 디바이스 ID, 디바이스 위치, 데이터의 총합과 평균을 조회하시오.

  ```sql
SELECT D.DEVICE_ID "디바이스 ID", D.DEVICE_LOC "디바이스 위치", SUM(DD.DD_DEVICE_DATA) 총합, ROUND(AVG(DD.DD_DEVICE_DATA),2) 평균
  FROM DEVICE D, DEVICE_DATA DD
  WHERE D.DEVICE_ID = DD.DD_DEVICE_ID
  GROUP BY D.DEVICE_ID
  HAVING SUM(DD.DD_DEVICE_DATA) > 280;
  ```
  

<br>

### Distinct

중복 행을 제거한다.

> Remove duplicate rows

> count() function to determine the number of members in each group

* ex

  몇 개의 디바이스에서 데이터가 수집되었는지 확인하기

  <span style="color:red">모르는 부분 Check 필요</span>

  ```sql
  SELECT COUNT(*) CNT
  FROM SELECT DD_DEVICE_ID
        FROM DEVICE_DATA
        GROUP BY DD_DEVICE_ID;
  ```

  ```sql
  SELECT
  COUNT(DISTINCT DD_DEVICE_ID) AS CNT
  FROM
  DEVICE_DATA;
  ```
  
  ```sql
  SELECT COUNT(DD_DEVICE_ID) 개수
  FROM DEVICE_DATA DD
  GROUP BY DD.DD_DEVICE_ID
  ORDER BY DD_DEVICE_ID;
  ```
  
  

<br>

### NULL

> missing information and inapplicable information

> 데이터 값이 존재하지 않는다는 것을 지시하는데 사용하는 특별한 표시어

* Query Expression

  ```sql
  NULL OPERATION
  SELECT NULL = NULL, NULL <> NULL, 1 = NULL, 1 <> NULL, 1 < NULL, 1> NULL;
  -- NULL은 비교 연산이 불가능하다.
  
  논리적인 연산
  -- True이면 't', False이면 'f'를 RETURN
  SELECT NULL IS NULL, 1 IS NULL, 1 IS NOT NULL;
  ```

<br>

## Subqueries

> are a powerful tool that you can use in all four SQL data statements

#### Subquery

is a query contatined within another SQL statement.
is always enclosed within parentheses.
is usually executed prior to the containing statement.

* ex

  운영체제의 시수와 같거나 큰 과목을 조회하라.

  일반적인 형태

  ```sql
  SELECT C1.CNAME
  FROM COURSE C1, COURSE C2
  WHERE C1.CTIME >= C2.CTIME
  AND C2.CNAME = 'OS';
  ```

  **Subquery 사용**

  ```sql
  SELECT CNAME
  FROM COURSE
  WHERE CTIME >= (SELECT CTIME
                 FROM COURSE
                 WHERE CNAME = 'OS');
  ```


### Operators

연산자

#### Single Row Operators

단일 행 연산자

* '=', '>', '>=', '<', '<=', '<>', '!='

#### Multiple Row Operators

다중 행 연산자

SELECT 문장에서 2건 이상의 행(값)을 반환하는 Query

* IN, NOT IN, ANY, ALL, EXISTS

프롬절 실렉트절 웨얼절에서 사용가능

스칼라서브쿼리 =  실렉트

비상관 상관 서브쿼리 = 웨얼절의 두 종류

### Types

#### Single-Row /Multiple-Row Subquery

* Single-Row
  : SELECT 문장에서 오직 하나의 행을 검색하는 질의
* Multiple-Row
  : SELECT 문장에서 하나 이상의 행을 검색하는 질의

#### Single-Column / Multiple_Column Subquery

* Single-Column
  : SELECT 문장에서 오직 하나의 컬럼을 검색하는 질의
* Multiple-Column
  : SELECT 문장에서 하나 이상의 컬럼을 검색하는 질의

#### INLINE VIEW

> FROM 절에서 사용하는 Subquery

VIEW 형태로 동작하여 INLINE VIEW라고 함

#### Noncorrelated Subqueries

> 비상관 서브 쿼리

#### Correlated Subqueries

> 상관 서브 쿼리

## Views

### About VIew

* Virtual Table
  
  > is simply a mechanism for querying data
* Unlike tables, views do not involve data storage
  
  > you won't need to worry about views filling up your disk space.

### Advantage of View

* 보안
  사용자에게 필요없는 정보를 숨길 수 있음

* 복잡한 질의를 간단한 명령으로 단순하게 사용할 수 있음

* 데이터 모델(설계)이 변경되어도 기본 질의의 변경을 최소화할 수 있음.

  > 이 시점에서 SQL을 수행하라고 하는 것. SQL 알리어스 라고 생각하는게 낫다.

### View

==모르겠음==

* Syntax

  ```sql
  CREATE [OR REPLACE] VIEW view_name [(column_list)]
  	AS select_statement
  ```

  * view_name

    생성할 뷰(View) 명을 입력

  * OR REPLACE

    기존에 동일한 이름의 뷰 명이 있으면 다시 생성함

  * column-list

    뷰를 구성하는 컬럼 목록을 지정

  * [Whitepaper](https://www.postgresql.org/docs/9.6/static/sql
    createview.html[)

* ex

   박현주 교수님께서 강의하는 과목명, 강의 시수, 그리고 강의실을 조회하라.

  ```sql
  SELECT
  FROM FROFESSOR
  WHERE
  ```

  ```sql
  SELECT
  C CNAME, C CTIME, C CROOM
  FROM
  PROFESSOR P, COURSE C, LECTURE L
  WHERE
  L LPCODE P PCODE AND L LCCODE C CCODE
  AND
  P PNAME 박현주
  
  
  CREATE
  VIEW viewLecture AS
  SELECT
  P PNAME, C CNAME, C CTIME, C CROOM
  FROM
  PROFESSOR P, COURSE C, LECTURE L
  WHERE
  L LPCODE P PCODE AND L LCCODE C CCODE
  SELECT
  CNAME, CTIME, CROOM
  FROM
  viewLecture
  WHERE
  PNAME 박현주
  ```

<br><br>

## Join Method

### JOIN

> KEY Element of the RDBMS

#### About JOIN

* 관계형 데이터베이스의 꽃
* 조인을 명확하게 이해하기 위해서는 관계형 데이터베이스에 대한 이해가 필요

**최소한의 핵심적인 내용만을 가져야 한다.**

PK FK 관계형 데이터베이스 특징, 가져오는 기법은 **JOIN**

* 조인이 왜 필요할까요?
  * 관계형 데이터베이스의 구조적 특징으로 말미암아 의미 있는 데이터의 집합으로
    테이블이 구성되고 , 각 테이블끼리는 관계 (Relationship)를 가짐
    * 관계형 데이터베이스는 저장 공간의 효율성과 확장성이 향상
  * 서로 관계 있는 데이터가 여러 테이블로 나뉘어 저장되므로, 각 테이블에 저장된 데이터를 효과적으로 검색하기 위해 방법이 필요
    * 각 테이블 간 의미 있는 데이터(행)를 연결하는 데 활용되는 메커니즘

#### Key Point

* SQL 문장의 의미를 제대로 파악하라
  * 잘못 사용하면 커다란 재앙이 뒤따른다.
* 조인 조건을 명확하게 제공해야 한다.
  * CROSS JOIN(Caresian Product)이 발생할 가능성이 있음
* 조인을 적용한 후 반드시 테스트를 수행하여 검증하라

### Join Types

* Category
  * CARTESIAN PRODUCT
  * INNER JOIN
  * OUTER JOIN
    * LEFT OUTER JOIN
    * RIGHT OUTER JOIN
    * FULL OUTER JOIN

#### Cartesian Product

조인(JOIN)에 참여한 테이블들의 모든 데이터가 RETURN

* 발생 이유

  JOIN 조건이 잘못된 경우

  JOIN 조건을 정의하지 않았을 때

  첫 번째 테이블의 모든 행과 두 번째 테이블의 모든 행이 조인되는 경우

* 해결방법

  테이블 개수가 N개라면, 적어도 N-1개의 JOIN 조건을 질의 안에 포함해야 함

#### INNER JOIN

가장 일반적인 조인 형태

둘 이상의 테이블이 존재하는 공통 컬럼의 값이 같은 것을 결과로 추출

* Syntax

  ```sql
  SELECT *
  FROM A INNER JOIN B
  ON A.ID = B.ID;
  ```

  ```sql
  SELECT *
  FROM A, B
  WHERE A.ID = B.ID;
  ```

  

* ex

  ```sql
  \i C:/SQL/professor_website.sql;
  
  \d PROF_WEBSITE;
  SELECT * FROM PROF_WEBSITE;
  ```

  교수코드 P004의 교수이름, 블로그, 홈페이지, 페이스북을 조회하라
  
  ```sql
  SELECT PROFESSOR.PNAME, PROF_WEBSITE.BLOG, PROF_WEBSITE.HOMEPAGE, PROF_WEBSITE.FACEBOOK
  FROM PROFESSOR, PROF_WEBSITE
  WHERE PROFESSOR.PCODE = PROF_WEBSITE.PWCODE
AND PROFESSOR.PCODE = 'P004';
  ```
  
  ```sql
  SELECT P.PNAME, PW.BLOG, PW.HOMEPAGE, PW.FACEBOOK
  FROM PROFESSOR P, PROF_WEBSITE PW
  WHERE P.PCODE = PW.PWCODE
  AND P.PCODE = 'P004';
  ```

#### OUTER JOIN

* LEFT OUTER JOIN
오른쪽 테이블에 조인할 칼럼의 값이 없는 경우 사용함
* RIGHT OUTER JOIN
왼쪽 테이블에 조인할 컬럼의 값이 없는 경우에 사용함
* FULL OUTER JOIN
  양쪽 테이블 모두 OUTER JOIN이 필요할 때 사용함

## Set Theory

### INTERSECTION

**INNERJOIN**
$$
A \cap B
$$

* Syntax

  ```sql
  SELECT *
  FROM A INNER JOIN B
  ON A.ID = B.ID
  ;
  ```

### UNION

**FULL OUTERJOIN**
$$
A \cup B
$$

* Syntax

  ```sql
  SELECT *
  FROM A FULL OUTER JOIN B
  ON A.ID = B.ID
  ;
  ```

  

### Relative Complement

**LEFT OUTERJOIN**
$$
A \cap B^C
$$

```sql
SELECT *
FROM A LEFT OUTER JOIN B
ON A.ID = B.ID
WHERE B.ID IS NULL;
```



**RIGHT OUTERJOIN**
$$
A^C \cap B
$$

```sql
SELECT *
FROM A RIGHT OUTER JOIN B
ON A.ID = B.ID
WHERE A.ID IS NULL;
```



### Symmetric difference

**Other**
$$
(A\cap B)^C
$$

```sql
SELECT *
FROM A FULL OUTER JOIN B
ON A.ID = B.ID
WHERE A.ID IS NULL OR B.ID IS NULL;
```

## Set Operation

#### UNION

* UNION

  * 집합의 합집합을 추출
  * 중복을제거함

* UNION ALL

  * 집합의 합집합을 추추

  * 중복을 제거하지않음

    **성능이 좋으므로 대부분 이렇게 사용함**

#### INTERSECT, EXCEPT

* INTERSECT

  집합의 교집합을 추출

* EXCEPT

  집합의 여집합을 추출

  **같은 컬럼일때** 
  
* ex
  
    데이터베이스를 강의하는 교수의 코드번호, 이름, 전화번호, 강의실을 조회하라
    
    ```SQL
    SELECT P.PCODE, P.PNAME, P.PPHONE, C.CROOM
    FROM PROFESSOR P, LECTURE L, COURSE C
    WHERE C.CCODE = L.LCCODE
  AND L.LPCODE = P.PCODE
  AND C.CNAME ='Database';
  ```
  
    박현주 교수님께서 강의하는 과목명, 강의 시수, 그리고 강의실을 조회하라
  
    ```	sql
    SELECT C.CNAME, C.CTIME, C.CROOM
    FROM PROFESSOR P, COURSE C, LECTURE L
    WHERE C.CCODE = L.LCCODE
  AND l.lpcode = P.PCODE
  AND P.PNAME ='박현주';
    ```
  
    학생이 수강 신청한 과목에 대해 학생이름, 학생 전화번호, 과목이름, 강의시수, 강의실을 조회하라.
    단, 조회결과는 학생이름의 오름차순, 과목이름의 내림차순으로 정렬하라.
  
    ```sql
  SELECT S.SNAME AS 학생이름, S.SPHONE AS "학생 전화번호", C.CNAME AS 과목이름, C.CTIME AS 강의시수, C.CROOM AS 강의실
  FROM STUDENT S, REGISTER R, COURSE C
    WHERE S.SCODE = R.RSCODE
    AND R.RCCODE = C.CCODE
    ORDER BY S.SNAME, C.CNAME DESC;
    ```
  
