import sys

def solve():
    try:
        n = int(sys.stdin.readline())
        s = sys.stdin.readline().strip()
    except (IOError, ValueError):
        return

    old_grades = []
    i = 0
    while i < len(s):
        if i + 1 < len(s) and s[i+1] in ('+', '0', '-'):
            old_grades.append(s[i:i+2])
            i += 2
        else:
            if s[i] == 'A':
                old_grades.append('A0')
            elif s[i] == 'B':
                old_grades.append('B0')
            elif s[i] == 'C':
                old_grades.append('C0')
            i += 1

    new_grades_list = []
    for i in range(len(old_grades)):
        current_grade = old_grades[i]
        previous_grade = old_grades[i-1] if i > 0 else None
        
        new_grade = ''

        if current_grade in ('C+', 'C0', 'C-'):
            new_grade = 'B'
        
        elif current_grade in ('B0', 'B-'):
            if i == 0 or previous_grade in ('C+', 'C0', 'C-'):
                new_grade = 'D'
            else:
                new_grade = 'B'
        
        elif current_grade in ('A-', 'B+'):
            if i == 0 or previous_grade in ('B0', 'B-', 'C+', 'C0', 'C-'):
                new_grade = 'P'
            else:
                new_grade = 'D'

        elif current_grade == 'A0':
            if i == 0 or previous_grade in ('A-', 'B+', 'B0', 'B-', 'C+', 'C0', 'C-'):
                new_grade = 'E'
            else:
                new_grade = 'P'
        
        elif current_grade == 'A+':
            new_grade = 'E'
        
        new_grades_list.append(new_grade)

    print("".join(new_grades_list))


solve()