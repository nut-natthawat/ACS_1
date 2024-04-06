q = int(input())
for k in range(2, q) :
    if (q % k) == 0 :
        print(q,'=',k,'x',q//k)
        break
else :
    print(q,'is prime number')