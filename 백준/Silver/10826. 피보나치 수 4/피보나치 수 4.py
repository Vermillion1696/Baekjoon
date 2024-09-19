n = int(input())
F0, F1 = 0, 1
for _ in range(n):
    F0, F1 = F1, F0 + F1
print(F0)