# [Gold II] 박스 채우기 - 1493 

[문제 링크](https://www.acmicpc.net/problem/1493) 

### 성능 요약

메모리: 56584 KB, 시간: 184 ms

### 분류

분할 정복, 그리디 알고리즘, 수학

### 제출 일자

2025년 7월 15일 13:13:41

### 문제 설명

<p>세준이는 length × width × height 크기의 박스를 가지고 있다. 그리고 세준이는 이 박스를 큐브를 이용해서 채우려고 한다. 큐브는 정육면체 모양이며, 한 변의 길이는 2의 제곱꼴이다. (1×1×1, 2×2×2, 4×4×4, 8×8×8, ...)</p>

<p>세준이가 가지고 있는 박스의 종류와 큐브의 종류와 개수가 주어졌을 때, 박스를 채우는데 필요한 큐브의 최소 개수를 출력하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 세 자연수 length width height가 주어진다.</p>

<p>둘째 줄에 세준이가 가지고 있는 큐브의 종류의 개수 N이 주어진다.</p>

<p>셋째 줄부터 총 N개의 줄에 큐브의 종류 A<sub>i</sub>와 개수 B<sub>i</sub>가 i가 증가하는 순서대로 주어진다. 큐브의 종류는 한 변의 길이를 나타낼 때 쓰는 2<sup>i</sup>에서 i이다.</p>

### 출력 

 <p>첫째 줄에 필요한 큐브의 개수의 최솟값을 출력한다. 만약 채울 수 없다면 -1을 출력한다.</p>

