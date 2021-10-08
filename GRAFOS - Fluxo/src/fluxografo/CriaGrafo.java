package fluxografo;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class CriaGrafo {

    public void criaGrafo(int v, int numVertices, int numArestas, ArrayList<Integer> v1, ArrayList<Integer> v2, ArrayList<Integer> peso) throws IOException {
       Scanner entrada = new Scanner(System.in);
        Grafo m = new Grafo(numVertices);
        int[] vetor = new int[1];
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
        int op =1;
      while(op == 1){
          System.out.println("Informe os vertices da Aresta");
          System.out.println("1º Vertice");
          int arest1 = entrada.nextInt()-1;
          System.out.println("2º Vertice");
          int arest2 = entrada.nextInt()-1;
          m.retiraAresta(arest1, arest2);
          m.imprime();
          System.out.println("Deseja remover mais alguma? 1 - Sim,0 - Nao");
          op = entrada.nextInt();
          
      }     
        BuscaEmProfundidade bsf = new BuscaEmProfundidade(m, raiz, antiraiz);
        bsf.buscaEmProfundidade();
        
       
       

    }
}
