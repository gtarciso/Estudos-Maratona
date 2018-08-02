import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
 
/*
 * Problema 1084 URI
 */
public class Main {
 
    public static void main(String[] args) throws IOException {
 
        Scanner io = new Scanner(System.in);
        while(true) {
        	int n = io.nextInt();
        	int d = io.nextInt();
        	if(n == 0 && d == 0) break;

        	String number = io.next();
        	char aux[] = number.toCharArray();
        	char valor[] = new char[n-d];
        	int max = 0;
        	for(int i = n-d-1; i >= 0; i--) {
        		for(int j = max; j < n-i; j++) {
        			if(aux[j] > aux[max] && aux[j] != '-') {
        				max = j;
        			}
        		}
        		valor[i] = aux[max];
        		aux[max] = '-';
        	}
        	for(int i = 0, j = n-d-1; i < (n-d)/2; i++, j--) {
        		char a = valor[i];
        		valor[i] = valor[j];
        		valor[j] = a;
        	}

        	System.out.println(valor);
        }
 
    }
 
}