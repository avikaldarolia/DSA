/**
 * MAP:
- A Map is a built-in JavaScript object that allows you to store key-value pairs and they have a search time complexity of O(1)
- Unlike plain objects, where keys can only be strings or symbols, a Map can use any value as a key, including objects, functions, and primitive values.
 */

// Plain  Object example. can only have string/symbol as key.
const subscribe = () => {};
const obj = {
	name: "hackthecode",
	action: subscribe(),
};

// Using Map
const myMap = new Map();

const key1 = {}; // object
const key2 = function () {}; // function
const key3 = "a string"; // string

myMap.set(key1, "value1");
myMap.set(key2, "value2");
myMap.set(key3, "value3");

console.log(myMap.get(key1)); // "value1"
console.log(myMap.get(key2)); // "value2"
console.log(myMap.get(key3)); // "value3"

console.log(myMap.size); // 3

myMap.forEach((value, key) => {
	console.log(`${key}: ${value}`);
});
