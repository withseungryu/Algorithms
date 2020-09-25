def solution(a):
    answer = 0
    arr = list()
    tmp = sorted(a)

    min_num = tmp[0]
    min_idx = 0
    for i in range(len(a)):
        if min_num == a[i]:
            min_idx = i
            break

    left_min = a[0]
    for i in range(min_idx):
        if left_min >= a[i]:
            left_min = a[i]
            answer+=1


    right_min = a[len(a)-1]

    for i in range(len(a)-min_idx-1):
        j = len(a)-1-i
        if right_min >= a[j]:
            right_min = a[j]
            answer+=1

    answer+=1

    return answer
