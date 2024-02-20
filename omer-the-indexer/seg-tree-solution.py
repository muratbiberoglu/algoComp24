from collections import defaultdict
import sys

max_value = 1000001

def lchild(i: int):
    return 2 * i + 1

def rchild(i: int):
    return 2 * i + 2

class OSTree:
    def __init__(self) -> None:
        self.__st = [0 for _ in range(4 * max_value)]
        self.__n = max_value

    def update(self, index: int, value: int) -> None:
        self.__update(0, 0, self.__n - 1, index, value)

    def get_by_order(self, order: int) -> int:
        return self.__get_by_order(0, 0, self.__n - 1, order)

    def __update(self, si: int, sl: int, sr: int, i: int, value: int) -> None:
        if i < sl or sr < i or sr < sl:
            return
        if sl == sr:
            self.__st[si] = value
            return
        mid = (sl + sr) // 2
        self.__update(lchild(si), sl, mid, i, value)
        self.__update(rchild(si), mid + 1, sr, i, value)
        self.__st[si] = self.__st[lchild(si)] + self.__st[rchild(si)]

    def __get_by_order(self, si: int, sl: int, sr: int, order: int) -> int:
        if sl == sr:
            return sl
        mid = (sl + sr) // 2
        if order <= self.__st[lchild(si)]:
            return self.__get_by_order(lchild(si), sl, mid, order)
        else:
            return self.__get_by_order(rchild(si), mid + 1, sr, order - self.__st[lchild(si)])

if __name__ == "__main__":
    n, p, q = map(int, sys.stdin.readline().strip().split())

    videos = []
    for _ in range(n):
        videos.append(list(map(int, sys.stdin.readline().strip().split())))

    ostrees = [OSTree() for _ in range(p)]
    maps = [defaultdict(int) for _ in range(p)]
    # Build OS-Trees
    for i in range(n):
        for j in range(p):
            ostrees[j].update(videos[i][j], 1)
            maps[j][videos[i][j]] = i

    while q:
        q -= 1
        query = list(map(int, sys.stdin.readline().strip().split()))
        query[1] -= 1
        query[3] -= 1

        value = ostrees[query[1]].get_by_order(query[2])
        ind = maps[query[1]][value]

        if query[0] == 1:
            ostrees[query[3]].update(videos[ind][query[3]], 0)
            maps[query[3]].pop(videos[ind][query[3]])
            videos[ind][query[3]] += query[4]
            ostrees[query[3]].update(videos[ind][query[3]], 1)
            maps[query[3]][videos[ind][query[3]]] = ind
        else:
            print(videos[ind][query[3]])
