

def calculate_modulo(base, exponent, modulo):
    result = 1
    while exponent != 0:
        if exponent % 2 == 1:
            result *= base % modulo
        exponent /= 2
        base *= base % modulo
    return result % modulo


print calculate_modulo(2004, 2005, 10)
print calculate_modulo(17, calculate_modulo(17, 17, 100), 100)

result = 0
for i in range(1, 2002):
    result += calculate_modulo(i, i, 10)

print result % 10
