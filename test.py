print('Test AnyPower')
from AnyPower import AnyPower

assert(AnyPower(2) == 'NO')
assert(AnyPower(3) == 'NO')
assert(AnyPower(4) == 'YES')
assert(AnyPower(27) == 'YES')
assert(AnyPower(28) == 'NO')
assert(AnyPower(1024) == 'YES')
assert(AnyPower(15625) == 'YES')
assert(AnyPower(17210368) == 'YES')
assert(AnyPower(17210369) == 'NO')
print('AnyPower test OK')

exit()
