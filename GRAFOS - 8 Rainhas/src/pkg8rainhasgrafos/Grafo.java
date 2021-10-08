package pkg8rainhasgrafos;

public class Grafo {

    private int linha;
    private int coluna;
    public String[][] matriz;
    public String[][] grafoResposta;

    public Grafo() {
        this.linha = 8;
        this.coluna = 8;
        this.matriz = new String[getLinha()][getColuna()];
        this.grafoResposta = new String[getLinha()][getColuna()];
    }

    public void criaGrafo() { //Essa funçao cria um grafo(Nosso tabuleiro) por meio de uma matriz adjacencia
        for (int i = 0; i < getLinha(); i++) {
            for (int j = 0; j < getColuna(); j++) {
                this.matriz[i][j] = "[ ]";//[ ] representa onde nao ha Rainhas
                if(i == j){
                this.matriz[i][j] = "[R]"; //[R] representa onde ha rainhas no grafo
                
                
                }
            }
        }
        grafoResp();
    }
    public void grafoResp() { //esta funçao cria um cria um grafo onde serao alocadas as respostas
        for (int i = 0; i < getLinha(); i++) {
            for (int j = 0; j < getColuna(); j++) {
                this.grafoResposta[i][j] = "[ ]";
                
            }
        }
    }

    public void imprimeGrafo() { //imprimo o grafo respostas
        for (int i = 0; i < getLinha(); i++) {
            for (int j = 0; j < getColuna(); j++) {
                System.out.print("" + this.grafoResposta[i][j]);

            }
            System.out.println("");
        }
        grafoResp(); //reseto o meu grafo resposta para que possa ser incluida outra resposta nele
    }

   
    

    public int getLinha() {
        return linha;
    }

    public void setLinha(int linha) {
        this.linha = linha;
    }

    public int getColuna() {
        return coluna;
    }

    public void setColuna(int coluna) {
        this.coluna = coluna;
    }

}
