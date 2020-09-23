def solution(stones, k):
    answer=0
    max_pe = 0
    for stone in stones:
        max_pe = max(max_pe, stone)

    left = 1
    right = 200000000

    while left <= right:
        mid = (left+right)//2
        tmp = list()
        for i in range(len(stones)):
            if stones[i]-mid >=0:
                tmp.append(stones[i]-mid)
            else:
                tmp.append(0)
        cnt=0
        max_cnt=0
        for i in range(len(tmp)):
            if tmp[i] == 0:
                cnt+=1
                max_cnt = max(max_cnt, cnt)
            else:
                cnt =0

        if max_cnt >= k:
            right = mid-1
        elif max_cnt < k:
            left = mid+1
     
        
    answer =left
    return answer
