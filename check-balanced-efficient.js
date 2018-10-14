let treeNode = function(val) {
  this.value = val;
  this.left = null;
  this.right = null;
};

// Number.MIN_SAFE_INTEGER

let checkHeight = function(node) {
  if (node === null) {
    return -1;
  }
  console.log(node.value);
  let heightLeft = checkHeight(node.left);
  if (heightLeft === Number.MIN_SAFE_INTEGER) {
    console.log(`Error alert! ${node.value}'s left subtree`);
    return Number.MIN_SAFE_INTEGER;
  }
  console.log(`height of ${node.value}'s left subtree is ${heightLeft}`);
  let heightRight = checkHeight(node.right);
  if (heightRight === Number.MIN_SAFE_INTEGER) {
    console.log(`Error aleart! ${node.value}'s right subtree`);
    return Number.MIN_SAFE_INTEGER;
  }
  console.log(`height of ${node.value}'s right subtree is ${heightRight}`);
  let diff = heightLeft - heightRight;

  if (Math.abs(diff) > 1) {
    return Number.MIN_SAFE_INTEGER;
  } else {
    return Math.max(heightLeft, heightRight) + 1;
  }
};

let checkBalanced = function(node) {
  return checkHeight(node) !== Number.MIN_SAFE_INTEGER;
};

let root = new treeNode(2);                                                      
                                                                                 
root.left = new treeNode(4);                                                     
root.right = new treeNode(1);                                                    
root.left.left = new treeNode(6);                                                
root.left.right = new treeNode(5);                                               
root.right.right = new treeNode(3);                                              
root.right.left = new treeNode(7);                                        
// root.right.right.right.right = new treeNode(-1);                                  
console.log(checkBalanced(root));
