package fluxografo;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class FordFulkerson {

    private int numVertices;
    private int numArestas;
    private int matCp[][];
    private  int z=1;
    private ArrayList<Integer> v1;
    private ArrayList<Integer> v2;
    private Queue<Integer> fila;
    private boolean visitados[];
    private int caminho[];
    private int raiz;
    private int antiraiz;

    public FordFulkerson(int numVertices, int[][] matCp,ArrayList<Integer> v1,ArrayList<Integer> v2, int raiz, int antiraiz,int numArestas) {
        this.numVertices = numVertices;
        this.matCp = matCp;
        this.fila = new LinkedList<Integer>();
        this.visitados = new boolean[this.numVertices];
        this.caminho = new int[this.numVertices];
        this.raiz = raiz;
        this.antiraiz = antiraiz;
        this.v1 = v1;
        this.v2 = v2;
        this.numArestas = numArestas;
    }

    public int fluxo() {
        int fluxoMaximo = 0;
          while (caminho())
        {
            int fluxoM = Integer.MAX_VALUE; 
            
            int i;
            //percorre o caminho e salva a aresta de menoir capacidade para definir o valor do fluxo
            for (int v = this.antiraiz; v != this.raiz; v = this.caminho[v])
            {
                i = this.caminho[v];
                if(this.matCp[i][v] < fluxoM){
                	fluxoM = this.matCp[i][v];
                    
                       
                }
                 
                
            }
            
            //atualiza os valores do Grafo copia
            System.out.println(this.z+"º"+"Passo: ");
            this.z++;
            for (int v = this.antiraiz; v != this.raiz; v = caminho[v])
            {
                i = caminho[v];
                matCp[i][v] -= fluxoM;
                System.out.println("matriz"+ "["+(i+1)+ "]" +" -> " + "["+(v+1)+ "]"+"="+matCp[i][v]);
                matCp[v][i] += fluxoM;
              System.out.println("matriz"+ "["+(v+1)+ "]" +" <- " + "["+(i+1)+ "]"+"="+matCp[v][i]);
            }
             System.out.println("#########################");
            fluxoMaximo += fluxoM;	
        }
        
		return fluxoMaximo;

        
    }
    //faz uma busca no grafo
    public boolean caminho() {
        boolean exCaminho = false;
        //redefine as variaveis
        for (int v = 0; v < this.numVertices; v++) {
            caminho[v] = -1;
            visitados[v] = false;

        }
        fila.add(this.raiz);//adiciona o vertice inicial na fila
        visitados[raiz] = true;
        while(!fila.isEmpty()){
        int vertice  = fila.remove();
            for (int i = 0; i <this.numVertices; i++) {
                // se existir um ligacao entre os vertices , a capacidade for maior que zero e ainda nao foi visitado
           if(this.matCp[vertice][i]>0 && !this.visitados[i]){
            this.caminho[i] = vertice;//adiciono o vertice no vetor que guarda o caminho
            fila.add(i);//adiciona o vertice no final da fila
            this.visitados[i] = true;//marca ele como visitado           
            }            
            }     
        }
        if(this.visitados[this.antiraiz]){//verifica se um caminho ate o destino foi formado
        exCaminho =  true;
        }

        return exCaminho;
    }
       
    public void imprime() {
        System.out.println("\n___________________________________________________________________________");
      for(int i = 0;i<this.numArestas;i++){
          System.out.println("Fluxo Elementar "+"["+(v1.get(i)+1)+"]"+"["+(v2.get(i)+1)+"]"+":"+this.matCp[v2.get(i)][v1.get(i)]); 
      }
    } 
}
