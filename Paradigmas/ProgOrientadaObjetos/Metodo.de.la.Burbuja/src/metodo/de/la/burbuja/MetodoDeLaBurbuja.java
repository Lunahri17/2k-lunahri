package metodo.de.la.burbuja;


public class MetodoDeLaBurbuja {

    static void ordenar(int[] vector){
        boolean ordenado;
        int aux;
        
        do{
            ordenado = true;
            for (int i = 0 ; i < vector.length-1 ; i++){
                if (vector[i] > vector[i+1]){
                    aux = vector[i+1];
                    vector[i+1] = vector[i];
                    vector[i] = aux;
                    ordenado = false;
                }
            }
        } while(!ordenado);
    }
    
    static void mostrar(int[] vector){
        System.out.print("Vector: ");
        for (int i = 0 ; i < vector.length ; i++){
            System.out.print(vector[i] + " ");
        }
    }
    
    public static void main(String[] args) {
        int []vector = {3,2,1,5,7,4,9,8};
        int []vector2 = {3,2,1,5,7,4,9,8};
              
        ordenar(vector);
        ordenar(vector2);
        mostrar(vector);
        mostrar(vector2);
    }
    
}
