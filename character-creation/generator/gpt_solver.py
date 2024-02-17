class SegmentTree:
    def __init__(self, n):
        self.tree = [0] * (4 * n)
    
    def update(self, idx, start, end, target_idx, value):
        if start == end:
            if start == target_idx:
                self.tree[idx] = value
            return
        
        mid = (start + end) // 2
        if target_idx <= mid:
            self.update(2 * idx + 1, start, mid, target_idx, value)
        else:
            self.update(2 * idx + 2, mid + 1, end, target_idx, value)
        
        self.tree[idx] = max(self.tree[2 * idx + 1], self.tree[2 * idx + 2])
    
    def query(self, idx, start, end, left, right):
        if start > right or end < left:
            return 0
        if start >= left and end <= right:
            return self.tree[idx]
        
        mid = (start + end) // 2
        left_max = self.query(2 * idx + 1, start, mid, left, right)
        right_max = self.query(2 * idx + 2, mid + 1, end, left, right)
        
        return max(left_max, right_max)


def find_best_combination(N, A, D, P, enemies):
    # Initialize segment tree
    st = SegmentTree(D)
    
    # Build segment tree
    for d in range(1, D + 1):
        st.update(0, 1, D, d, A + d)
    
    # Initialize best combination
    best_attack = A
    best_defense = D
    
    # Iterate through enemies
    for enemy_attack, enemy_defense in enemies:
        max_attack_to_defeat_enemy = st.query(0, 1, D, enemy_defense + 1, D)
        remaining_points = P - (max_attack_to_defeat_enemy - enemy_attack)
        
        if remaining_points >= 0 and max_attack_to_defeat_enemy > best_attack:
            best_attack = max_attack_to_defeat_enemy
            best_defense = enemy_defense
    
    return best_attack, best_defense


# Input
N, A, D, P = map(int, input().split())
enemies = [tuple(map(int, input().split())) for _ in range(N)]

# Find and print the best combination
best_attack, best_defense = find_best_combination(N, A, D, P, enemies)
print(best_attack, best_defense)
