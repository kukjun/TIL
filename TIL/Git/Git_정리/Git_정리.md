# Git

<br>

## Git 개요

### Git?

* Git은 버전 관리 시스템(VCS, Version Control System)중 가장 유명한 프로그램
  * Github, Gitlab은 Git의 데이터를 저장하는 서버
* 컴퓨터 파일의 변경사항을 추적하고 여러 명의 사용자들 간에 해당 파일들의 작업을 조율하기 위한 분산 버전 관리 시스템.
* Github은 웹 상에 소스 코드를 올려서 여러 사람과 공유하는 장소

### Git의 필요성

* 버전에 따라 코드를 수정할 필요성이 있고, 파일들을 백업해서 관리가 필요함
  * 서버와 개인이 서로 파일을 가지고 문제가 생기면 서로 백업하는 형식

<br>

## 스냅샷

* 기술적인 용어로, 특정 시간에 저장 장치의 상태를 나타내며, 스냅 샷의 동작으로 보존되어 데이터 저장에 실패한 경우 데이터 백업 기능을 복원함.

![

](https://camo.githubusercontent.com/b337e89591990cffe548b0877fa6006b98e9bf3f/68747470733a2f2f6769742d73636d2e636f6d2f626f6f6b2f656e2f76322f696d616765732f736e617073686f74732e706e67)

시간 순서대로 프로젝트의 스냅샷을 저장.

<br>

## Git 관리 방법

Git은 파일을 세 가지 상태로 관리한다.

* Modified : 파일을 수정한 상태로 아무 작업도 하지 않은 상태
  
* Staged : 수정한 파일을 커밋하기 전에 Staging Area에 올린 상태.
* Commited :  Staging area의 데이터가 로컬 데이터베이스에 안전하게 저장된 상태

![img](https://camo.githubusercontent.com/44163c6ce4b34e84e122453be40207b601f0d3df/68747470733a2f2f6769742d73636d2e636f6d2f626f6f6b2f656e2f76322f696d616765732f61726561732e706e67)

Git 프로젝트의 세가지 단계
* Working directory : .git 이 존재하는 디렉토리에서 파일을 수정하게되면 git이 working directory로 상태가 변한다.
* Staging area : working directory에서 수정한 파일을 커밋하기 전까지 임시로 저장하는 상태
* .git directory : 파일들을 커밋해서 자신의 git directory에 영구적인 스냅샷으로 저장한다.

## Git 초기 설정

### SSH

SSH란 Secure Shell Protocol, 의 약자로 컴퓨터와 컴퓨터가 인터넷과 같은 Pubilc Network를 통해 서로 통신을 할 때 보안적으로 안전하게 통신을 하기 위해 사용하는 프로토콜이다.

* 매번 로그인을 할때마다 로그인 정보들을 주고 받는다면 정보를 직접 네트워크를 통해 넘기기 때문에 누구나 해당 정보를 열어볼 수 있어 보안에 상당히 취약해 SSH Key를 사용한다.

Public Key와 Private Key를 서로 비교해 서로 관계를 맺고 있는것이 증명되면 암호화된 채널이 형성되어 안전하게 데이터를 주고 받을 수 있다.

#### Public Key

공개되어도 안전한 Key로 암호화는 가능하지만 복호화는 불가능하다.

* 통신에 응답하는 서버에 저장된다.

#### Private Key

절대 공개되면 안되는 Key로 암호화된 Public Key를 복호화 할 수 있다.

* 통신을 요청하는 컴퓨터에 저장된다.

#### 인증키 생성방법

```bash
ssh-ed25519 -C "comment"
```

* -C

  코멘트를 남기는 플래그

* rsa는 키가 너무 길어서 안되는 경우도 있음(??)

```c
Enter passphrase (empty for no passphrase): // passphrase 입력 10~30 문자
```

* 자동 로그인을 원할 경우 입력하지 않고 Enter를 누른다.

이러한 과정을 거치면 Private  Key와 Public Key가 만들어진다.

### git init

새로운 local repository 생성하는 명령어

```bash
git init
```

