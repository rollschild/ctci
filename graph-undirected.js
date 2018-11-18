// Re-write the Grpah datastructure
// Undirected
let Graph = function() {
  this.vertices = {};
};

Graph.prototype.addNode = function(val) {
  if (this.vertices[val] !== undefined) {
    console.log(`Node of value ${val} already exists!`);
  } else {
    this.vertices[val] = [];
  }
  return;
};

Graph.prototype.addEdge = function(source, destination) {
  if (this.vertices[source] === undefined) {
    console.log(`Source node ${source} does NOT exist!`);
  } else if (this.vertices[destination] === undefined) {
    console.log(`Destination node ${destination} does NOT exist!`);
  } else if (this.vertices[source].indexOf(destination) !== -1) {
    console.log(`Edge ${source} -> ${destination} already exists!`);
  } else {
    this.vertices[source].push(destination);
    this.vertices[destination].push(source);
  }
  return;
};

Graph.prototype.findEdges = function(node) {
  if (this.vertices[node] === undefined) {
    console.log(`Node ${node} does NOT exist!`);
  } else {
    return this.vertices[node];
  }
};

Graph.prototype.hasNode = function(val) {
  return this.vertices[val] !== undefined;
};

Graph.prototype.hasEdge = function(source, destination) {
  return (
    this.vertices[source] !== undefined &&
    this.vertices[destination] !== undefined &&
    this.vertices[source].indexOf(destination) !== -1 &&
    this.vertices[destination].indexOf(source) !== -1
  );
};

Graph.prototype.removeEdge = function(source, destination) {
  if (!this.hasEdge(source, destination)) {
    console.log(`No edge ${source} -> ${destination} exists!`);
  } else {
    let pos = this.vertices[source].indexOf(destination);
    this.vertices[source].splice(pos, 1);
    pos = this.vertices[destination].indexOf(source);
    this.vertices[destination].splice(pos, 1);
  }
  return;
};

Graph.prototype.removeNode = function(node) {
  if (!this.hasNode(node)) {
    console.log(`No such node ${node}!`);
  } else {
    delete this.vertices[node];

    for (let vertex in this.vertices) {
      if (this.vertices[vertex].indexOf(node) !== -1) {
        let pos = this.vertices[vertex].indexOf(node);
        this.vertices[vertex].splice(pos, 1);
      }
    }
  }
  return;
};

module.exports = Graph;
