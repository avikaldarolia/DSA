let n = 5;

function fib(n) {
	// let ans = ARra
	if (n <= 0) {
		return [];
	}

	if (n === 1 || n === 2) {
		return 1;
	}

	let f = 1,
		s = 1;
	let fibs = Array(2).fill(1);
	for (let i = 2; i < n; i++) {
		let third = f + s;
		f = s;
		s = third;
		fibs.push(s);
	}

	return fibs;
}

function FibRecursive(n) {
	if (n == 1 || n == 2) {
		return 1;
	}

	return FibRecursive(n - 1) + FibRecursive(n - 2);
}
console.log(fib(6));
console.log(FibRecursive(5));
