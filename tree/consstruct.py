def trail(idx):
    if idx>=10:
        return idx
    idx+=1
    print(idx)
    return trail(idx)

idx=0
print(trail(idx))