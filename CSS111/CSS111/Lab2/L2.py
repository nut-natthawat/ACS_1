sum_ = 0
sum_2 = 0
while True:
        input_ = int(input())
        if input_ > 0 :
            sum_ += input_
        if input_ < 0 :
             sum_2 += input_
        if input_ == 0 :
            break     
print(sum_,sum_2)