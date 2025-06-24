# [Gold IV] Almost-K Increasing Subsequence - 17243 

[문제 링크](https://www.acmicpc.net/problem/17243) 

### 성능 요약

메모리: 3000 KB, 시간: 112 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 6월 24일 11:25:12

### 문제 설명

<p>수열 <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, ... , <em>a</em><sub>n</sub>이 주어진다. 이때, 우리는 이 수열에서 0개 이상의 수를 지워서 새로운 수열 <em>b</em><sub>1</sub>, <em>b</em><sub>2</sub>, ... , <em>b</em><sub>m</sub>을 만들 수 있다. 이때, 수열 <em>b</em><sub>1</sub>, <em>b</em><sub>2</sub>, ... , <em>b</em><sub>m</sub>을 수열 <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, ... , <em>a</em><sub>n</sub>의 Subsequence라고 부른다. 예를 들어, 수열 (1,2,4,5)의 Subsequence는 (1), (2, 5), (1, 2, 4, 5) 등이 있다.</p>

<p>우리는 수열 A = <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, ... , <em>a</em><sub>n</sub>와 <em>K</em>가 주어질때 수열 A의 Longest Almost-<em>K</em> Increasing Subsequence의 길이를 구하고 싶다. Longest Almost-<em>K</em> Increasing Subsequence란, Almost-<em>K</em> Increasing Subsequence중 가장 길이가 긴 수열을 의미하며, Almost-<em>K</em> Increasing Subsequence는 다음과 같이 정의된다.</p>

<ul>
	<li>수열 B = <em>b</em><sub>1</sub>, <em>b</em><sub>2</sub>, ... , <em>b</em><sub>m</sub>이 수열 A의 Subsequence라고 가정하자. 이때, 모든 <em>i</em> = 1, 2, ... , <em>m</em>−1에 대하여, <em>b</em><sub>i</sub> > <em>b</em><sub>i+1</sub>인 <em>i</em>의 개수가 <em>K</em>개 이하인 경우, 수열 B를 수열 A의 Almost-<em>K</em> Increasing Subsequence라고 정의한다.</li>
</ul>

### 입력 

 <p>첫 줄에 <em>n</em>, <em>K</em>(1 ≤ <em>n</em> ≤ 500, 0 ≤ <em>K</em> ≤ <em>n</em>)가 주어진다.</p>

<p>두 번째 줄에 정수 <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, ... , <em>a</em><sub>n</sub>(1 ≤ <em>a</em><sub>i</sub> ≤ 10<sup>9</sup>)이 주어진다.</p>

### 출력 

 <p>수열 A의 Longest Almost-<em>K</em> Increasing Subsequence의 길이를 출력하라.</p>

