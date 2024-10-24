/**
 * Throttling ensures that a function is called at most once in a specified period. This is useful for events that can fire frequently, such as mouse movements. Below is a complete example that demonstrates it.
 */

function throttle(fn, delay = 1000) {
	let wait = false;
	return function (...args) {
		if (wait) {
			return;
		}
		fn(...args);
		wait = true;
		setTimeout(() => (wait = false), delay);
	};
}
