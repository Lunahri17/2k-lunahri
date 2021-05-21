package problema.de.las.pkg8.reinas;


public class ProblemaDeLas8Reinas {
    public static final String ANSI_YELLOW_BACKGROUND = "\u001B[43m";
    public static final String ANSI_RESET = "\u001B[0m";
    
    static void dibujar(int []tablero){
        for (int i = 0; i < 8 ; i++){
            for (int j = 0 ; j < 8 ; j++){
                if (tablero[i] == j){
                    if ((i+j)%2 == 0){
                        System.out.print(ANSI_YELLOW_BACKGROUND+"|R"+ANSI_RESET);
                    } else {
                        System.out.print("|R");
                    }
                } else {
                    if ((i+j)%2 == 0){
                        System.out.print(ANSI_YELLOW_BACKGROUND+"|_"+ANSI_RESET);
                    } else {
                        System.out.print("|_");
                    }
                }
            }
            System.out.println();
        }
        System.out.println();
    }
    
    static boolean ataque(int[] tablero){
        boolean res = false;
            
        for (int i=0 ; i<7 ; i++){
            for (int j=i+1 ; j<8 ; j++){
                if (tablero[i]==tablero[j]){
                    
                }
            }
        }
        
        return res;
    }
    
    public static void main(String[] args) {
        int[] tablero = { 0, 1, 2, 3, 4, 5, 6, 7};
        dibujar(tablero);
        int[] tablero2 = { 0, 0, 0, 0, 0, 0, 0, 0};
        dibujar(tablero2);
    }
    
}
