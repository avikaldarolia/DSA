function test() {
	console.log(this.name);
}

var name = "zoya";

test(); // "zoya"    ---> Default binding

// BUT,

function test2() {
	console.log(this.name2);
}

var name2 = "zoya";
var aditya = {
	name2: "geet",
	test2: test2,
};

test2(); // "zoya"    ---> Default binding
aditya.test2(); //"geet" ---> Implicit binding
