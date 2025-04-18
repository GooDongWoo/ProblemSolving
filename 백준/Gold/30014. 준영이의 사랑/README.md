# [Gold III] 준영이의 사랑 - 30014 

[문제 링크](https://www.acmicpc.net/problem/30014) 

### 성능 요약

메모리: 2164 KB, 시간: 0 ms

### 분류

애드 혹, 자료 구조, 덱, 그리디 알고리즘, 정렬

### 제출 일자

2025년 2월 3일 09:21:26

### 문제 설명

<p>선린의 대표 스윗남인 준영이는 여자친구 아스나를 위한 선물을 준비 중이다. 그는 $N$개의 진주로 이루어진 <u><strong>원형</strong></u>의 진주 목걸이를 선물해 줄 생각이다.</p>

<p>$i$ $(1 \leq i \leq N)$번째 진주알은 가치 $P_{i}$를 지닌다. 이 진주알 $N$개를 적당한 순서로 재배열하여 목걸이의 가치가 최대가 되는 목걸이를 선물하려고 한다. 이때 임의로 재배열한 후 $i$번째 진주알의 가치를 $A_i$ $(1 \leq i \leq N)$라 하자. 목걸이의 가치 $X$는 서로 인접한 진주알 쌍에 대해 두 진주알의 가치를 곱한 값의 합이다.</p>

<p>수식으로 표현하면 다음과 같다. $X=A_{1}\times A_{2}+A_{2}\times A_{3} + \cdots +A_{N-1}\times A_{N}+A_{N}\times A_{1}$</p>

<p>목걸이의 가치 $X$의 최댓값과 그 가치가 나오기 위해 목걸이를 재배열했을 때 $i$번째 진주알의 가치 $A_i$를 출력하라. 가치가 최대인 목걸이 배치가 여러 가지 존재할 경우, 그 중 하나를 아무거나 출력한다.</p>

### 입력 

 <p>첫째 줄에 진주알의 개수 $N$이 주어진다.</p>

<p>둘째 줄에 각 진주알의 가치 $P_1$, $P_2$, $\cdots$, $P_N$이 공백으로 구분되어 주어진다. </p>

<p>입력으로 주어지는 수는 모두 정수이다.</p>

### 출력 

 <p>첫째 줄에 목걸이의 가치의 최댓값 $X$를 출력하라.</p>

<p>둘째 줄에 위의 가치가 나오기 위한 목걸이를 재배열하였을 때 각 진주알의 가치에 해당하는 $N$개의 수 $A_1$, $A_2$, $\cdots$, $A_N$를 공백으로 구분하여 출력하라.</p>

