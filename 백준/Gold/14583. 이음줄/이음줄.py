h,v=map(float,input().split())

t=(h**2 +v**2)**(0.5)

a=v*(h/(h+t))
b=v*(t/(h+t))
m=(a**2 +h**2)**(0.5)

n=b*h/m

print(f'{round(m/2,2)} {round(n,2)}')