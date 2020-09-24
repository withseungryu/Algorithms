import sys
sys.setrecursionlimit(100000)
def solution(k, room_number):
    answer = []
    dic = dict()

    def find(dic, x):
        if x in dic:
            dic[x] = find(dic, dic[x])

        else:
            dic[x]= x
        return dic[x]

    for i in room_number:
        if i not in dic.keys():
            dic[i] = i+1
            answer.append(i)
        else:
            tmp = find(dic,i)
            dic[tmp]  = tmp+1
            answer.append(tmp)

    return answer
