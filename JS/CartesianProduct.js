const a = [1, 2];
const b = [3, 4, 5];

function CartesianProduct(a, b) {
	// return a.forEach((el) => {
	// 	return b.forEach((el2) => [el, el2]);
	// });

	let final = [];
	a.forEach((el) => {
		for (let i = 0; i < b.length; i++) {
			final.push([el, b[i]]);
		}
		// return [...newEl];
	});

	return final;
}

console.log(CartesianProduct(a, b));
