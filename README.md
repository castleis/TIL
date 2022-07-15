# TIL

---

### Ground Rule

1. 오늘 배운 것들을 차곡차곡
  - 그날 배운 것은 그날 Commit



---

### [220714](C:\Users\multicampus\dev\til\220714.md)

### 220715
**Git정리**
##### 협업 복구 백업

> Git과 Github는 다르다.

Git은 분산 버전 관리 시스템, Github는 git을 통해 이용하는 Cloud 서비스
> 

#### Git 기본 명령어

**로컬 레포지토리**

1. Local Repository를 생성할 때 `git init`
2. Working Directory에 생긴 변화 사항 (파일 생성, 삭제, 수정 등)을 버전으로 관리하고자 Staging Area에 올리는 명령어 `git add {file.확장자}`
    - 현재 경로를 의미하는 `git add .` : 현재 WD에 생긴 모든 변경 사항을 한번에 Staging Area에 올리는 명령어
3. 버전을 기록할 때, Commit을 남길 때 : `git commit -m "커밋내용(최대한 상세하게)`
4. file의 상태 :
    1. `untracked` : git이 아직 관리하고 있지 않다.
    2. `tracked` : add 명령어를 통해서 Staging Area에 올라간 파일
5. `git status` : 현재 Local Repository의 상태를 확인하는 명령어 (**습관처럼 입력하기**)
---
### 협업과 복구 및 백업

**원격 저장소 연결**

1. github에 원격 저장소를 생성
2. 로컬 저장소 (Repository) 생성
3. **원격 저장소에 Push하기 전에 반드시 최소 1개 이상의 commit을 가져야 한다.**

**원격 저장소 연결 명령어**

1. `git remote add origin {Repository Url}`
2. `git remote -v origin {url}` : 등록한 Remote Repository 정보 확인
3. `git push -u origin master` :로컬에서 생긴 커밋 내역을 업로드
    - `-u` 를 한번이라도 사용하면  git push만 쳐도 origin master에 push
4. `git pull origin master` : 원격 저장소의 변화 사항을 업데이트
5. `git clone {Git Repository Url}` : 원격 저장소를 복제해온다. (로컬 저장소에 없을 때)

### **Git ignore**

처음 레포지토리를 생성할 때 만들어야 하는 파일

- `README.md`
- `.gitignore` → Git에 올리면 안되는, 올리고 싶지 않은 파일 설정
    - `.gitignore` 에 폴더 전체를 설정할 수도 있다.
    - `.gitignore`에 `파일명.확장자` or `/폴더이름` 적어놓으면 끝!

**API**
