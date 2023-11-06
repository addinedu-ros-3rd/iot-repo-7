<div align="center">
<h2>IoT 프로젝트 7조 저장소. 반려동물 자동 사료 배급기</h2>
<h3>[2023] 반려동물 자동 사료 배급기 제작 🎮</h3>
바쁜 일상 속에서 반려동물의 배급시간을 책임질 수 있는 기기, 집게리아입니다!<br> 간편하게 동작시킬 수 있으며
깔끔한 UI로 동시 제어할 수 있습니다🍀
</div>


## 프로젝트 개요
  - 팀명 : 밥 조
  - 팀원 : 이충한 강병철 이수민
  - 기간 : 23.10.23 ~ 23.10.30
  - 기술 키워드 :  모터제어, LCD, 음성입출력,<img src="https://img.shields.io/badge/PySerial-000000?style=for-the-badge&logo=serial&logoColor=white"> 
<img src="https://img.shields.io/badge/PyQt-41CD52?style=for-the-badge&logo=Qt&logoColor=white"> <img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"> <img src="https://img.shields.io/badge/python-3776AB?style=for-the-badge&logo=python&logoColor=white">

## 프로젝트 목적
  1. 편의성 --> 주인이 바빠서 배급 시간을 놓치는 경우 유용
  2. 반려동물 건강관리 --> 반려 동물의 규칙적인 식습관 
  3. 하드웨어 학습기회 --> 실제 하드웨어 구현을 해보며 하드웨어 지식 확장
  4. 아두이노 코딩 실력 향상 --> C언어 기반의 아두이노 숙련도 향상
  5. 직관적이고 편리한 사용법 ---> 사용자의 입장에서 편리성을 향상시키도록 노력

## 역할 분담
#### 이충한
###### 총괄
- 프로젝트 기획 및 물품구매


#### 이수민
###### 소프트웨어 팀장
- 데이터 흐름 구체화
- UI 디자인 설계
- 배급기 타이머 로직 개발
- 배급기 급여량 조절 로직 개발
- 배급기 UI 기본틀 제작 및 로직 개발
- serial 통신 로직 개발
- LCD 로직 개발 및 serial 통신 연동

#### 강병철
###### 하드웨어 팀장
- 하드웨어 설계 및 구현
- 데이터 흐름 구체화
- 깃 관리






### 기기 동작 방식
- 2개의 버튼으로 동작하며 왼쪽(확인) 오른쪽(상태변경) 버튼으로 이루어져있음
- 오른쪽(상태변경) 버튼을 누르게 되면 배급시간 배급량을 설정하는 상태로 변경
- 사용자가 원하는 시간과 배급량을 왼쪽(확인)버튼을 클릭하여 설정한다
- 그리고 기기 우측의 녹음(왼쪽), 재생(우측) 버튼을 통해 반려동물에게 배급 시간임을 인지하게 한다

### GUI 
- GUI를 활용하여 Arduino와의 Serial 통신을 통해 기기를 동작할 수 있다.
- 그림에 표시된 버튼을 누르게 되면 기기와 연동됨
    

