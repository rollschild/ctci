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

BST.prototype.insertLoop = function(val) {
  if (this.value === undefined) {
    this.value = val;
  } else {
    // let left = true;
    let parent = this;
    let child = this;
    while (child !== null) {
      if (val < child.value) {
        parent = child;
        child = child.left;
      } else if (val > child.value) {
        parent = child;
        child = child.right;
      } else {
        return `Node already exists!`;
      }
    }

    let node = new BST(val);
    if (val < parent.value) {
      parent.left = node;
    } else {
      parent.right = node;
    }
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
  console.log('entering while loop...');
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
/*
bst.insertRecursion(4);
bst.insertRecursion(2);
bst.insertRecursion(6);
bst.insertRecursion(1);
bst.insertRecursion(3);
bst.insertRecursion(5);
bst.insertRecursion(7);
*/
bst.insertLoop(4);
bst.insertLoop(2);
bst.insertLoop(6);
bst.insertLoop(1);
bst.insertLoop(3);
bst.insertLoop(5);
bst.insertLoop(7);
console.log(bst);
bst.printLevelOrder();
