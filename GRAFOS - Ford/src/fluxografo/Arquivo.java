package fluxografo;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Arquivo {
    public static int[] Read() {
         Scanner entrada = new Scanner(System.in);
        System.out.println("Informe o Nome do arquivo");
        String Caminho = entrada.nextLine();      
        int[] vetor = new int[2]; 
        ArrayList<Integer> v1 = new ArrayList<>();
        ArrayList<Integer> v2 = new ArrayList<>();
        ArrayList<Integer> peso = new ArrayList<>();
        int a = 0, b = 0, c = 0;
        try {
            FileReader arq = new FileReader(Caminho);
            BufferedReader lerArq = new BufferedReader(arq);
            String linha = "";
            try {
                linha = lerArq.readLine();
                while (linha != null) {
                    StringTokenizer token = new StringTokenizer(linha, " ");
                    a = Integer.parseInt(token.nextToken());
                    b = Integer.parseInt(token.nextToken());
                    c = Integer.parseInt(token.nextToken());
                    v1.add(a-1);
                    v2.add(b-1);
                    peso.add(c);
                    linha = lerArq.readLine();
                }
                int numVertices = TestaNumero.teste(v1, v2);             
                int numArestas = ContaLinhas.ContaLinha(Caminho);
                CriaGrafo Cg = new CriaGrafo();
                 Cg.criaGrafo(1, numVertices, numArestas, v1, v2, peso);
                vetor[0] = numVertices;
                vetor[1]= numArestas;     
                arq.close();
                return vetor;
            } catch (IOException ex) {
                System.out.println("Erro: Não foi possível ler o arquivo!");
                return null;
            }
        } catch (FileNotFoundException ex) {
            System.out.println("Erro: Arquivo não encontrado!");
            return null;
        }

    }

}
