#!/usr/bin/python
# coding: utf-8

import random
answer = random.randint(0, 100)
print "游戏开始"
number = int(raw_input("请输入0-100的数字:"))
count = int(raw_input("请输入要猜的次数:"))
flag = 0
while count > 0:
    if number == answer:
        print "哇偶，恭喜猜对啦"
        flag = 1
        break
    elif number > answer:
        print "您输入的数字太大啦"
        number = int(raw_input("请输入0-100的数字:"))
        count -= 1
    elif number < answer:
        print "您输入的数字太小啦"
        number = int(raw_input("请输入0-100的数字:"))
        count -= 1

if count == 0 and flag == 0:
    print "很遗憾，您没有猜对"


