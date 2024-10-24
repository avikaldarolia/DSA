/**
 * Currying is transforming a function that takes multiple arguments into a sequence of functions, each taking a single argument.
 */

function add(a, b) {
	return a + b;
}

console.log(add(2, 3)); // 5

function curriedAdd(a) {
	return function (b) {
		return a + b;
	};
}

console.log(curriedAdd(2)(3)); // 5

// Infinite currying
/**
 * Infinite currying refers to a technique where a function continues to return new functions until a certain condition is met, often when no arguments are passed, at which point it performs a final operation using all accumulated arguments.
 */

function sum(a) {
	return function (b) {
		if (b !== undefined) {
			return sum(a + b);
		} else {
			return a;
		}
	};
}

console.log(sum(1)()); // 1
console.log(sum(1)(9)()); // 10
console.log(sum(5)(10)(-3)(2)()); // 14
