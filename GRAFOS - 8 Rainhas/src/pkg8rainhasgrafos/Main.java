package pkg8rainhasgrafos;

public class Main {

    public static void main(String[] args) {
        Grafo g = new Grafo();
        SolutionQueen s = new SolutionQueen();
        g.criaGrafo(); 
         s.Solucoes8Rainhas(g);
       
    }

}
