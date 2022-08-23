def solution(year):
    cen = int((year / 100))
    if (cen % 10 == 0):
        return cen
    else:
        return cen + 1
