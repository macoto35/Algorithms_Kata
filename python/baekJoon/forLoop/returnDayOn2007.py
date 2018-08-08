mon, day = map(int, input().split()); endDayByMonth = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
for i in range(mon): day += endDayByMonth[i]
print(days[day % 7])

# import datetime; mon, day = map(int, input().split()); print(datetime.date(2007, mon, day).strftime('%a').upper())
# m, d = map(int, input().split()); print('FSSMTWTRAUOUEHITNNEDU'[(d - 5389465494 // 7**m) % 7::7])
