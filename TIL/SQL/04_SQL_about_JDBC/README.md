# Getting Started with PgSQL

## Introduction

### About JDBC

**자바를 이용하여 데이터베이스 관련 작업을 할 수 있도록 해주는 자바 프로그래밍 인터페이스를 위한 API 규격**

* API
  : Application Programming Interface

Interface로 정의

* 데이터베이스 제조사등은 자신들의 데이터베이스에 접속해서 작업할 수 있도록 Interface를 구현하여 드라이버 클래스를 만들어서 프로그래머들에게 제공
* 표준적인 JDBC의 사용법만 익히면 JDBC를 제공하는 모든 데이터베이스에 대해 프로그래밍을 할 수 있음
* 프로그래밍 언어에 따라 문법이 조금 다를 수 있음

<br>

### History

Microsoft社의 Open Database Connectivity(**ODBC**)의 영향을 받아 제작

자바는 필요하다면  ODBC를 직접 이용할 수도 있음.

* 하지만 ODBC가 C언어로 제작되었기 때문에 복잡한 작업이 필요하고, 자바의 객체지향적인 언어적 장점을 살릴 수 없는 문제가 발생함.

순수 자바 기술이 적용된 JDBC를 만들게 되었음.

<br><br>

## Driver Type

### DBMS 등장 전

![image-20200811101438157](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811101438157.png)<br>

### DBMS 등장

![image-20200811101524517](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811101524517.png)

<br>

### DBMS 사용 규칙

![image-20200811101557455](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811101557455.png)<br>

###  SQL 전달 및 데이터 수신

#### SQL 전송 프로토콜

![image-20200811101943730](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811101943730.png)<br>

#### DBMS 전용 통신 프로토콜

![image-20200811102010615](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811102010615.png)<br>

![image-20200811101812396](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811101812396.png)<br><br>

## JDBC 구조

프로그래머가 이용하기 위한 API 명세인 Interface

* interface의 핵심부 - DriverManager Class
* Driver Class - 다양한 드라이버를 자바 응용 프로그램과 연결시켜 주는 역할

실제 데이터베이스와 연결을 책임지는 드라이버(Driver)

* JDBC 인터페이스에 맞추어 해당 DBMS에서 JDBC 관련 API 호출이 가능하도록 관련 인터페이스와 클래스를 구현한 클래스 라이브러리

<br>

## JDBC Driver Types

다양한 단체와 업체에서 만들어지므로 다양한 방식으로 제작 (4가지 타입)

#### JDBC-ODBC Bridge Driver

* 특징

  JRE에 기본으로 포함

  ODBC 드라이버 사용

  속도 느리다.

  Excel, Text 데이터에 접근할 때 유용

![image-20200811102724454](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811102724454.png)<br>

#### Native-API Driver

* 특징

  별도 다운로드 필요

  ODBC 사용 안 함

  Native API 호출

![image-20200811102814131](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811102814131.png)<br>

#### JDBC Network Protocol Driver (Middleware Driver)

* 특징

  Native-API Driver와 동일

#### DBMS Protocol Driver (Pure Java Driver)

Vendor-specific database protocol, Oracle Thin Driver

* 특징

  별도 다운로드 필요

  DBMS와 직접 통신

  Pure Java

![image-20200811102920138](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200811102920138.png)<br>

## JDBC Programming



## Connection Test

