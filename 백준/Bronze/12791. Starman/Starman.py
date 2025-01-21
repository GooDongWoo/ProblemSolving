import sys
input = sys.stdin.readline

d = {}
d[1967] = ["DavidBowie"]
d[1969] = ["SpaceOddity"]
d[1970] = ["TheManWhoSoldTheWorld"]
d[1971] = ["HunkyDory"]
d[1972] = ["TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"]
d[1973] = ["AladdinSane","PinUps"]
d[1974] = ["DiamondDogs"]
d[1975] = ["YoungAmericans"]
d[1976] = ["StationToStation"]
d[1977] = ["Low", "Heroes"]
d[1979] = ["Lodger"]
d[1980] = ["ScaryMonstersAndSuperCreeps"]
d[1983] = ["LetsDance"]
d[1984] = ["Tonight"]
d[1987] = ["NeverLetMeDown"]
d[1993] = ["BlackTieWhiteNoise"]
d[1995] = ["1.Outside"]
d[1997] = ["Earthling"]
d[1999] = ["Hours"]
d[2002] = ["Heathen"]
d[2003] = ["Reality"]
d[2013] = ["TheNextDay"]
d[2016] = ["BlackStar"]

q = int(input())
for _ in range(q):
    s, e = map(int, input().split())
    cands = []
    for i in range(s, e + 1):
        if i in d:
            for j in d[i]:
                cands.append((i, j))
    print(len(cands))
    for i in range(len(cands)):
        print(*cands[i])
        