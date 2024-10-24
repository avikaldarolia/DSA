/**
 * An IIFE (Immediately Invoked Function Expression) is a JavaScript function that runs as soon as it is defined.
 */

(function () {
	var lol = "I am LOL 😂😂😂";
	console.log(lol); // "I am local"
})();

/**
 * It is a design pattern which is also known as a Self-Executing Anonymous Function and contains two major parts:
1. The first is the anonymous function with lexical scope enclosed within the Grouping Operator (). This prevents accessing variables within the IIFE idiom as well as polluting the global scope.
2. The second part creates the immediately invoked function expression () through which the JavaScript engine will directly interpret the function.
 
*/

/**
Uses:
1. Avoid polluting the global namespace
2. An async IIFE allows you to use await and for-await even in older browsers and JavaScript runtimes that have no top-level await:
3. Also used to create private and public variables and methods.

*/
