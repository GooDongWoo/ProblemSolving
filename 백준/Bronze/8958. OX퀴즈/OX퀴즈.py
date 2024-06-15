n_test=int(input())
for _ in range(n_test):
    test=list(input())
    score=0
    point=1
    for question in test:
        if (question=="O"):
            score+=point
            point+=1
        else:
            score+=0
            point=1
    print(score)