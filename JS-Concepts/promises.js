// Promise

/**
A Promise is a proxy for a value not necessarily known when the promise is created. It allows you to associate handlers with an asynchronous action's eventual success value or failure reason. This lets asynchronous methods return values like synchronous methods: instead of immediately returning the final value, the asynchronous method returns a promise to supply the value at some point in the future.

A Promise is in one of these states:

pending: initial state, neither fulfilled nor rejected.
fulfilled: meaning that the operation was completed successfully.
rejected: meaning that the operation failed.
 */

/**
 * 
1. Promise.all()
- Takes an array of promises
- Resolves when all of the promises in the array have resolved.
- Rejects if any of the promises reject.

2. Promise.any()
- Takes an array of promises
- Resolves as soon as any of the promises resolve.
- It rejects only if all the promises reject.
- This can be useful for getting the fastest successful response from multiple sources.


3. Promise.allSettled()
- Takes an array of promises
- Returns a promise that resolves after all of the given promises have either resolved or rejected. It returns an array of objects describing the outcome of each promise.

4.Promise.race()
- Takes an array of promises
- Resolves or rejects as soon as one of the promises resolves or rejects.
- Promise.race() will resolve as soon as either the main API or the backup API returns a response. This can be useful for redundancy and improving reliability.

*/
