vocab = input()
Sala = 'aeiou'
group_count = 0
result = 0
for char in vocab :
    if char in Sala :
        group_count += 1
    else :
        if group_count > 0 :
            result += 1 
            group_count = 0
if group_count > 0 :
    result += 1
print(result)