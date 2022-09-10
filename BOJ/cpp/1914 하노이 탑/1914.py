import sys
input = sys.stdin.readline

def inputs():
    return int(input())


def getDPtable(plateCount):
    table = []
    table.append(1)

    for i in range(2, plateCount):
        table.append(table[i-1] * 2 + 1)

    return table


def hanoiProcess(palteCount, start, end):

    if(plateCount == 1):
        print("{} {}".format(start, end))
    else:
        hanoiProcess(palteCount - 1, start, 6 - start - end)
        print("{} {}".format(start, end))
        hanoiProcess(palteCount - 1, 6 - start - end, end)

    return

if __name__ == "__main__":

    plateCount = inputs()
    dpTable = getDPtable(plateCount)

    print(dpTable[-1])

    if plateCount < 20:
        hanoiProcess(plateCount)

