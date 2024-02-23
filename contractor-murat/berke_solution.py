import sys

N = 105  # Adjusted to include the required range, might be different from C++ code

seg = [[0] * (4 * N) for _ in range(4 * N)]


def upd2(c1, c2, l2, r2, ty, v):
    if not (l2 <= ty <= r2):
        return
    if l2 == r2:
        seg[c1][c2] = max(seg[c1][c2], v)
        return
    mid = (l2 + r2) // 2
    upd2(c1, 2 * c2, l2, mid, ty, v)
    upd2(c1, 2 * c2 + 1, mid + 1, r2, ty, v)
    seg[c1][c2] = max(seg[c1][2 * c2], seg[c1][2 * c2 + 1])


def upd(c1, l1, r1, tx, ty, v):
    if not (l1 <= tx <= r1):
        return
    upd2(c1, 1, 0, N - 1, ty, v)
    if l1 == r1:
        return
    mid = (l1 + r1) // 2
    upd(2 * c1, l1, mid, tx, ty, v)
    upd(2 * c1 + 1, mid + 1, r1, tx, ty, v)


def get(c1, c2, l2, r2, y1, y2):
    if l2 > y2 or r2 < y1:
        return 0
    if y1 <= l2 and r2 <= y2:
        return seg[c1][c2]
    mid = (l2 + r2) // 2
    return max(get(c1, 2 * c2, l2, mid, y1, y2), get(c1, 2 * c2 + 1, mid + 1, r2, y1, y2))

def get2(c1, l1, r1, c2, l2, r2, x1, y1, x2, y2):
    if l1 > x2 or r1 < x1:
        return 0
    if x1 <= l1 and r1 <= x2:
        return get(c1, c2, l2, r2, y1, y2)
    mid = (l1 + r1) // 2
    return max(get2(2 * c1, l1, mid, c2, l2, r2, x1, y1, x2, y2),
               get2(2 * c1 + 1, mid + 1, r1, c2, l2, r2, x1, y1, x2, y2))



def solve():
    n, q = map(int, sys.stdin.readline().split())
    pre = [[0] * N for _ in range(N)]
    for i in range(n):
        row = list(map(int, sys.stdin.readline().split()))
        for j in range(n):
            x = row[j]
            upd(1, 0, N - 1, i, j, x)
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + x

    for _ in range(q):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        x1, y1, x2, y2 = x1 - 1, y1 - 1, x2 - 1, y2 - 1
        mx = get2(1, 0, N - 1, 1, 0, N - 1, x1, y1, x2, y2)
        area = (x2 - x1 + 1) * (y2 - y1 + 1)
        sum_val = pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] + pre[x1][y1]
        print(area * mx - sum_val)


if __name__ == "__main__":
    solve()
