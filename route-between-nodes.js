let Graph = require('./graph.js');
let Queue = require('./queue.js');

function checkRoute(graph, source, destination) {
  if (!graph.hasNode(source) || !graph.hasNode(destination)) {
    return false;
  }
  /*
  let edgesSour = graph.findEdges(source);
  let edgesDest = graph.findEdges(destination);

  if (Object.keys(edgesSour).length === 0 
      || Object.keys(edgesDest).length === 0) {
    return false;
  }
  */
  queSour = new Queue();
  queDest = new Queue();

  visitedSour = {}
  visitedDest = {};

  // visitedSour[source] = true;
  // visitedDest[source] = true;

  queSour.push(source);
  queDest.push(destination);

  while (!queSour.isEmpty() || !queDest.isEmpty()) {
    if (!queSour.isEmpty()) {
      let node = queSour.pop();
      if (node === destination) {
        return true;
      } else {
        if (visitedSour[node] === undefined) {
          visitedSour[node] = true;
          if (graph.hasNode(node)) {
            for (let child in graph.findEdges(node)) {
              queSour.push(child);
            }
          }
        }
      }
    }

    if (!queDest.isEmpty()) {
      let node = queDest.pop();
      if (node === source) {
        return true;
      } else {
        if (visitedDest[node] === undefined) {
          visitedDest[node] = true;
          if (graph.hasNode(node)) {
            for (let child in graph.findEdges(node)) {
              queDest.push(child);
            }
          }
        }
      }
    }
  }

  return false;
}

let graph = new Graph();
graph.addNode('A');
graph.addNode('B');
graph.addNode('C');
graph.addNode('D');
graph.addNode('E');

graph.addEdge('A', 'B');
graph.addEdge('A', 'C');
graph.addEdge('B', 'C');
graph.addEdge('D', 'E');


console.log(checkRoute(graph, 'A', 'C'), true);
console.log(checkRoute(graph, 'A', 'E'), false);
console.log(checkRoute(graph, 'B', 'A'), true);
console.log(checkRoute(graph, 'D', 'E'), true);
