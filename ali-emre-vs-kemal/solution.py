import heapq

BISHOP = 0
ROOK = 1

n = 0
tr = 0
tc = 0

knight_directions = [(2, 1), (1, 2), (-2, 1), (1, -2), (2, -1), (-1, 2), (-2, -1), (-1, -2)]
bishop_directions = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
rook_directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def in_grid(r, c):
    return 0 <= r < n and 0 <= c < n


def print_grid(grid):
    for row in grid:
        print(','.join(map(lambda x: str(-1 if x == float('inf') else x), row)))


def fill(grid, pieces, directions, is_knight=False):
    pq = []
    for r, c in pieces:
        grid[r][c] = 0
        heapq.heappush(pq, (0, r, c))

    while pq:
        cur_dist, r, c = heapq.heappop(pq)

        if cur_dist > grid[r][c]:
            continue

        for dr, dc in directions:
            i = 1
            while True:
                if i == 2 and is_knight:
                    break
                new_r = r + dr * i
                new_c = c + dc * i
                if not in_grid(new_r, new_c):
                    break
                if grid[new_r][new_c] == -1:
                    break
                i += 1
                new_dist = cur_dist + 1
                if new_dist < grid[new_r][new_c]:
                    grid[new_r][new_c] = new_dist
                    heapq.heappush(pq, (new_dist, new_r, new_c))


def solve():
    global n, tr, tc
    n, tr, tc = map(int, input().strip().split())
    tr -= 1
    tc -= 1

    grid = [[float('inf')] * n for _ in range(n)]
    rooks = []
    bishops = []
    kr, kc = 0, 0
    for r in range(n):
        s = input()
        for c in range(n):
            ch = s[c]
            if ch == 'P':
                grid[r][c] = -1
            elif ch == 'R':
                rooks.append((r, c))
            elif ch == 'B':
                bishops.append((r, c))
            elif ch == 'K':
                kr, kc = r, c

    grid_bishops = [row[:] for row in grid]
    grid_rooks = [row[:] for row in grid]

    fill(grid_bishops, bishops, bishop_directions)
    fill(grid_rooks, rooks, rook_directions)

    # merge solutions
    for r in range(n):
        for c in range(n):
            if grid[r][c] == -1:
                continue
            if grid_bishops[r][c] != -1:
                grid[r][c] = min(grid[r][c], grid_bishops[r][c])
            if grid_rooks[r][c] != -1:
                grid[r][c] = min(grid[r][c], grid_rooks[r][c])

    old = grid[tr][tc]

    # move knight
    knights = [(kr, kc)]
    fill(grid, knights, knight_directions, True)

    print("YES" if grid[tr][tc] < old else "NO")


def main():
    global n
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
