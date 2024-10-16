function InsertionSort(arr) {
	for (let i = 1; i < arr.length; i++) {
		let toInsert = arr[i];
		let j = i - 1;
		while (j >= 0 && toInsert < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = toInsert;
	}
}

const arr = [8, 20, -2, 4, -6];

InsertionSort(arr);
console.log(arr);
