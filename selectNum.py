# -*- coding: utf-8  -*-

Count = 0
def combination(data, t, vl):
    _kk = len(data)
    for _i in range(_kk-t+1):
        vl.append(data[_i])
        new_data = data[_i+1:]
        if t-1 == 1:
            for _j in range(len(new_data)):
                print ','.join(map(str,vl))+','+str(new_data[_j])
                global Count
                Count += 1
        else:
            combination(new_data, t-1, vl)
        vl.pop()

if __name__ == '__main__':
    n = 10 # 总数
    t = 6  # 选取个数
    vl = [] # 用于存放选中的数字
    data = range(1, n+1)#[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    combination(data, t, vl)
    _count_correct = reduce(lambda x, y: x*y,range(n,n-t,-1)) / reduce(lambda x, y: x*y,range(t,0,-1))
    print Count, Count == _count_correct
