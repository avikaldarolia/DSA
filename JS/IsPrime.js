function isPrime(n) {
	if (n < 2) {
		return false;
	}

	for (let i = 2; i <= parseInt(Math.sqrt(n)); i++) {
		if (n % i === 0) {
			return false;
		}
	}
	return true;
}

function GeneratePrimeSieve(n) {
	let primes = [],
		upperLimit = parseInt(Math.sqrt(n)),
		array = Array(n).fill(true);

	for (let i = 2; i <= upperLimit; i++) {
		if (array[i]) {
			for (let j = i * i; j < n; j += i) {
				array[j] = false;
			}
		}
	}

	for (let i = 2; i < n; i++) {
		if (array[i]) {
			primes.push(i);
		}
	}

	return primes;
}

console.log(GeneratePrimeSieve(20));

// console.log(parseInt(Math.sqrt(17)));

// console.log(isPrime(2));
// console.log(isPrime(4));
// console.log(isPrime(16));
// console.log(isPrime(17));
// console.log(isPrime(19));
// console.log(isPrime(20));
