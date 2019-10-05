# Find if a number is a power (> 1) of some natural number n > 1.

from collections import Counter

def Erat(n):
	# Returns list of prime numbers from 1 to n.
	if n <= 1:
		raise ValueError

	prime = list(map(lambda x: True, range(1 + n)))

	prime[0] = False
	prime[1] = False
	for i in range(2, n + 1):
		if prime[i]:
			if i * i <= n:
				for j in range(i * i, n + 1, i):
					prime[j] = False

	ans = list()
	for k, v in enumerate(prime):
		if v:
			ans.append(k)
	return ans

def PrimeDiv(n):
	# Returns prime dividers of a natural number n > 1.
	if n <= 1:
		raise ValueError

	primes = Erat(n)
	prime_mult = list()
	while n > 1:
		for v in primes:
			if n % v == 0:
				prime_mult.append(v)
				n = n // v
	return prime_mult

def AnyPower(n, GetPowerForm=False):
	# Returns 'YES' if it is a power of some number, 'NO' instead.
	# If GetPowerForm set true, returns powered form (string).
	if n <= 1:
		raise ValueError

	prime_mult = PrimeDiv(n)

	prime_count = dict(Counter(prime_mult))

	min_count = min(prime_count.values())

	if min_count <= 1:
		return 'NO'

	for k, v in prime_count.items():
		if v % min_count > 0:
			return 'NO'

	if GetPowerForm:
		original_number = 1
		for k, v in prime_count.items():
			original_number *= k ** (v // min_count)

		return f'{original_number}^{min_count}'
	else:
		return 'YES'
