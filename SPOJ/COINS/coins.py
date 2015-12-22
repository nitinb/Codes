
store = {}

def func(n):
    global store
    key1 = n / 2
    key2 = n / 3
    key3 = n / 4

    if key1 + key2 + key3 > n:
         if key1 not in store:
             store[key1] = func(key1)
         if key2 not in store:
             store[key2] = func(key2)
         if key3 not in store:
             store[key3] = func(key3)

         return store[key1] + store[key2] + store[key3]

    return n

while True:
    try:
        n = input()
        print func(n)
    except Exception:
        break
