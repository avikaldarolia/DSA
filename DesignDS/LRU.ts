// Using Js Map. Map maintains the order of insertion, so we can use it like a queue.
// Idea is to delete the key every time it is queried and add it again so it goes to the last.
// Then whenever we hit capacity, just remove the key from the top of the map because that key
// is for sure going to be the one that is LRU.
class LRUCache {
	private map = new Map<number, number>();
	constructor(private capacity: number) {}

	get(key: number): number {
		const value = this.map.get(key);
		if (value === undefined) {
			return -1;
		}

		this.map.delete(key);
		this.map.set(key, value);
		return value;
	}

	put(key: number, value: number): void {
		if (this.map.has(key)) {
			this.map.delete(key);
		}

		this.map.set(key, value);

		if (this.map.size > this.capacity) {
			const lruKey = this.map.keys().next().value;
			this.map.delete(lruKey);
		}
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
