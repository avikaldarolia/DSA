/**
Debouncing ensures that a function is only called once after a specified amount of time has passed since the last time it was invoked. It’s useful for scenarios where you want to wait for the user to stop performing an action before triggering the function. 
 */

function sendApiRequest(e) {
	console.log(e.target.value);
}

function debounce(fn, delay = 1000) {
	let timer;
	return function (...args) {
		if (timer) {
			clearTimeout(timer);
		}
		timer = setTimeout(() => fn(...args), delay);
	};
}
