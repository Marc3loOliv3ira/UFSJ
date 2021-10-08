package pkg8rainhasgrafos;

public class SolutionQueen {

    public int contaSolutions = 0;
    void Solucoes8Rainhas(Grafo grafo ) {
        int[] linhas = new int[8]; //crio um vetor que vai receber a posição(linha que se encontram) das minhas Rainhas que estao no grafo
        int i,j;
         for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
           if("[R]".equals(grafo.matriz[i][j])){
               linhas[i] = i;
           
           }
        }
        }
        testaPermutacoes(grafo, linhas, 0);//Chamo a funçao para testar as permutacoes, passando o grafo, o vetor contendo a posicao, e a coluna inicial (0)
    }

    public void testaPermutacoes(Grafo grafos, int linhas[], int coluna) { //nessa função fixamos um elemento,e tentamos as permutacoes com todos os outros indices, se der certo
        // adiciono a solucao no meu grafo :) se nao :( passo para outro elemento;
        // esse processo sera repetido ate fixar todos os elementos ate chegar na posicao coluna
        int i;

        if (coluna == 8) { //verifico se ja chegou na oitava coluna 
            if (solucaoValida(linhas)) {//verifico se a soluçao foi valida
                addSolution(grafos, linhas);// se a solucao foi valida adiciono no meu grafo resposta;
            }
        } else {
            for (i = coluna; i < 8; i++) {
                troca(linhas, coluna, i);//chamo a funçao troca 
                testaPermutacoes(grafos, linhas, coluna + 1);//toda vez que volto na Testa Permutaçoes,realizo uma nova troca no vetor linhas
                //se a troca nao for uma solucao, realizo o backtracking retornando a troca que havia feito
                troca(linhas, i, coluna);
            }
        }
    }

    public boolean solucaoValida(int linhas[]) { // ultilizamos essa função para testar se a solucao é valida
        int i;
        int x, y;
        int diagX,diagY;

        for (i = 0; i < 8; i++) {
            x = i;
            y = linhas[i];
            diagX = x;
           diagY = y;
            while (true) {
                diagX += 1;
               diagY -= 1;
                if (diagX > 7 ||diagY < 0) {
                    break;
                }

                if (diagY == linhas[diagX]) { //para isso verificamos as diagonais  tanto na parte de cima a partir de onde esta a rainha
                    return false;//se a rainha estiver na diagonal de outra retornamos falso
                }
            }

            diagX = x;
           diagY = y;
            while (true) {
                diagX -= 1;
               diagY -= 1;
                if (diagX < 0 ||diagY < 0) {
                    break;
                }

                if (diagY == linhas[diagX]) { // quanto na parte de baixo para ter certeza que nehuma rainha esta na diagonal de outra
                    return false; //se a rainha estiver na diagonal de outra retornamos falso
                }
            }
        }
        return true; // se a rainha nao estiver em nenhuma diagonal de outra rainha retornamos verdadeiro
    }

    public void troca(int linhas[], int i, int j) { // Realiza trocas de duas posiçoes no vetor de linhas
        int tmp;
        tmp = linhas[i];
        linhas[i] = linhas[j];
        linhas[j] = tmp;
        // obs: essa funcao é necessaria pois como serao testadas as permutacoes, primeiro elas precisam ser geradas
    }

    public void addSolution(Grafo grafo, int linhas[]) { // adiciono a solucao no meu grafo resposta
        int i;
        int x, y;
        contaSolutions++;
        System.out.println("Solução " + contaSolutions + " :");

        for (i = 0; i < 8; i++) {
            x = i;// aqui sao as colunas do tabuleiro como nenhuma rainha pode estar na mesma coluna que outra uso um for para adiciona-las na coluna
            y = linhas[i];// verifico no meu vetor linhas em qual linha estao as rainhas e salvo as posiçoes
            grafo.grafoResposta[y][x] = "[R]";// depois passo pro meu grafo resposta a coluna em que a rainha deve estar na solucao e a linha
        }
        
            grafo.imprimeGrafo();
        

    }

}
