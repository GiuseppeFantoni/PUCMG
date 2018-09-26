import networkx as nx

def main():
  str = input("")

  n, m = str.split(" ") #m = numero juncoes byteland e n = numero de estradas em byteland

  n = int(n) # numero total de empresas cliente 
  m = int(m) # par de parceiro de negocios

  while (n!= 0 and m!= 0):

    g = nx.Graph()

    for i in range(0,n):

      leitura = input()
      
      x, y, z = leitura.split(" ")  

      x = int(x)
      y = int(y)
      z = int(z)
      g.add_edge(x,y, weight = z) #criando grafo com x,y e z metros

      distanciaT =+ z
      
      
      T= nx.minimum_spanning_tree(g)

      new_graph = nx.difference(g,T)
      g.add_edge
      
    
    
