def topological_sort_dfs(num_nodes, edges):
    # Build adjacency list
    graph = {i: [] for i in range(num_nodes)}
    for src, dest in edges:
        graph[src].append(dest)
        
    visited = [False] * num_nodes
    stack = []

    def dfs(node):
        visited[node] = True
        
        # Explore all neighbors
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)
                
        # Push node to stack ONLY after all neighbors are explored
        stack.append(node)

    # Check all nodes to handle disconnected graphs
    for i in range(num_nodes):
        if not visited[i]:
            dfs(i)

    # Reverse the stack to get the topological order
    return stack[::-1]

# Example Usage
edges = [(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)]
print("Topological Order:", topological_sort_dfs(6, edges))
