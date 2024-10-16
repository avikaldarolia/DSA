function IsPowerOfTwo(n) {
	if (n < 1) {
		return false;
	}

	while (n > 1) {
		if (n % 2 != 0) {
			return false;
		}

		n = n / 2;
	}

	return true;
}

function IsPowerOfTwoBitWise(n) {
	if (n < 1) {
		return false;
	}

	return (n & (n - 1)) === 0;
}

console.log(IsPowerOfTwo(2));
console.log(IsPowerOfTwo(8));
console.log(IsPowerOfTwo(18));

console.log(IsPowerOfTwoBitWise(2));
console.log(IsPowerOfTwoBitWise(8));
console.log(IsPowerOfTwoBitWise(18));
