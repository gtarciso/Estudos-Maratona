import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
 

/*
 * Problema número 1380 do URI - não aceito (time limit exceeded)
 * Problema I do treino 1
 */

public class Main {
 
    public static void main(String[] args) throws IOException {
    	int values[] = new int[1500];
    	int pd[] = new int [1500];
 
        Scanner io = new Scanner(System.in);
        int n = io.nextInt();
        for(int i = 0; i < n; i++) {
        	BigInteger number;
        	String aux = io.next();
        	number = new BigInteger(aux);
        	number = number.mod(new BigInteger("1500"));
        	int x = number.intValue();
        	int a;
        	if(pd[x] == 1) {
        		a = values[x];
        	} else {
        		pd[x] = 1;
        		a = fib(x)%1000;
        		values[x] = a;
        	}
        	if(x < 10) {
        		System.out.println("00"+a);
        	} else if(x < 100) {
        		System.out.println("0"+a);
        	} else {
        		System.out.println(a);
        	}
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