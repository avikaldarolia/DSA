function MergeSort(arr) {
	if (arr.length < 2) {
		return arr;
	}

	return MergeSortHelper(arr, 0, arr.length - 1);
}

function MergeSortHelper(arr, low, high) {
	if (low === high) {
		return [arr[low]];
	}

	let mid = Math.floor(low + (high - low) / 2);
	let lh = MergeSortHelper(arr, low, mid);
	let rh = MergeSortHelper(arr, mid + 1, high);
	return merge(lh, rh);
}

function merge(a1, a2) {
	let i = 0,
		j = 0;

	let final = [];
	while (i < a1.length && j < a2.length) {
		if (a1[i] <= a2[j]) {
			final.push(a1[i]);
			i++;
		} else if (a1[i] > a2[j]) {
			final.push(a2[j]);
			j++;
		}
	}

	while (i < a1.length) {
		final.push(a1[i]);
		i++;
	}

	while (j < a2.length) {
		final.push(a2[j]);
		j++;
	}

	return final;
}

const arr = [8, 20, -2, 4, -6];

console.log(MergeSort(arr));
