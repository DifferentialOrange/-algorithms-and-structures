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
assert(AnyPower(2, GetPowerForm=True) == 'NO')
assert(AnyPower(27, GetPowerForm=True) == '3^3')
assert(AnyPower(17210368, GetPowerForm=True) == '28^5')
print('AnyPower test OK')

exit()
