import math
p = int(input())
result = 3
t = 1
for i in range(1,p+1) :
    result += (t*4)/((2*i)*(2*i+1)*(2*i+2))
    t = t*-1
print('{:.15f}'.format(math.pi - result))