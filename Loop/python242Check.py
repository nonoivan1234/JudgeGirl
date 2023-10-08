l = []
for i in range(3):
    l.append(list(map(int, input().split())))

# xMin = min(l[i][0] - l[i][2] for i in range(3))
# xMax = max(l[i][0] + l[i][2] for i in range(3))
# yMin = min(l[i][1] - l[i][2] for i in range(3))
# yMax = max(l[i][1] + l[i][2] for i in range(3))
xMin = -200
xMax = 200
yMin = -200
yMax = 200

def inter(x, y, X, Y, R):
    return (x - X) ** 2 + (y - Y) ** 2 <= R ** 2

cnt = 0
for x in range(xMin, xMax + 1):
    for y in range(yMin, yMax + 1):
        interscet = 0
        for i in range(3):
            interscet += inter(x, y, l[i][0], l[i][1], l[i][2])
        
        if(interscet % 2 == 1):
            cnt += 1
            
# print(xMin, xMax, yMin, yMax)
print(cnt)