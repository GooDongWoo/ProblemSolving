total_loss = 0
while True:
    bet = int(input())
    if bet == -1:  # 게임 종료 조건
        break
    total_loss += bet

print(total_loss)