package fluxografo;

import java.util.ArrayList;

public class TestaNumero {

    public static int teste(ArrayList<Integer> lista1, ArrayList<Integer> lista2) {
        int maiorv1 = lista1.get(0);
        int menorv1 = lista1.get(0);
        int maiorv2 = lista2.get(0);
        int menorv2 = lista2.get(0);
        int maior;
        int menor;
        int diferenca;
        for (int i = 0; i < lista1.size(); i++) {
            if (lista1.get(i) >= maiorv1) {
                maiorv1 = lista1.get(i);
            } else if (lista1.get(i) <= menorv1) {
                menorv1 = lista1.get(i);
            }
        }

        for (int i = 0; i < lista2.size(); i++) {
            if (lista2.get(i) >= maiorv2) {
                maiorv2 = lista2.get(i);
            } else if (lista2.get(i) <= menorv2) {
                menorv2 = lista2.get(i);
            }
        }
        if(maiorv1>= maiorv2){
        maior = maiorv1;
        }else{
        maior = maiorv2;
        }
        if(menorv1<= menorv2){
            menor = menorv1;
        }else{
        menor = menorv2;
        }
        diferenca = (maior+1)-menor;
        return diferenca;
    }
}
