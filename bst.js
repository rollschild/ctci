// Binary Search Tree
let Queue = require('./queue-rewritten.js');
let BST = function(val) {
  this.value = val;
  this.left = null;
  this.right = null;
};

BST.prototype.insertRecursion = function(val) {
  if (this.value === undefined) {
    this.value = val;
    return;
  }

  if (val < this.value) {
    if (this.left === null) {
      let node = new BST(val);
      this.left = node;
    } else {
      this.left.insertRecursion(val);
    }
  } else if (val > this.value) {
    if (this.right === null) {
      let node = new BST(val);
      this.right = node;
    } else {
      this.right.insertRecursion(val);
    }
  } else {
    return `Node already exists!`;
  }

  return;
};

BST.prototype.printLevelOrder = function() {
  if (this === null) {
    return `Empty BST..`;
  }
  let nodes = [];
  let que = new Queue();
  que.add(this);
  console.log("entering while loop...");
  while (!que.isEmpty()) {
    let node = que.pop();
    nodes.push(node.value);
    if (node.left) {
      que.add(node.left);
    }
    if (node.right) {
      que.add(node.right);
    }
  }

  console.log(nodes);
  return;
};

// TEST

let bst = new BST();
bst.insertRecursion(4);
bst.insertRecursion(2);
bst.insertRecursion(6);
bst.insertRecursion(1);
bst.insertRecursion(3);
bst.insertRecursion(5);
bst.insertRecursion(7);
console.log(bst);
bst.printLevelOrder();
