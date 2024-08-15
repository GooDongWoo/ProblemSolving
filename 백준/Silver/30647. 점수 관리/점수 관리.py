import sys
n=int(sys.stdin.readline())
l1=[]
for _ in range(n):
    raw_datas=sys.stdin.readline().rstrip().rstrip(',').lstrip('[').rstrip(']').lstrip('{').rstrip('}').split(',')
    each_p=[]
    for raw_data in raw_datas:
        key,real=raw_data.split(':')
        key=key.strip('"')
        real=real.strip('"')
        each_p.append(real)
    l1.append(tuple(each_p))
l1.sort(key=lambda x:(x[0]))
l1.sort(key=lambda x:(int(x[1])),reverse=True)
score_list=sorted(([int(x[1]) for x in l1]),reverse=True)
for name,score,ishidden in l1:
    if(ishidden=='0'):
        sys.stdout.write(f'{score_list.index(int(score))+1} {name} {score}\n')