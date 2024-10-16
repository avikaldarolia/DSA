function BinarySearch(arr, tar) {
	let low = 0,
		high = arr.length - 1;

	while (low <= high) {
		let mid = low + Math.floor((high - low) / 2);
		if (arr[mid] === tar) {
			return mid;
		} else if (arr[mid] > tar) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}

let arr = [1, 2, 3, 4, 6, 7, 8, 9, 11, 13];

function BinarySearchRecursive(arr, tar) {
	return search(arr, tar, 0, arr.length - 1);
}

function search(arr, target, low, high) {
	if (low > high) {
		return -1;
	}

	let mid = low + Math.floor((high - low) / 2);
	if (arr[mid] === target) {
		return mid;
	} else if (arr[mid] > target) {
		return search(arr, target, low, mid - 1);
	} else {
		return search(arr, target, mid + 1, high);
	}
}

// console.log(BinarySearch(arr, 3));
// console.log(BinarySearch(arr, 5));
// console.log(BinarySearch(arr, 10));
// console.log(BinarySearch(arr, 13));

console.log(BinarySearchRecursive(arr, 3));
console.log(BinarySearchRecursive(arr, 5));
console.log(BinarySearchRecursive(arr, 10));
console.log(BinarySearchRecursive(arr, 13));
