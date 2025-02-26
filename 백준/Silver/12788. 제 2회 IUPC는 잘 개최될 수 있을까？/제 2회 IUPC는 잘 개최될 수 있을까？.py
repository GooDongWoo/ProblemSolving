n = int(input());
m,a = map(int,input().split());
need = m*a;
l = sorted(list(map(int,input().split())),reverse = True);
cur = 0;
idx = 0;
while (cur<need and idx<n):
    cur += l[idx];
    idx += 1;
if(idx>=n and cur<need):
    print("STRESS\n");
else:
    print(idx);