package fluxografo;

import java.io.IOException;
import java.util.ArrayList;


public class CriaGrafo {

    public void criaGrafo(int v, int numVertices, int numArestas, ArrayList<Integer> v1, ArrayList<Integer> v2, ArrayList<Integer> peso) throws IOException {
        Grafo m = new Grafo(numVertices);
        int raiz = 0, antiraiz = 0;
        for (int i = 0; i < numArestas; i++) {
            m.insereAresta(v1.get(i), v2.get(i), peso.get(i));

        }
                for (int i = 1; i < numVertices; i++) {
            if (m.grauVerticeEntrada(i) == 0) {
                raiz = i;
            }
        }
        for (int i = 1; i < numVertices; i++) {
            if (m.grauVerticeSaida(i) == 0) {
               antiraiz = i;
            }
        }    
      
        FordFulkerson f = new FordFulkerson(numVertices, m.getMatriz(),v1,v2, raiz, antiraiz,numArestas);
        int fluxMax = f.fluxo();
        
        f.imprime();
        System.out.println("\n\n");
        System.out.println("O fluxo maximo encontrado foi : "+fluxMax+"\n");
    }
}
