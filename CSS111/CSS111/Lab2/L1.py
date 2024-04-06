Hr_in = int(input())
Mi_in = int(input())
Hr_out = int(input())
Mi_out = int(input())
totalminin = (Hr_in * 60) + Mi_in
totalminout = (Hr_out * 60) + Mi_out
sum = totalminout - totalminin
if sum <= 15 :
    print('0')
elif 15 < sum <= 180 :
    fee3hr = sum//60 * 20
    if sum % 60 != 0 :
        fee3hr += 20
    print(fee3hr)
elif 180 < sum <= 480 :
    fee4hr = (((sum - 180)//60)*40)+60
    if sum % 60 != 0 :
        fee4hr += 40
    print(fee4hr)
elif sum > 480 :
    print('400')