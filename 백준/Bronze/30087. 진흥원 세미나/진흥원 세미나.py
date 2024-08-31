dict1={'Algorithm':204,
'DataAnalysis':	207,
'ArtificialIntelligence':302,
'CyberSecurity':'B101',
'Network':303,
'Startup':501,
'TestStrategy':105}
a=int(input())
for _ in range(a):
    b=input().rstrip()
    print(dict1[b])