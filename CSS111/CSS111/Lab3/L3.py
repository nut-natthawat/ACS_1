text = input().split()
want = input()
change = input()
hhhh = []
for char in text :
    if char == want:
        hhhh.append(change)
    elif want in char :
        hhhh.append(change.join(char.split(want)))
    else :
        hhhh.append(char)
print(*hhhh)
