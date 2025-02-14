// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
	private readonly vec: number[];
	private readonly hash: Map<number, number>;

	constructor() {
		this.vec = [];
		this.hash = new Map();
	}

	insert(val: number): boolean {
		if (this.hash.has(val)) {
			return false;
		}

		this.vec.push(val);
		this.hash.set(val, this.vec.length - 1);
		return true;
	}

	remove(val: number): boolean {
		if (!this.hash.has(val)) {
			return false;
		}

		const lastIndex = this.vec.length - 1;
		const idxToRemove = this.hash.get(val);

		if (!idxToRemove) {
			return false;
		}

		const lastValue = this.vec[lastIndex];

		this.vec[idxToRemove] = lastValue;
		this.hash.set(lastValue, idxToRemove);
		this.vec.pop();
		this.hash.delete(val);

		return true;
	}

	getRandom(): number {
		const indx = Math.floor(Math.random() * this.vec.length);
		return this.vec[indx];
	}
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
