import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
 

/*
 * Problema número 1380 do URI
 * Problema I do treino 1
 */

public class U1380 {

    public static final BigInteger ONE = new BigInteger("1");
    public static final BigInteger ZERO = new BigInteger("0");
 
    public static void main(String[] args) throws IOException {
    	BigInteger values[] = new BigInteger[1500];
    	int pd[] = new int [1501];
        values[0] = ZERO;
        values[1] = ONE;
        BigInteger mil = new BigInteger("1000");
 
        Scanner io = new Scanner(System.in);
        String n = io.next();
        BigInteger nth = new BigInteger(n);
        fib(values, 1499);
        for(int i = 0; i < 1500; i++) {
            values[i] = values[i].mod(mil);
            pd[i] = values[i].intValue(); 
        }
        for(BigInteger i = ZERO; !i.equals(nth) ; i = i.add(ONE)) {
        	BigInteger number;
        	String aux = io.next();
            char x[] = aux.toCharArray();
            int comp = aux.length();
            int soma = 0;
            for(int j = 0; j < comp; j++) {
                soma = (soma*10 + x[j] - '0')%1500;
            }
        	int a = pd[soma];
            
        	if(a < 10) {
        		System.out.println("00"+a);
        	} else if(a < 100) {
        		System.out.println("0"+a);
        	} else {
        		System.out.println(a);
        	}
        }
 
    }

    public static void fib(BigInteger c[], int n) {
        for(int i = 2; i <= n; i++) {
            c[i] = c[i-1].add(c[i-2]);
        }
    }

    private static int fib(int n) {
    	BigInteger a = new BigInteger("1");
    	BigInteger b = new BigInteger("0");
    	BigInteger p = new BigInteger("0");
    	BigInteger q = new BigInteger("1");
    	BigInteger dois = new BigInteger("2");
    	while (n > 0) {
    		if (n%2 == 0) {
    			BigInteger aux = p;
    			BigInteger aux2 = q;
    			
    			p = aux.pow(2); // p = p^2
    			p = p.add(aux2.pow(2)); // p = p^2 + q^2
    			q = dois.multiply(aux.multiply(aux2)); // q = 2*p*q
    			q = q.add(aux2.pow(2)); // q = 2*p*q + q^2;
    			n /= 2;
    		} else {
    			BigInteger aux = a;
    			BigInteger aux2 = b;
    			a = aux.multiply(q); // a = a*q
    			a = a.add(aux.multiply(p)); // a = a*q+a*p
    			a = a.add(aux2.multiply(q)); // a = a*q + a*p + b*q
    			b = aux2.multiply(p); // b = b*p
    			b = b.add(aux.multiply(q)); // b = b*p + a*q
    			n--;
    		}
    	}
    	b = b.mod(new BigInteger("1000"));
    	return b.intValue();
    	
    }
}
