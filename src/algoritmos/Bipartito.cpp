#include "algoritmos/Bipartito.h"
#include "algoritmos/BFS.h"

namespace algoritmos::bipartito {
    bool esBipartito(Grafo* G) {

    }
}

/* si G es conexo
0. Tomo un nodo cualquiera s
1. {L, T} = BFS(s)
2. Para cada capa L[i]
3.  Si i es par, pinto los nodos de L[i] de color A
4.  Si no, pinto los nodos de L[i] de color B
5. Para cada arista (u,v)
6.  Si color[u]==color[v]
7.      retorno false
8. Retorno true

si G no es conexo
0. Para cada componente conexa C
1.  Si bipartito(C) == false
2.      retorno false
3. Retorno true
*/