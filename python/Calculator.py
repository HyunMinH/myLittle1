class Calculator:
    sumof = 0
    cnt = 0

    def __init__(self, list):
        self.list = list

    def sum(self):
        for i in self.list:
            self.sumof += i
            self.cnt += 1
        return self.sumof

    def avg(self):
        if not self.cnt:
            print("sum부터 해주세요.")
            return
        return self.sumof / self.cnt


if __name__ == "__main__":
    cal = Calculator([1, 2, 3, 4, 5])
    print(cal.sum())
    print(cal.avg())

    cal2 = Calculator([6, 7, 8, 9, 10])
    print(cal2.sum())
    print(cal2.avg())