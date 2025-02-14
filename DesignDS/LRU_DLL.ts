class Node {
	constructor(
		public val: number = 0,
		public next: Node | null = null,
		public prev: Node | null = null
	) {}
}

class LRUCache {
	public head: Node | null = null;
	public tail: Node | null = null;
	public map = new Map<number, [number, Node]>();

	constructor(private capacity: number) {}

	private addFront(val: number | Node): Node {
		let newNode: Node = val instanceof Node ? val : new Node(val);
		newNode.next = newNode.prev = null;
		if (!this.head) {
			this.head = this.tail = newNode;
		} else {
			newNode.next = this.head;
			this.head.prev = newNode;
			this.head = newNode;
		}

		return newNode;
	}

	private removeNode(node: Node): void {
		if (node.prev) {
			node.prev.next = node.next;
		}
		if (node.next) {
			node.next.prev = node.prev;
		}
		if (this.head === node) {
			this.head = node.next;
		}
		if (this.tail === node) {
			this.tail = node.prev;
		}

		node.next = node.prev = null;
	}

	private makeRecentlyUsed(node: Node) {
		if (this.head === node) {
			return;
		}

		this.removeNode(node);
		this.addFront(node);
	}

	get(key: number): number {
		const pair = this.map.get(key);
		if (!pair) {
			return -1;
		}

		this.makeRecentlyUsed(pair[1]);
		return pair[0];
	}

	put(key: number, value: number): void {
		const pair = this.map.get(key);
		if (pair) {
			pair[0] = value;

			this.makeRecentlyUsed(pair[1]);
		} else {
			const newNode = new Node(key);
			this.addFront(newNode);
			this.map.set(key, [value, newNode]);

			if (this.map.size > this.capacity && this.tail) {
				this.evict();
			}
		}
	}

	private evict(): void {
		const keyNode = this.tail;
		this.removeNode(keyNode);
		this.map.delete(keyNode.val);
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
