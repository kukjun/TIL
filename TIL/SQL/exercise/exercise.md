![image-20200722234735819](C:\Users\klop0\AppData\Roaming\Typora\typora-user-images\image-20200722234735819.png)

\# 프라이머리 키

\* 낫널

\0 널 가능

까마귀 1대 다

FK 왜래키



1. ENTERTAINMENT 데이터베이스 생성

   ```sql
   CREATE DATABASE ENTERTAINMENT ENCODING 'UTF-8';
   ```

2. ENTERTAINMENT 데이터베이스 사용자 생성

   ```sql
   CREATE USER maker WITH PASSWORD 'zxcv4489';
   ```

3. maker에게 권한 주기

   ```sql
   GRANT all ON DATABASE ENTERTAINMENT TO maker WITH GRANT OPTION;
   ```

4. 부서(DEPARTMENT) 테이블 생성

   ```sql
   CREATE TABLE DEPARTMENT (
   	DEPT_CODE VARCHAR(4) NOT NULL PRIMARY KEY,
   	DEPT_NAME VARCHAR(10) NOT NULL,
   	DEPT_LOC VARCHAR(10) NULL
   );
   ```

   * PRIMARY KEY는 각 테이블에 한개씩만 존재함

5. 부서(DEPARTMENT) 데이터 삽입

   ```sql
   INSERT INTO DEPARTMENT VALUES ('D001', '배우', '서울특별시');
   INSERT INTO DEPARTMENT VALUES ('D002', '뮤지컬배우', '서울특별시');
   INSERT INTO DEPARTMENT VALUES ('D003', '가수(솔로)', '서울특별시');
   INSERT INTO DEPARTMENT VALUES ('D004', '가수(그룹)', '서울특별시');
   INSERT INTO DEPARTMENT VALUES ('D005', '코미디언', '서울특별시');
   INSERT INTO DEPARTMENT VALUES ('D101', '드라마제작', '서울특별시');
   INSERT INTO DEPARTMENT VALUES ('D102', '영화제작', '대전광역시');
   INSERT INTO DEPARTMENT VALUES ('D103', '음반제작', '수원시');
   INSERT INTO DEPARTMENT VALUES ('D104', '예능제작', '서울특별시');
   INSERT INTO DEPARTMENT VALUES ('D201', '스테프');
   INSERT INTO DEPARTMENT VALUES ('D301', '임원', '서울특별시');
   ```

6. 연예관계자(EMPLOYEE) 테이블 등록하기 전에 연예관계자직급(EMP_ROLE)테이블 등록

   ```sql
   CREATE TABLE EMP_ROLE(
   EMP_RCODE VARCHAR(4) NOT NULL PRIMARY KEY,
   EMP_RNAME VARCHAR(10) NOT NULL
   );
   ```

7. 연예관계자직급(EMP_ROLE) 데이터 작성

   ```sql
   INSERT INTO EMP_ROLE VALUES ('R001', '엔터테이너');
   INSERT INTO EMP_ROLE VALUES ('R002', '국장');
   INSERT INTO EMP_ROLE VALUES ('R003', '실장');
   INSERT INTO EMP_ROLE VALUES ('R004', '대리');
   INSERT INTO EMP_ROLE VALUES ('R005', '사원');
   INSERT INTO EMP_ROLE VALUES ('R006', '이사');
   INSERT INTO EMP_ROLE VALUES ('R007', '사장');
   ```

8. 연예관계자(EMPLOYEE) 테이블 등록

   ```sql
   CREATE TABLE EMPLOYEE(
   	EMP_CODE VARCHAR(4) NOT NULL PRIMARY KEY,
   	EMP_NAME VARCHAR(10) NOT NULL,
   	EMP_MGT VARCHAR(4) NOT NULL,
   	EMP_SAL INT NOT NULL,
       EMP_RCODE VARCHAR(4) NOT NULL,
       CONSTRAINT emprcode_fk FOREIGN KEY(EMP_RCODE) REFERENCES EMP_ROLE(EMP_RCODE)
   );
   ```

9. 연예관계자 테이블 데이터 등록

   ```sql
   INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, EMP_MGT, EMP_SAL, EMP_RCODE)
   VALUES ('E001', '김민훈', 'E202', 5500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E002', '손지민', 'E201', 4500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E003', '이순신', 'E203', 4500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E004', '강혁민', 'E201', 4500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E005', '옥주인', 'E201', 4500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E006', '신승모', 'E202', 4500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E007', '김건훈', 'E202', 4500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E008', '소년시대', 'E203', 4500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E009', '유재동', 'E203', 8500, 'R001');
   INSERT INTO EMPLOYEE VALUES ('E101', '강동민', 'E902', 7500, 'R002');
   INSERT INTO EMPLOYEE VALUES ('E102', '문성준', 'E902', 7500, 'R002');
   INSERT INTO EMPLOYEE VALUES ('E103', '한동화', 'E902', 7500, 'R002');
   INSERT INTO EMPLOYEE VALUES ('E201', '홍길동', 'E902', 3000, 'R003');
   INSERT INTO EMPLOYEE VALUES ('E202', '일지매', 'E101', 2750, 'R004');
   INSERT INTO EMPLOYEE VALUES ('E203', '김수현', 'E102', 2750, 'R004');
   INSERT INTO EMPLOYEE VALUES ('E204', '신용주', 'E103', 2500, 'R005');
   INSERT INTO EMPLOYEE VALUES ('E901', '이수민', '', 5000, 'R007');
   INSERT INTO EMPLOYEE VALUES ('E902', '김형석', 'E901', 4000, 'R006');
   ```

10. 연예관계자의 소속 부서(REL_DEPARTMENT) 테이블 생성

    ```sql
    CREATE TABLE REL_DEPARTMENT (
    	RD_EMP_CODE VARCHAR(4) NOT NULL,
    	RD_DEPT_CODE VARCHAR(4) NOT NULL,
    	PRIMARY KEY (RD_EMP_CODE, RD_DEPT_CODE),
        CONSTRAINT rdempcode_fk FOREIGN KEY(RD_EMP_CODE) REFERENCES EMPLOYEE(EMP_CODE),
        CONSTRAINT rddeptcode_fk FOREIGN KEY(RD_DEPT_CODE) REFERENCES DEPARTMENT(DEPT_CODE)
    );
    ```

11. 연예관계자 소속 부서(REL_DEPARTMENT) 데이터 작성

    ```sql
    INSERT INTO REL_DEPARTMENT VALUES ('E001', 'D001');
    INSERT INTO REL_DEPARTMENT VALUES ('E001', 'D002');
    INSERT INTO REL_DEPARTMENT VALUES ('E002', 'D001');
    INSERT INTO REL_DEPARTMENT VALUES ('E003', 'D001');
    INSERT INTO REL_DEPARTMENT VALUES ('E003', 'D003');
    INSERT INTO REL_DEPARTMENT VALUES ('E004', 'D001');
    INSERT INTO REL_DEPARTMENT VALUES ('E004', 'D002');
    INSERT INTO REL_DEPARTMENT VALUES ('E005', 'D002');
    INSERT INTO REL_DEPARTMENT VALUES ('E006', 'D003');
    INSERT INTO REL_DEPARTMENT VALUES ('E007', 'D003');
    INSERT INTO REL_DEPARTMENT VALUES ('E008', 'D004');
    INSERT INTO REL_DEPARTMENT VALUES ('E009', 'D005');
    INSERT INTO REL_DEPARTMENT VALUES ('E101', 'D101');
    INSERT INTO REL_DEPARTMENT VALUES ('E102', 'D102');
    INSERT INTO REL_DEPARTMENT VALUES ('E103', 'D103');
    INSERT INTO REL_DEPARTMENT VALUES ('E201', 'D201');
    INSERT INTO REL_DEPARTMENT VALUES ('E202', 'D201');
    INSERT INTO REL_DEPARTMENT VALUES ('E203', 'D201');
    INSERT INTO REL_DEPARTMENT VALUES ('E204', 'D201');
    INSERT INTO REL_DEPARTMENT VALUES ('E901', 'D301');
    INSERT INTO REL_DEPARTMENT VALUES ('E902', 'D301');
    ```

12. 영화(MOVIE) 테이블 생성, 데이터 삽입

    ```sql
    CREATE TABLE MOVIE (
    	MOV_CODE VARCHAR(5) NOT NULL PRIMARY KEY,
        MOV_NAME VARCHAR(10) NOT NULL,
        MOV_MPAA VARCHAR(2) NOT NULL,
        MOV_PDDATE DATE NOT NULL,
        MOV_OPDATE DATE NULL
    );
    
    INSERT INTO MOVIE VALUES ('MOV01', '모래가 흐르는 바다', 'A', '2013.01.01', '2013.01.01');
    INSERT INTO MOVIE VALUES ('MOV02', '프랜드', '18', '2013.01.15', '2013.01.15');
    INSERT INTO MOVIE VALUES ('MOV03', '5급 공무원', '15', '2013.02.01', '2013.02.01');
    INSERT INTO MOVIE VALUES ('MOV04', '사랑', '18', '2013.02.01', '2013.02.01');
    INSERT INTO MOVIE VALUES ('MOV05', '킬러', '18', '2013.02.08', '2013.02.08');
    INSERT INTO MOVIE VALUES ('MOV06', '스토커', '18', '2013.02.28', '2013.02.28');
    INSERT INTO MOVIE VALUES ('MOV07', '더 울버린', '15', '2013.07.25');
    INSERT INTO MOVIE VALUES ('MOV08', '여름', '15', '2013.07.31');
    INSERT INTO MOVIE VALUES ('MOV09', '봄', 'A', '2013.03.01', '2013.03.01');
    INSERT INTO MOVIE VALUES ('MOV10', '저스트 어 이어', '12', '2013.05.01');
    ```

13. 드라마(DRAMA) 테이블 생성, 데이터 삽입

    ```sql
    CREATE TABLE DRAMA (
    	DRM_CODE VARCHAR(5) NOT NULL PRIMARY KEY,
        DRM_NAME VARCHAR(10) NOT NULL,
        DRM_PRD VARCHAR(5) NOT NULL,
        DRM_BRD VARCHAR(3) NOT NULL,
        DRM_OPDATE DATE NULL
    );
    
    INSERT INTO DRAMA VALUES ('DRM01', '왕의 게임', 'TG', 'SBC', '2013.01.01');
    INSERT INTO DRAMA VALUES ('DRM02', '아이러시', 'SN', 'KBC', '2013.01.01');
    INSERT INTO DRAMA VALUES ('DRM03', '야킹', 'TG', 'SBC', '2013.02.01');
    INSERT INTO DRAMA VALUES ('DRM04', '닥터 호', 'HNU-E', 'MBC', '2013.02.01');
    INSERT INTO DRAMA VALUES ('DRM05', '5급 사무관', 'SN', 'MBC', '2013.02.15');
    INSERT INTO DRAMA VALUES ('DRM06', '그 사람', 'XTS', 'XTS', '2013.02.15');
    INSERT INTO DRAMA VALUES ('DRM07', '여왕의 꿈', 'HNU-E', 'KBC', '2013.03.15');
    INSERT INTO DRAMA VALUES ('DRM08', '머니의 화신', 'TG', 'SBC', '2013.3.15');
    INSERT INTO DRAMA VALUES ('DRM09', '회사의 신', 'SN', 'KBC');
    INSERT INTO DRAMA VALUES ('DRM10', '수의사', 'HNU-E', 'XTS');
    ```

14. 음반(MUSIC) 테이블 생성, 데이터 삽입

    ```sql
    CREATE TABLE MUSIC (
    	MSC_CODE VARCHAR(5) NOT NULL PRIMARY KEY,
        MSC_NAME VARCHAR(10) NOT NULL,
        MSC_DATE DATE NOT NULL,
        MSC_PRICE VARCHAR(10) NOT NULL,
        MSC_CSF VARCHAR(2) NULL
    );
    
    INSERT INTO MUSIC VALUES ('MSC01', '소년시대 2013', '2013.01.01', '8,000', '싱글');
    INSERT INTO MUSIC VALUES ('MSC02', '하이퍼주니어 4집', '2013.01.05', '15,500', '정규');
    INSERT INTO MUSIC VALUES ('MSC03', '이승모 연인', '2013.01.31', '7,000', '싱글');
    INSERT INTO MUSIC VALUES ('MSC04', '박장현 사랑', '2013.02.01', '7,000', '싱글');
    INSERT INTO MUSIC VALUES ('MSC05', '김건훈 5집', '2013.02.08', '12,500', '정규');
    INSERT INTO MUSIC VALUES ('MSC06', '원더우먼 봄', '2013.02.28', '9,500', '싱글');
    INSERT INTO MUSIC VALUES ('MSC07', '슈퍼맨 안녕', '2013.03.25', '9,500', '싱글');
    INSERT INTO MUSIC VALUES ('MSC08', '소년시대 4집', '2013.04.01', '13,500', '정규');
    INSERT INTO MUSIC VALUES ('MSC09', '핑키 러브', '2013.04.01', '10,500', '싱글');
    INSERT INTO MUSIC VALUES ('MSC10', '신승모 6집', '2013.04.02', '18,500', '정규');
    
    ```

15. 영화 출연 테이블 생성, 데이터 삽입

    ```sql
    CREATE TABLE PART_MOVIE(
        PM_MOV_CODE VARCHAR(5) NOT NULL,
    	EMP_CODE VARCHAR(4) NOT NULL,
        PM_EMP_ROLE VARCHAR(2) NOT NULL,
        PM_MOV_FEE INT NULL,
        PRIMARY KEY (EMP_CODE, PM_MOV_CODE),
        CONSTRAINT pmmovcode_fk FOREIGN KEY(PM_MOV_CODE) REFERENCES MOVIE(MOV_CODE),
        CONSTRAINT empcode_fk FOREIGN KEY(EMP_CODE) REFERENCES EMPLOYEE(EMP_CODE)
    );
    
    INSERT INTO PART_MOVIE VALUES ('MOV03', 'E003', '주연', 13500);
    INSERT INTO PART_MOVIE VALUES ('MOV03', 'E001', '조연', 7500);
    INSERT INTO PART_MOVIE VALUES ('MOV05', 'E002', '단역', 3500);
    INSERT INTO PART_MOVIE VALUES ('MOV08', 'E004', '단역', 3500);
    INSERT INTO PART_MOVIE VALUES ('MOV09', 'E001', '조연', 8000);
    INSERT INTO PART_MOVIE VALUES ('MOV09', 'E004', '단역', 3000);
    
    ```

16. 드라마 출연 테이블 생성, 데이터 삽입

    ```sql
    CREATE TABLE PART_DRAMA(
    	PD_DRM_CODE VARCHAR(5) NOT NULL,
        PD_EMP_CODE VARCHAR(4) NOT NULL,
        PD_EMP_ROLE VARCHAR(2) NOT NULL,
        PD_EMP_FEE INT NULL,
        PRIMARY KEY(PD_DRM_CODE, PD_EMP_CODE),
        CONSTRAINT pddrmcode_fk FOREIGN KEY(PD_DRM_CODE) REFERENCES DRAMA(DRM_CODE),
        CONSTRAINT pdempcode_fk FOREIGN KEY(PD_EMP_CODE) REFERENCES EMPLOYEE(EMP_CODE)
    );
    
    INSERT INTO PART_DRAMA VALUES ('DRM02', 'E003', '주연', 13500);
    INSERT INTO PART_DRAMA VALUES ('DRM02', 'E001', '조연', 7500);
    INSERT INTO PART_DRAMA VALUES ('DRM02', 'E004', '단역', 3500);
    INSERT INTO PART_DRAMA VALUES ('DRM05', 'E001', '주연', 7500);
    INSERT INTO PART_DRAMA VALUES ('DRM05', 'E004', '단역', 0);
    INSERT INTO PART_DRAMA VALUES ('DRM05', 'E002', '단역', 0);
    INSERT INTO PART_DRAMA VALUES ('DRM08', 'E002', '조연', 6500);
    INSERT INTO PART_DRAMA VALUES ('DRM10', 'E003', '주연', 15000);
    
    ```

17. 음반 참여 테이블 생성, 데이터 삽입

    ```sql
    CREATE TABLE PART_MUSIC(
    	PM_MSC_CODE VARCHAR(5) NOT NULL,
        PM_EMP_CODE VARCHAR(4) NOT NULL,
        PM_EMP_ROLE VARCHAR(3) NOT NULL,
        PM_EMP_FEE INT NULL,
        PRIMARY KEY(PM_MSC_CODE, PM_EMP_CODE),
        CONSTRAINT pmmsccode_fk FOREIGN KEY(PM_MSC_CODE) REFERENCES MUSIC(MSC_CODE),
        CONSTRAINT pmempcode_fk FOREIGN KEY(PM_EMP_CODE) REFERENCES EMPLOYEE(EMP_CODE)
    );
    
    INSERT INTO PART_MUSIC VALUES
    ('MSC01', 'E008', '메인', 8500),
    ('MSC03', 'E007', '피처링', 1500),
    ('MSC04', 'E001', '피처링', 1500),
    ('MSC08', 'E008', '메인', 13500),
    ('MSC10', 'E006', '메인', 15500);
    ```


## SAMPLE

1. HNU 엔터테인먼트의 부서의 코드, 이름, 위치를 검색하시오.

   ```sql
   SELECT D.DEPT_CODE, D.DEPT_NAME, D.DEPT_LOC
   FROM DEPARTMENT D;
   ```

2. HNU 엔터테인먼트의 연예관계자인 코드, 이름, 관리자, 급여를 검색하시오.

   ```sql
   SELECT E.EMP_CODE, E.EMP_NAME, E.EMP_MGT, E.EMP_SAL
   FROM EMPLOYEE E;
   ```

3. 2013년에 제작된 영화의 코드, 이름, 관람등급, 출시년월, 개봉년월을 검색하시오.

   ```sql
   SELECT M.MOV_CODE, M.MOV_NAME, M.MOV_MAPP, M.MOV_PDDATE, M.MOV_OPDATE
   FROM MOVIE M;
   ```

4. 2013년에 제작된 드라마의 코드, 이름, 제작사, 방영사, 방영년월을 검색하시오.

   ```sql
   SELECT D.DRM_CODE, D.DRM_NAME, D.DRM_PRD, D.DRM_BRD, D.DRM_OPDATE
   FROM DRAMA D;
   ```

5. 2013년에 제작된 음반의 코드, 이름, 출시일자, 가격을 검색하시오,

   ```sql
   SELECT M.MSC_CODE, M.MSC_NAME, M.MSC_DATE, M.MSC_PRICE
   FROM MUSIC M;
   ```

6. 우리 회사(HNU-E)에서 제작한 드라마의 코드와 이름을 검색하시오.

   ```sql
   SELECT D.DRM_CODE, D.DRM_NAME
   FROM DRAMA D;
   ```

7. 음반 구분이 싱글인 음반의 코드, 이름, 출시일자를 검색하시오.

   ```sql
   SELECT M.MSC_CODE, M.MSC_NAME, M.MSC_DATE
   FROM MUSIC M
   WHERE M.MSC_CSF = '싱글';
   ```

8. 음반 구분이 정규의 코드, 이름,  출시일자, 가격을 검색하시오.

   ```sql
   SELECT M.MSC_CODE, M.MSC_NAME, M.MSC_DATE, M.MSC_PRICE
   FROM MUSIC M
   WHERE M.MSC_CSF = '정규';
   ```

9. **2013년 3월 이후**에 출시된 영화의 이름, 관람등급을 검색하시오.

   ```sql
   SELECT M.MOV_NAME, M.MOV_MPAA
   FROM MOVIE M
   WHERE M.MOV_PDDATE >= '2013-04-01';
   ```

10. 음반 가격이 만원 이상인 음반의 이름과 가격을 검색하시오. ==실패 - 데이터 잘못만듬== 

    ```sql
    SELECT M.MSC_NAME, M.MSC_PRICE
    FROM MUSIC M
    WHERE M.MSC_PRICE >= '10,000';
    ```

11. 영화 중 전체 관람 등급이거나 16세 미만이 볼 수 있는 영화 코드와 이름을 검색하시오.

    ```sql
    SELECT M.MOV_CODE, M.MOV_NAME
    FROM MOVIE M
    WHERE M.MOV_MPAA = 'A' OR M.MOV_MPAA = '15';
    ```

12. 드라마 **방영사가 KBC이거나 SBC**인 드라마를 검색하시오.

    ```sql
    SELECT *
    FROM DRAMA D
    WHERE D.DRM_BRD = 'KBC' OR D.DRM_BRD = 'SBC';
    ```

13. 2013년도에 드라마를 제작한 드라마제작사를 검색하시오, 단, 중복된 값이 있으면 제거하시오.

    ```sql
    SELECT DISTINCT D.DRM_PRD
    FROM DRAMA D;
    ```

14. 연예관계자들의 급여의 총합과 평균 급여액을 계산하시오.

    ```sql
    SELECT SUM(EMP_SAL) 합계, ROUND( (AVG(EMP_SAL)), 2) 평균
    FROM EMPLOYEE;
    ```

15. 아직 방영일자가 확정되지 않은 드라마의 이름을 검색하시오.  ==실패==

    ```sql
    SELECT DRM_NAME
    FROM DRAMA
    WHERE DRM_OPDATE = NULL;
    ```

16. 방영일자가 확정되지 않은 드라마의 방영일자가 '2013-05-01'로 편성되었습니다. 방영일자를 편성일에 맞게 변경하시오. ==실패==

    ```	sql
    UPDATE DRAMA SET DRM_OPDATE ='2013-05-01'
    WHERE DRM_OPDATE = NULL;
    ```

17. 연예관계자의 이름과 현재 직급을 검색하시오.

    ```sql
    SELECT E.EMP_NAME, ER.EMP_RNAME
    FROM EMPLOYEE E, EMP_ROLE ER
    WHERE E.EMP_RCODE = ER.EMP_RCODE;
    ```

18. 연예관계자가 소속된 부서의 이름과 연예 관계자의 이름을 검색하시오.

    ```sql
    SELECT D.DEPT_NAME, E.EMP_NAME
    FROM EMPLOYEE E, REL_DEPARTMENT RD, DEPARTMENT D
    WHERE E.EMP_CODE = RD.RD_EMP_CODE
    AND RD.RD_DEPT_CODE = D.DEPT_CODE;
    ```

19. 연예관계자가 소속된 부서의 이름과 연예 관계자의 이름을 검색하시오. 단, 부서를 기준으로 출력해야함.

    ```sql
    SELECT D.DEPT_NAME, E.EMP_NAME
    FROM DEPARTMENT D, EMPLOYEE E, REL_DEPARTMENT RD
    WHERE E.EMP_CODE = RD.RD_EMP_CODE
    AND RD.RD_DEPT_CODE = D.DEPT_CODE
    ORDER BY D.DEPT_NAME;
    ```

20. 연예 관계자에 대해 연예관계자의 이름과 직속 상사의 이름을 검색하시오. 

    ```sql
    SELECT E.EMP_NAME "연예관계자의 이름", EM.EMP_NAME "직속상사 이름"
    FROM EMPLOYEE E, EMPLOYEE EM
    WHERE E.EMP_MGT = EM.EMP_CODE;
    ```

21. 배우와 가수를 겸업하는 연예관계자의 이름을 검색하시오. ==실패==

    ```sql
    SELECT E.EMP_NAME
    FROM EMPLOYEE E, REL_DEPARTMENT RD, DEPARTMENT D
    WHERE E.EMP_CODE = RD.RD_EMP_CODE
    AND D.DEPT_CODE = RD.RD_DEPT_CODE
    AND D.DEPT_NAME = '배우'
    AND (
        D.DEPT_NAME = '가수(솔로)'
        OR D.DEPT_NAME = '가수(그룹)'
        );
    ```

    ```sql
    
    SELECT EMP_NAME
    FROM REL_DEPARTMENT, EMPLOYEE, DEPARTMENT
    WHERE REL_DEPARTMENT.RD_EMP_CODE = EMPLOYEE.EMP_CODE
    AND REL_DEPARTMENT.RD_DEPT_CODE = DEPARTMENT.DEPT_CODE
    AND DEPARTMENT.DEPT_NAME = '배우'
    INTERSECT
    SELECT EMP_NAME
    FROM REL_DEPARTMENT, EMPLOYEE, DEPARTMENT
    WHERE REL_DEPARTMENT.RD_EMP_CODE = EMPLOYEE.EMP_CODE
    AND REL_DEPARTMENT.RD_DEPT_CODE = DEPARTMENT.DEPT_CODE
    AND DEPARTMENT.DEPT_NAME LIKE '가수%';
    ```

22. 모든 연예관계자에 대해 이름과 급여를 출력하고 급여의 내림차순으로 정렬하시오. 단, 동일한 급여액일 때 이름의 오름차순으로 정렬해야함

    ```sql
    SELECT EMP_NAME 이름, EMP_SAL 급여
    FROM EMPLOYEE
    ORDER BY EMP_SAL, EMP_NAME DESC;
    ```

23. 부서별로 모든 연예관계자에 대해 이름과 급여를 출력하고, 급여의 내림차순으로 정렬하시오. 단 동일한 급여액일 때 이름의 오름차순으로 정렬해야함.

    ```sql
    SELECT D.DEPT_NAME 부서이름, E.EMP_NAME 이름, E.EMP_SAL 급여
    FROM EMPLOYEE E, REL_DEPARTMENT RD, DEPARTMENT D
    WHERE E.EMP_CODE = RD.RD_EMP_CODE
    AND D.DEPT_CODE = RD.RD_DEPT_CODE
    ORDER BY D.DEPT_NAME, E.EMP_SAL, E.EMP_NAME DESC;
    ```

24. 영화에서 주연을 맡은 연예관계자의 이름과 영화 이름을 검색하시오.

    ```sql
    SELECT E.EMP_NAME 이름, M.MOV_NAME 영화이름
    FROM EMPLOYEE E, PART_MOVIE PM, MOVIE M
    WHERE E.EMP_CODE = PM.EMP_CODE
    AND PM.PM_MOV_CODE = M.MOV_CODE
    AND PM.PM_EMP_ROLE='주연';
    ```

25. 모든 연예관계자에 대해 직급별로 그룹화 하고, 평균 급여액이 5000 이상인 직급에 대해 연예관계자의 직급과 평균 급여액, 최소 급여액, 최대 급여액을 검색하라

    ```sql
    SELECT 
    FROM EMPLOYEE E, EMP_ROLE ER
    WHERE E.EMP_RCODE = ER.EMP_RCODE
    GROUP BY EMP_RNAME
    ```

    
