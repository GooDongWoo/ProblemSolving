while 1:
    n=int(input())
    if n==0:break
    tmp='PREMIADO' if n%42==0 else 'TENTE NOVAMENTE'
    print(tmp)
        