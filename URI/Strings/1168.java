// Java programs must have class name "Main" in URI online judge

import java.io.IOException;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) throws IOException {
		int values[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int soma[] = new int[n];
		for(int i = 0; i < n; i++) {
			soma[i] = 0;
			String str = scn.next();
			for(int j = 0; j < str.length(); j++) {
				int aux = str.charAt(j)-48;
				soma[i] += values[aux];
			}
		}
		for(int i = 0; i < n; i++)
			System.out.println(soma[i]+" leds");
	}
}

		
	
