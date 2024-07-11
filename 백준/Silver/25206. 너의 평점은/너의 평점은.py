dict1=dict([('A+',4.5),('A0',4.0),('B+',3.5),('B0',3.0),('C+',2.5),('C0',2.0),('D+',1.5),('D0',1.0),('F',0.0)])
g_s=0
a_s=0
for _ in range(20):
    name,amount,grade=input().split()
    if(grade=='P'):
        continue
    a_s+=float(amount)
    g_s+=dict1[grade]*float(amount)
print(g_s/a_s)