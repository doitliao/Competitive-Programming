import sys

def x(n):
  cnt = 0
  while n > 0:
    cnt = cnt + 1;
    n = n / 10
  return cnt

f1 = 1
f2 = 1
f3 = f1 + f2
i = 3
while True:
  f3 = f1 + f2
  f1 = f2
  f2 = f3
  if x(f3) == 1000:
    print i,x(f3), f3
    sys.exit(0)
  i = i + 1
