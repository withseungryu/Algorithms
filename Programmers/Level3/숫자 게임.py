from collections import deque
def solution(A, B):
    answer = 0

    A.sort()
    B.sort()
    q=deque()

    for i in range(len(B)):
        q.append(B[i])



    idx = 0
    cnt = 0
    while q:
        if A[idx] < q[0]:
            cnt+=1
            idx += 1
            q.popleft()
        else:
            q.popleft()

    answer =cnt

    return answer
