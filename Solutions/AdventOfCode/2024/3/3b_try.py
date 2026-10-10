import re

f = open("in1", "r")
lines = f.readlines()
f.close()

regex = r"mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\)"

doit = True
sum = 0

for line in lines:
    ls = re.findall(regex, line)

    for items in ls:
        if items == "don't()":
            doit = False
        elif items == "do()":
            doit = True
        else:
            if doit:
                num = items[4:-1]
                nums = num.split(',')
                sum += int(nums[0]) * int(nums[1])
    
print(sum)
