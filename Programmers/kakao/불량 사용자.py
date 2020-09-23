from itertools import permutations


def solution(user_id, banned_id):
    answer2 = list()
    
    def doubleCheck(comued_ele, banned_ele):
        for i in range(len(banned_ele)):
            if banned_ele[i] == '*':
                continue
            if banned_ele[i] != comued_ele[i]:
                return False
        return True


    def check(comued, banned_id):
        for i in range(len(banned_id)):
            if len(comued[i]) != len(banned_id[i]):
                return False
            if doubleCheck(comued[i], banned_id[i]) is False:
                return False

        return True



    for comued in permutations(user_id, len(banned_id)):
        if check(comued, banned_id):
            comued = set(comued)
            if comued not in answer2:
                answer2.append(comued)

    answer = len(answer2)
    return answer
