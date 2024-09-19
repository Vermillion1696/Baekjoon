# [Diamond II] 파리채 만들기 - 17441 

[문제 링크](https://www.acmicpc.net/problem/17441) 

### 성능 요약

메모리: 3588 KB, 시간: 92 ms

### 분류

미적분학, 기하학, 그린 정리, 수학

### 제출 일자

2024년 9월 19일 18:46:31

### 문제 설명

<p>실버는 다각형 모양의 방에서 SNUPC 문제를 만들고 있었다. 문제 아이디어가 생각이 안 나서 문득 고개를 위로 들었는데, 그 순간 천장에 모기 두 마리가 붙어있는 걸 발견했다! 모기한테 당한 게 많은 실버는 모기와의 사투를 벌였지만, 끝내 잡지 못했다. 그런데 다음 날에도, 또 그다음 날에도 모기 두 마리가 천장에 붙어 있는 것이 아닌가? 실버는 이 모기 두 마리를 잡기 위해 맞춤형 DIY 파리채를 만들기로 했다.</p>

<p>파리채는 원형이며, 모기를 잡기에 완벽한 특수 소재로 이루어져 있어 살짝 닿기만 해도 모기를 바로 죽일 수 있다. 또한, 이 특수 소재는 잘 접히기 때문에 모기가 모서리나 꼭짓점에 있더라도 아무 문제 없이 모기를 잡을 수 있다. 하지만 한 번 천장에 파리채를 휘두르면, 파리채에 맞지 않은 모기는 도망가버리기 때문에, 두 모기를 한 방에 죽일 수 있도록 파리채의 지름은 최소 두 모기 사이의 거리만큼은 되어야 한다. 파리채를 만드는 특수 소재의 단가는 단위 넓이당 <span style="display: inline-block; position: relative; vertical-align: middle; letter-spacing: 0.001em; text-align: center;"><span style="display: block; padding: 0.1em;">4</span><span style="display: none; padding: 0.1em;">/</span><span style="display: block; padding: 0.1em; border-top: thin solid black;"><span style="font-style: italic;">π</span></span></span>이다. 즉, 두 모기 사이의 거리 <span style="font-style: italic;">d</span>에 대해 파리채를 만들기 위해 드는 비용은 <span style="font-style: italic;">d</span><sup>2</sup>이다.</p>

<p>파리채를 만들고 모기를 잡을 생각에 기분이 좋아진 실버는 문제를 만들었다! <strong>모기 두 마리가 천장의 임의의 위치에 있을 때, 파리채를 만들기 위해 드는 비용의 기댓값은 얼마일까?</strong> 단, 각 모기는 다각형(천장) 내의 임의의 점에 균일한 확률로 존재한다. 다시 말해, 다각형 <span style="font-style: italic;">D</span> 내의 임의의 "넓이를 가지는 영역" <span style="font-style: italic;">S</span>에 대해, 모기가 영역 <span style="font-style: italic;">S</span> 안에 위치할 확률은 |<span style="font-style: italic;">S</span>|/|<span style="font-style: italic;">D</span>|(여기서 |<span style="font-style: italic;">A</span>|는 도형 <span style="font-style: italic;">A</span>의 넓이)이다. 또한, 두 모기의 위치는 독립적으로 정해진다.</p>

### 입력 

 <p>첫 번째 줄에 다각형의 꼭짓점의 수 <span style="font-style: italic;">N</span>이 주어진다. (3 ≤ <span style="font-style: italic;">N</span> ≤ 100,000)</p>

<p>다음 <span style="font-style: italic;">N</span>개의 줄에 걸쳐 한 줄에 하나씩 다각형의 꼭짓점의 <span style="font-style: italic;">x</span>좌표와 <span style="font-style: italic;">y</span>좌표가 공백을 사이에 두고 주어진다. (-10,000 ≤ <span style="font-style: italic;">x</span>, <span style="font-style: italic;">y</span> ≤ 10,000)</p>

<p>다각형의 꼭짓점은 반시계 방향으로 주어지며, 주어진 다각형은 단순다각형임이 보장된다. 즉, 다각형의 모든 선분들은 연속하는 두 선분의 교점을 제외하고는 교차하지 않는다.</p>

### 출력 

 <p>첫 번째 줄에, 파리채를 만들기 위해 드는 비용의 기댓값을 출력한다. 답과 10<sup>-6</sup> 이하의 절대 또는 상대오차가 있을 경우 정답으로 인정한다.</p>

