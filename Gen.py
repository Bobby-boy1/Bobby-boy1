import random
#to set number of nodes and edges in the graph
Node_val = 4
Vertex_val = 6
m=[]
for i in range(Node_val):
    row = []
    for j in range(Node_val):
        row.append(0)
    m.append(row)
print(m)
edges = {}
while len(edges) < Vertex_val:
    x = random.randint (1, Node_val)
    y = random.randint (1, Node_val)
    if x == y: continue
    if y < x: x, y = y, x
    w = random.randint(1,15)
    edges [x, y] = w

for (x, y), w in edges.items ():
    m[x-1][y-1] = w
    m[y-1][x-1] = w
    #printing individual weight from one node to the other
    print ('Edge from {} to {} with weight {}.'.format (x, y, w) )
#printing the resulting data in matrix form
print("{",end="")
for row in m:
    print("{",end="")
    for val in row:
        print(val,end=",")
    print("}")
print("}")