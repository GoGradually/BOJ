# [Gold I] Diamond Collector (Silver) - 12003 

[문제 링크](https://www.acmicpc.net/problem/12003) 

### 성능 요약

메모리: 4796 KB, 시간: 24 ms

### 분류

이분 탐색, 누적 합, 두 포인터

### 문제 설명

<p>Bessie the cow, always a fan of shiny objects, has taken up a hobby of mining diamonds in her spare time! She has collected \(N\) diamonds (\(N \leq 50,000\)) of varying sizes, and she wants to arrange some of them in a pair of display cases in the barn.</p>

<p>Since Bessie wants the diamonds in each of the two cases to be relatively similar in size, she decides that she will not include two diamonds in the same case if their sizes differ by more than \(K\) (two diamonds can be displayed together in the same case if their sizes differ by exactly \(K\)). Given \(K\), please help Bessie determine the maximum number of diamonds she can display in both cases together.</p>

### 입력 

 <p>The first line of the input file contains \(N\) and \(K\) (\(0 \leq K \leq 1,000,000,000\)). The next \(N\) lines each contain an integer giving the size of one of the diamonds. All sizes will be positive and will not exceed \(1,000,000,000\).</p>

### 출력 

 <p>Output a single positive integer, telling the maximum number of diamonds that Bessie can showcase in total in both the cases.</p>

