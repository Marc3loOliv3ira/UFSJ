package fluxografo;

public class BuscaEmProfundidade {

    public static final byte branco = 0;//variavel para colorir vertice de branco
    public static byte cinza = 1;       //colorir de cinza
    public static byte preto = 2;       //colorir de preto
    private int d[], t[], antecessor[];// tempo de descoberto,tempo para examinar a lista de adjacentes e o antecessor
    private int raiz;
    private int antiraiz;
    private Grafo grafo;                
//todos os vertices sao inicializados de branco
    public BuscaEmProfundidade(Grafo grafo,int r,int ar) {
        this.grafo = grafo;
        int n = this.grafo.getNumVertices();
        d = new int[n];
        t = new int[n];
        antecessor = new int[n];
        this.raiz = r;
        this. antiraiz = ar;
    }

    private int visitaDfs(int u, int tempo, int cor[]) {
        cor[u] = cinza;                 //Visita o vertice a primeira vez e pinta de cinza
        this.d[u] = ++tempo;
        if (!this.grafo.listAdjVazia(u)) {
            Grafo.Aresta a = this.grafo.primeiroListaAdj(u);
            while (a != null) {
                int v = a.v2();
                if (cor[v] == branco) { //se o vertice estiver branco visita ele
                    this.antecessor[v] = u;
                    tempo = this.visitaDfs(v, tempo, cor);
                }
                a = this.grafo.proxAdj(u);
            }
        }
        cor[u] = preto;                 //quando a lista de adjacentes foi completamente analizada pinta de preto
        this.t[u] = ++tempo;
        return tempo;
       
    }
    public void buscaEmProfundidade() {
        int tempo = 0;
        int cor[] = new int[this.grafo.getNumVertices()];
        for (int u = 0; u < grafo.getNumVertices(); u++) {
            cor[u] = branco;
            this.antecessor[u] = -1;
        }
        
                tempo = this.visitaDfs(this.getRaiz(), tempo, cor);
                if(achouCam(cor)){
                   System.out.println("Nao é corte");
                }
                else{
                    System.out.println("É um corte");
                    System.out.println("Capacidade do corte : " + grafo.getValorPeso());
                }
         
    }
    public boolean achouCam(int cor[]){
        if(cor[this.getAntiraiz()]== preto){
        return true;
        
        }
    return false;
    
    
    
    }

    public int d(int v) {
        return this.d[v];
    }

    public int t(int v) {
        return this.t[v];
    }

    public int antecessor(int v) {
        return this.antecessor[v];
    }

    public int getRaiz() {
        return raiz;
    }

    public void setRaiz(int raiz) {
        this.raiz = raiz;
    }

    public int getAntiraiz() {
        return antiraiz;
    }

    public void setAntiraiz(int antiraiz) {
        this.antiraiz = antiraiz;
    }

}
