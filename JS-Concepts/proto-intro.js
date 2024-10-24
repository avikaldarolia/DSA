// Inheritance and the prototype chain

/*
JavaScript implements inheritance by using objects. Each object has an internal link to another object called its prototype. That prototype object has a prototype of its own, and so on until an object is reached with null as its prototype. By definition, null has no prototype and acts as the final link in this prototype chain.
 */

// obj.[[Prototype]] = Object.getPrototypeOf(obj)
/*
It should not be confused with the func.prototype property of functions, which instead specifies the [[Prototype]] to be assigned to all instances of objects created by the given function when used as a constructor.
 */

/** Object Literal **/
const rohit = {
	girlfriend: "smita",
};

const vikas = {
	friend: "sakshi",
};

vikas.__proto__ = rohit; // we can do this bze __proto__ has get and set for __proto__ property
Object.setPrototypeOf(vikas, rohit); // newer way

console.log(vikas.friend);
console.log(vikas.girlfriend);
console.log(vikas); // gets rohit in __proto__ object

// NOTE: No circular dependencies are allowed. Uncaught TypeError: Cyclic __proto__ value
vikas.__proto__ = rohit;
rohit.__proto__ = vikas;

/** 2. Object with Getter and Setter **/
const men = {
	status: "single",
	crush: "xyz",
	set setCrush(name) {
		this.crush = name;
	},
};

const you = {};
Object.setPrototypeOf(you, men);
console.log(you.crush); // xyz
you.setCrush = "abcdef";
console.log(you.crush); // abcdef

// Get keys of an object
console.log(Object.keys(you)); // ["crush"]

// for...in loop includes inherited props
for (let key in you) console.log(key); // crush, status, setCrush
