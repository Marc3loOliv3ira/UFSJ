package fluxografo;

public class Grafo {

    private int matriz[][];
    private int numVertices;
    private int pos[];
    private int ValorPeso = 0;
    

    public static class Aresta {

        private int v1, v2, peso;

        public Aresta(int v1, int v2, int peso) {
            this.v1 = v1;
            this.v2 = v2;
            this.peso = peso;
        }

        public int peso() {
            return this.peso;
        }

        public int v1() {
            return this.v1;
        }

        public int v2() {
            return this.v2;
        }

    }

    public int getValorPeso() {
        return ValorPeso;
    }

    public void setValorPeso(int ValorPeso) {
        this.ValorPeso = ValorPeso;
    }
    
    public int[][] getMatriz() {
        return matriz;
    }

    public void setMatriz(int[][] matriz) {
        this.matriz = matriz;
    }

    public int getNumVertices() {
        return numVertices;
    }

    public void setNumVertices(int numVertices) {
        this.numVertices = numVertices;
    }

    public int[] getPos() {
        return pos;
    }

    public void setPos(int[] pos) {
        this.pos = pos;
    }

    public Grafo(int numVertices) {
        this.matriz = new int[numVertices][numVertices];
        this.setMatriz(matriz);
        this.pos = new int[numVertices];
        this.setPos(pos);
        this.numVertices = numVertices;
        this.setNumVertices(numVertices);
        for (int i = 0; i < this.numVertices; i++) {
            for (int j = 0; j < this.numVertices; j++) {
                this.pos[i] = -1;
            }
        }
    }

    public void insereAresta(int v1, int v2, int peso) {
        this.matriz[v1][v2] = peso;
        this.setMatriz(matriz);

    }

    public boolean existeAresta(int v1, int v2) {
        return (this.matriz[v1][v2] > 0);

    }

    public boolean listAdjVazia(int v) {
        for (int i = 0; i < this.getNumVertices(); i++) {
            if (this.matriz[v][i] > 0) {
                return false;
            }
        }
        return true;
    }

    public Aresta primeiroListaAdj(int v) {
        this.pos[v] = -1;
        return this.proxAdj(v);

    }

    public Aresta proxAdj(int v) {
        this.pos[v]++;
        while ((this.pos[v] < this.numVertices)
                && (this.matriz[v][this.pos[v]] == 0)) {
            this.pos[v]++;
        }
        if (this.pos[v] == this.numVertices) {
            return null;
        } else {
            return new Aresta(v, this.pos[v], this.matriz[v][this.pos[v]]);
        }

    }

    public Aresta retiraAresta(int v1, int v2) {
        if (this.matriz[v1][v2] == 0) {
            return null; // Aresta não existe
        } else {
            Aresta aresta = new Aresta(v1, v2, this.matriz[v1][v2]);
            this.setValorPeso(matriz[v1][v2]+ this.getValorPeso());
            this.matriz[v1][v2] = 0;
            return aresta;
        }
    }

    public int grauVerticeEntrada(int v) {
        int cont = 0;
        for (int i = 0; i < this.numVertices; i++) {
            if (existeAresta(i, v)) {
                cont++;
            }
        }

        return cont;
    }

    public int grauVerticeSaida(int v) {
        int cont = 0;
        for (int i = 0; i < this.numVertices; i++) {
            if (existeAresta(v, i)) {
                cont++;
            }
        }

        return cont;
    }
      
    public void imprime() {
        System.out.print(" ");
        for (int i = 0; i < this.numVertices; i++) {
            System.out.print((i+1) + " ");
        }
        System.out.println();
        for (int i = 0; i < this.numVertices; i++) {
            System.out.print((i +1)+ " ");
            for (int j = 0; j < this.numVertices; j++) {
                System.out.print(this.matriz[i][j] + " ");
            }
            System.out.println();
        }
    }

}
