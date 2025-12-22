# [Gold II] As the Crow Flies - 4561 

[문제 링크](https://www.acmicpc.net/problem/4561) 

### 성능 요약

메모리: 2172 KB, 시간: 0 ms

### 분류

수학, 그래프 이론, 기하학, 트리, 3차원 기하학

### 제출 일자

2025년 12월 22일 22:50:39

### 문제 설명

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/aed79a83-aefe-450a-bdef-01d9a44aacd7/-/preview/"></p>

<p>As president of a startup airline company, you have started a frequent flier program that rewards customers for every mile they travel. As a for-profit company, you have a vested interest in minimizing the number of frequent flier miles that a person can earn on any one trip. To get an idea of how many miles a customer could earn flying the existing network, you've decided to write a program.</p>

<p>Assumptions:</p>

<ul>
	<li>A passenger's itinerary is one-way (no return flight).</li>
	<li>Every itinerary takes the shortest route from the departing city to the destination city.</li>
	<li>Frequent flier miles are counted "as the crow flies" (i.e., the shortest route across the earth's surface that connects the cities along the route).</li>
	<li>The earth's surface is a perfect sphere with radius 4000 miles.</li>
</ul>

### 입력 

 <p>The first line contains a single integer <i>n</i> indicating the number of data sets. Each data set will be formatted according to the following description:</p>

<p>A single data set has 3 components:</p>

<ol>
	<li><i>Header Line</i> - A single line, "<i><tt>X Y</tt></i>", where <i>X</i> is the number of cities and <i>Y</i> is the number of flight legs in the airline's network. Both will be positive integers less than 100.</li>
	<li><i>City List</i> - A list of cities and their locations, one city per line. The line will be of the format
	<p>"<i><tt>C LA NS LO EW</tt></i>" where:</p>

	<ul>
		<li><i><tt>C</tt></i> is the name of the city (no spaces, alphabetical, first letter only upper case)</li>
		<li><i><tt>LA</tt></i> is the degrees of latitude where the city is located (from 0 to 90)</li>
		<li><i><tt>NS</tt></i> is the direction of latitude ('N'orth or 'S'outh of the equator)</li>
		<li><i><tt>LO</tt></i> is the degrees of longitude where the city is located (from 0 to 180)</li>
		<li><i><tt>EW</tt></i> is the direction of longitude ('E'ast or 'W'est of the prime meridian)</li>
	</ul>
	</li>
	<li><i>Flight List</i> - A list of city pairs of the format "<i><tt>B C</tt></i>" representing different cities that are directly connected by flight legs, one pair per line. Note that "<i><tt>B C</tt></i>" is equivalent to "<i><tt>C B</tt></i>".</li>
</ol>

<p>Note:</p>

<ul>
	<li>Some longitude measurements can be represented in multiple ways (i.e., 180E = 180W)</li>
	<li>All degrees of latitude and longitude given in the input will be integers.</li>
	<li>The airline's network is connected (i.e., there is at least one route between any two cities).</li>
</ul>

### 출력 

 <p>For each data set, output the two cities that are farthest from each other (farthest in the sense that the shortest route between them is the longest of any city pair). You are guaranteed that there will be no ties. Display the city names on the same line, separated by a single space, sorted in dictionary order.</p>

