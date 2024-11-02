# [Gold IV] Look Up - 6105 

[문제 링크](https://www.acmicpc.net/problem/6105) 

### 성능 요약

메모리: 2940 KB, 시간: 52 ms

### 분류

자료 구조, 스택

### 제출 일자

2024년 11월 2일 15:28:43

### 문제 설명

<p>Farmer John's N (1 <= N <= 100,000) cows, conveniently numbered 1..N, are once again standing in a row. Cow i has height H_i (1 <= H_i <= 1,000,000).</p>

<p>Each cow is looking to her left toward those with higher index numbers. We say that cow i 'looks up' to cow j if i < j and H_i < H_j. For each cow i, FJ would like to know the index of the first cow in line looked up to by cow i.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains the single integer: H_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..N: Line i contains a single integer representing the smallest index of a cow up to which cow i looks. If no such cow exists, print 0.</li>
</ul>

<p> </p>

