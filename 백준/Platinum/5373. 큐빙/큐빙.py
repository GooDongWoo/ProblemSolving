import sys

input = sys.stdin.readline

def solve():
    t = int(input())
    
    for _ in range(t):
        cube = {
            'U': [['w']*3 for _ in range(3)],
            'D': [['y']*3 for _ in range(3)],
            'F': [['r']*3 for _ in range(3)],
            'B': [['o']*3 for _ in range(3)],
            'L': [['g']*3 for _ in range(3)],
            'R': [['b']*3 for _ in range(3)]
        }
        
        n = int(input())
        commands = input().split()
        
        for cmd in commands:
            face = cmd[0]
            direction = cmd[1]
            
            count = 1 if direction == '+' else 3
            
            for _ in range(count):
                rotate_clock(cube, face)
        
        for i in range(3):
            print("".join(cube['U'][i]))

def rotate_clock(cube, face):
    old_face = [row[:] for row in cube[face]]
    for r in range(3):
        for c in range(3):
            cube[face][c][2-r] = old_face[r][c]
            
    u, d, f, b, l, r = cube['U'], cube['D'], cube['F'], cube['B'], cube['L'], cube['R']
    
    if face == 'U':
        temp = list(f[0])
        f[0] = list(r[0])
        r[0] = list(b[0])
        b[0] = list(l[0])
        l[0] = temp
        
    elif face == 'D':
        temp = list(f[2])
        f[2] = list(l[2])
        l[2] = list(b[2])
        b[2] = list(r[2])
        r[2] = temp
        
    elif face == 'F':
        
        temp = list(u[2])
        
        for i in range(3): u[2][i] = l[2-i][2]
        
        for i in range(3): l[i][2] = d[0][i]
        
        for i in range(3): d[0][i] = r[2-i][0]
        
        for i in range(3): r[i][0] = temp[i]
        
    elif face == 'B':
        
        temp = list(u[0])
        
        for i in range(3): u[0][i] = r[i][2]
        
        for i in range(3): r[i][2] = d[2][2-i]
        
        for i in range(3): d[2][i] = l[i][0]
        
        for i in range(3): l[i][0] = temp[2-i]
        
    elif face == 'L':
        
        temp = [u[i][0] for i in range(3)]
        
        for i in range(3): u[i][0] = b[2-i][2]
        
        for i in range(3): b[i][2] = d[2-i][0]
        
        for i in range(3): d[i][0] = f[i][0]
        
        for i in range(3): f[i][0] = temp[i]
        
    elif face == 'R':
        
        temp = [u[i][2] for i in range(3)]
        
        for i in range(3): u[i][2] = f[i][2]
        
        for i in range(3): f[i][2] = d[i][2]
        
        for i in range(3): d[i][2] = b[2-i][0]
        
        for i in range(3): b[i][0] = temp[2-i]

if __name__ == "__main__":
    solve()