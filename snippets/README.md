자동 코드조각
---
# 사용법
파일 상단에
```
/*!
prefix: ps
title: ps 기본 템플릿
description: ps 기본 템플릿을 생성합니다.
!*/
```
이렇게 명시한다.


그 후 `python make_snippets.py`를 실행하면 `library.code-snippets`가 생성된다.

그를 `.vscode`에 넣으면 된다.

추가적으로, 에러 표시를 방지하기 위해
```
//!$0 # 이런 형태로 예약어를 사용할 수 있다. (//!만 없어짐)
//[, //] # 이런 형태로 부분 코드를 사용할 수 있다.
```

# 목록
## 0. 기타
### 00. 템플릿
- `ps` : ps 템플릿
- `pss` : ps 심플 템플릿
- `cpp` : cpp 기본 템플릿
### 01. cheet sheet
- `comp` : 좌표압축
## 1. 그래프
### 10. 그래프 기본
- `uf` : union-find
### 11. 최단경로
- `dijkstra` : 다익스트라
- `bellmanford` : 벨만포드
- `spfa` : SPFA
- `floyd` : 플로이드

WIP