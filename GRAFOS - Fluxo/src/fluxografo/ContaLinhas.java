package fluxografo;

import java.io.BufferedReader;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class ContaLinhas {

    public static int ContaLinha(String Caminho) {
        int cont = 0;

        try {
            FileReader arq = new FileReader(Caminho);
            BufferedReader lerArq = new BufferedReader(arq);
            String linha = "";
            try {
                linha = lerArq.readLine();
                while (linha != null) {
                    linha = lerArq.readLine();
                    cont++;
                }
                arq.close();
                return cont;
            } catch (IOException ex) {
                System.out.println("Erro: Não foi possível ler o arquivo!");
                return 0;
            }
        } catch (FileNotFoundException ex) {
            System.out.println("Erro: Arquivo não encontrado!");
            return 0;
        }

    }
}
