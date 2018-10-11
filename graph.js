let Graph = function() {
  this.vertices = {};
};

Graph.prototype.addEdge = function(node, edge) {
  if (this.vertices[node] === undefined) {
    return `node of value ${node} does NOT exist!`;
  } else if (this.vertices[node][edge]) {
    return `edge ${node} - ${edge} already exists you stupid fuck!`;
  } else {
    this.vertices[node][edge] = true;
  }
};

Graph.prototype.addNode = function(node) {
  if (this.vertices[node] !== undefined) {
    return `node of value ${node} already exists Jesus Christ!`;
  } else {
    this.vertices[node] = {};
  }
};

Graph.prototype.findEdges = function(node) {
  if (this.vertices[node] === undefined) {
    return `node of value ${node} does not exist oh my...`;
  } else {
    return this.vertices[node];
  }
};

Graph.prototype.hasEdge = function(node, edge) {
  if (this.vertices[node] === undefined) {
    return `node of value ${node} does NOT even exist!`;
  } else {
    return this.vertices[node][edge] !== undefined;
  }
};

Graph.prototype.hasNode = function(node) {
  return this.vertices[node] !== undefined;
}

Graph.prototype.removeNode = function(node) {
  if (this.vertices[node] === undefined) {
    return `this node ${node} does not exist come on...`;
  } else {
    delete this.vertices[node];
    for (let curr in this.vertices) {
      if (this.vertices[curr][node] !== undefined) {
        delete this.vertices[curr][node];
      }
    }
  }
};

Graph.prototype.removeEdge = function(node, edge) {
  if (this.vertices[node] === undefined) {
    return `node of value ${node} does not exist... yet`;
  } else {
    if (this.vertices[node][edge] == undefined) {
      return `edge ${node} - ${edge} does not exist`;
    } else {
      delete this.vertices[node][edge];
    }
  }
}

module.exports = Graph;
